import pyproj
import rospy
from sensor_msgs.msg import NavSatFix

# Define WGS84 and ECEF coordinate systems
wgs84 = pyproj.CRS('EPSG:4326')
ecef = pyproj.CRS('EPSG:4978')

class Robots_rt_geolocation:
    def __init__(self):
        # Initialize MAC address
        self.mac = ""

        # Define initial positions for WiFi FTM anchors
        self.bsWifiFtm = {
            "9c:4f:5f:0f:de:aa": {"X": -4.4900179, "Y": 36.7155386, "Z": 48.56},  # Static anchor
            "3c:28:6d:b2:e2:0b": {"X": -4.4902625, "Y": 36.715327, "Z": -100.0},  # UAV
            "3c:28:6d:b2:c9:1f": {"X": -4.4902751, "Y": 36.7154688, "Z": 48.63},  # Static anchor
            "08:b4:b1:70:4b:65": {"X": -4.4902973, "Y": 36.7151904, "Z": -103.24}  # UGV
        }

        #rospy.loginfo(f"Initial positions: {self.bsWifiFtm}")

        # Subscribe to GPS topics for specific anchors
        self.sub3 = rospy.Subscriber('gps0/J8/fix', NavSatFix, self.callback_anchor_65)
        self.sub4 = rospy.Subscriber('/FV8/mavros/gps1/navsatfix/raw', NavSatFix, self.callback_anchor_0b)

    def get_updated_bsWifiFtm(self):
        """Returns the updated bsWifiFtm dictionary with anchor positions."""
        return self.bsWifiFtm

    def callback_anchor_0b(self, data):
        """Callback to update the UAV's GPS position."""
        try:
            if hasattr(data, 'longitude') and hasattr(data, 'latitude') and hasattr(data, 'altitude'):
                self.bsWifiFtm["3c:28:6d:b2:e2:0b"].update({
                    "X": data.longitude,
                    "Y": data.latitude,
                    "Z": data.altitude
                })
        except AttributeError as e:
            rospy.logwarn(f"Error processing UAV GPS data: {e}")

    def callback_anchor_65(self, data):
        """Callback to update the UGV's GPS position."""
        try:
            if hasattr(data, 'longitude') and hasattr(data, 'latitude') and hasattr(data, 'altitude'):
                self.bsWifiFtm["08:b4:b1:70:4b:65"].update({
                    "X": data.longitude,
                    "Y": data.latitude,
                    "Z": data.altitude
                })
        except AttributeError as e:
            rospy.logwarn(f"Error processing UGV GPS data: {e}")


if __name__ == '__main__':
    try:
        # Initialize ROS node
        rospy.init_node('ftmAnchors', anonymous=True)
        node_name = rospy.get_name()
        #rospy.loginfo(f"Starting ROS node: {node_name}")

        # Create a single instance of Robots_rt_geolocation
        geolocation_instance = Robots_rt_geolocation()

        # Anchor positions
        #rospy.loginfo("Testing initial anchor positions...")
        anchor_positions = geolocation_instance.get_updated_bsWifiFtm()
        #rospy.loginfo(f"Initial anchor positions: {anchor_positions}")

        # Run the main node
        geolocation_instance.run()
    except rospy.ROSInterruptException:
        rospy.loginfo("ROS node stopped.")

