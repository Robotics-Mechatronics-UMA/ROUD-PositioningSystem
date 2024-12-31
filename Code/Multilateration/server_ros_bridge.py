import json
import re
import requests
from flask import Flask, request, jsonify
import rospy
from std_msgs.msg import String
from positioning_rtt_ils import compute_position
from anchors_positions import Robots_rt_geolocation  # Import the correct class
import os

Mode = os.getenv('MODE', 'OLS')

print(f"Using mode: {Mode}")

class ServerToROS:
    def __init__(self, geolocation_instance):
        # Initialize Flask
        self.app = Flask(__name__)
        self.app.route('/mobile', methods=['POST'])(self.add_mobile)
        self.app.route('/inputServer', methods=['POST'])(self.input_server)

        # Single instance of Robots_rt_geolocation to retrieve anchor positions
        self.geolocation_instance = geolocation_instance

        # Initialize ROS
        self.pub = rospy.Publisher('/infoServer', String, latch=True, queue_size=1)
        self.sub = rospy.Subscriber('/inputServer', String, self.process_input_server)

    def input_server(self):
        try:
            # Receive JSON data from the inputServer endpoint
            data = request.json
            #rospy.loginfo(f"Received data from /inputServer: {data}")

            # Publish data to ROS topic
            self.pub.publish(str(data))
            #rospy.loginfo(f"Published to /infoServer: {data}")
            return jsonify({"message": "Data published successfully"})
        except Exception as e:
            rospy.logerr(f"Error in /inputServer: {e}")
            return jsonify({"error": str(e)}), 500

    def process_input_server(self, msg):
        try:
            # Process incoming ROS message from /inputServer
            #rospy.loginfo(f"Received raw data: {msg.data}")
            clean_data = re.sub(r"'", '"', msg.data)
            data = json.loads(clean_data)

            # Forward the processed data to the /mobile endpoint
            response = requests.post("http://localhost:5001/mobile", json=data)
            #if response.status_code == 200:
                #rospy.loginfo(f"Processed data: {response.json()}")
        except Exception as e:
            rospy.logerr(f"Error processing /inputServer data: {e}")

    def add_mobile(self):
        try:
            # Process the /mobile request
            #rospy.loginfo("Processing /mobile request")
            bs_wifi_ftm = self.geolocation_instance.get_updated_bsWifiFtm()

            #rospy.loginfo(f"Anchor positions (raw): {bs_wifi_ftm}")

            # Format anchor positions for use in multilateration
            bs_wifi_ftm_formatted = {
                mac: {"lat": bs["Y"], "lon": bs["X"], "alt": bs["Z"]}
                for mac, bs in bs_wifi_ftm.items()
                if all(key in bs and bs[key] is not None for key in ["X", "Y", "Z"])
            }

            #rospy.loginfo(f"Anchor positions (formatted): {bs_wifi_ftm_formatted}")

            # Extract RTT info from the request JSON
            rtt_info_raw = request.json.get("RttInfo", None)

            if not rtt_info_raw:
                rospy.logerr("No RTT data received.")
                return jsonify({"error": "No RTT data"}), 400

            # Check if RttInfo is valid
            if isinstance(rtt_info_raw, dict) and "RttInfo" in rtt_info_raw:
                rtt_info_string = rtt_info_raw["RttInfo"]
            elif isinstance(rtt_info_raw, str):
                rtt_info_string = rtt_info_raw
            else:
                rospy.logerr(f"Invalid RttInfo type: {type(rtt_info_raw)}")
                return jsonify({"error": "Invalid RttInfo format"}), 400

            # Parse the RttInfo string
            rtt_info_list = self.parse_rtt_string(rtt_info_string)

            if not rtt_info_list:
                rospy.logerr("No valid RTT data parsed.")
                return jsonify({"error": "No valid RTT data"}), 400

            # Format valid RTT data
            formatted_rtt_info = [
                {
                    "mac": rtt["mac"],
                    "distance": rtt["distanceMm"],
                    "stdDev": rtt["distanceStdDevMm"],
                    "rssi": rtt["rssi"]
                }
                for rtt in rtt_info_list
            ]

            # Call compute_position function
            position_data = compute_position(
                Mode,
                RttInfo=formatted_rtt_info,
                id_mobile=request.json.get("id_mobile", None),
                Timestamp=request.json.get("Timestamp", None),
                groundTruth=request.json.get("groundTruth", None),
                bsPositions=bs_wifi_ftm
            )

            # Publish position data to ROS
            msg = String(data=str(position_data))
            self.pub.publish(msg)
            return jsonify({"data": position_data})
        except Exception as e:
            rospy.logerr(f"Unexpected error in add_mobile: {e}")
            return jsonify({"error": f"Unexpected error: {e}"}), 500

    def parse_rtt_string(self, rtt_info_string):
        """Parse the RttInfo string into a list of dictionaries."""
        rtt_info_list = []
        try:
            if not isinstance(rtt_info_string, str):
                rospy.logerr(f"RttInfo is not a string: {type(rtt_info_string)}")
                return rtt_info_list

            # Clean irrelevant fields from the RttInfo string
            clean_rtt_info = re.sub(r"lci=\[.*?\]|lcr=\[.*?\]|peerHandle=<null>|responderLocation=.*?,", "", rtt_info_string)

            # Extract relevant fields
            ranging_results = re.findall(
                r"mac=([\w:]+).*?distanceMm=(-?\d+).*?distanceStdDevMm=(\d+).*?rssi=(-?\d+)",
                clean_rtt_info,
                re.DOTALL
            )

            for mac, distance_mm, distance_std_dev, rssi in ranging_results:
                rtt_info_list.append({
                    "mac": mac,
                    "distanceMm": max(int(distance_mm), 0),
                    "distanceStdDevMm": int(distance_std_dev),
                    "rssi": int(rssi)
                })

            if not rtt_info_list:
                rospy.logwarn("No valid RTT data extracted after cleaning.")
        except Exception as e:
            rospy.logerr(f"Error parsing RttInfo string: {e}")
        return rtt_info_list

    def run(self):
        # Run Flask server in a separate thread and start ROS spin
        from threading import Thread
        flask_thread = Thread(target=self.app.run, kwargs={'host': 'localhost', 'port': 5001})
        flask_thread.start()
        rospy.spin()

if __name__ == '__main__':
    try:
        rospy.init_node('ftmAnchors', anonymous=True)
        geolocation_instance = Robots_rt_geolocation()
        server = ServerToROS(geolocation_instance)
        server.run()
    except rospy.ROSInterruptException:
        pass