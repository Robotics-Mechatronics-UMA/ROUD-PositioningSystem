import pyproj
import rospy
from std_msgs.msg import String
import ast
import math

class EstimationsToROStopics:
    def __init__(self):
        # Initialize the ROS node
        rospy.init_node('geo_multilateration_node', anonymous=True)

        # Subscriber to receive data from 'infoServer'
        self.caller = rospy.Subscriber('infoServer', String, self.callToServer)

        # Publisher to send processed estimations
        self.pub4 = rospy.Publisher('geo_multilateration', String, latch=True, queue_size=1)

    def callToServer(self, msg):
        rospy.loginfo(f"Received message on 'infoServer': {msg.data}")
        try:
            # Convert the received message to a dictionary
            self.info = ast.literal_eval(msg.data)
            rospy.loginfo(f"Decoded info: {self.info}")

            # Validate and extract 'user_position'
            user_position = self.info.get('user_position', None)
            id_mobile = self.info.get('id_mobile', "Unknown")  # Mobile ID
            rospy.loginfo(f"'user_position': {user_position}, 'id_mobile': {id_mobile}")

            if user_position and isinstance(user_position, list) and len(user_position) >= 2:
                lat, lon = user_position[0], user_position[1]  # Latitude and longitude in the correct order
                alt = user_position[2] if len(user_position) > 2 else 0.0  # Default altitude if not provided
                rospy.loginfo(f"Extracted Latitude: {lat}, Longitude: {lon}, Altitude: {alt}")
            else:
                # Default values in case of error
                lat = float('nan')
                lon = float('nan')
                alt = float('nan')
                rospy.logwarn("Invalid or missing 'user_position'. Using default values (NaN, NaN, NaN).")

            # Validate and publish if the coordinates are valid
            if not (math.isnan(lat) or math.isnan(lon)):
                # Construct the message to publish in the expected format
                msg4 = f"{lat},{lon},{alt},{id_mobile}"
                rospy.loginfo(f"Publishing to 'geo_multilateration': {msg4}")
                self.pub4.publish(msg4)
            else:
                rospy.logwarn("Invalid coordinates. Not publishing to 'geo_multilateration'.")

        except Exception as e:
            # Handle errors with detailed logging
            rospy.logerr(f"Error processing message: {e}")

    def run(self):
        rospy.loginfo("Node 'geo_multilateration_node' is running. Sending distance estimations to ROS topics...")
        rospy.spin()

if __name__ == '__main__':
    try:
        node = EstimationsToROStopics()
        node.run()
    except rospy.ROSInterruptException:
        rospy.loginfo("Node terminated.")

