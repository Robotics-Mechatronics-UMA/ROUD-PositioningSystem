import rospy
import re
import numpy as np
from numpy.linalg import norm, inv
import pyproj

# Define WGS84 and ECEF coordinate systems
wgs84 = pyproj.CRS('EPSG:4326')
ecef = pyproj.CRS('EPSG:4978')
ecef_transformer = pyproj.Transformer.from_crs(wgs84, ecef)
gps_transformer = pyproj.Transformer.from_crs(ecef, wgs84)

def gps2ecef(lon, lat, alt):
    """Transform GPS coordinates to ECEF."""
    return ecef_transformer.transform(lat, lon, alt)  # Correct order for pyproj

def ecef2gps(x, y, z):
    """Transform ECEF coordinates to GPS."""
    return gps_transformer.transform(x, y, z)  # Returns lat, lon, alt

def compute_range(pos, BS_pos):
    """Compute distances between a position and base stations."""
    return norm(np.asarray(pos) - BS_pos, axis=1)

def hx_ils(pos, BS_pos, range_est):
    """Compute Jacobian matrix for ILS."""
    H = np.zeros((len(BS_pos), len(pos)))
    for j in range(len(BS_pos)):
        H[j, :] = (pos - BS_pos[j]) / range_est[j]
    return H



def lop_ils(distances, BS_pos, pos_est, mode="OLS", eps=1.e-1, max_iter=40):
    """Perform Iterative Least Squares (ILS) with different estimation methods."""
    pos = np.array(pos_est)
    W = np.eye(len(BS_pos))  # Initial weight matrix
    converged = False
    c = 0.7317  # Constant for Huber and Tukey methods

    for iteration in range(max_iter):
        r_est = compute_range(pos, BS_pos)
        H = hx_ils(pos, BS_pos, r_est)

        try:
            H_inv = inv(H.T @ W @ H) @ H.T @ W
        except np.linalg.LinAlgError:
            rospy.logerr("Jacobian matrix is singular. Cannot invert.")
            return pos, False, W

        # Residuals (difference between measured and estimated distances)
        y = distances - r_est

        # Update weight matrix based on the selected mode
        W_ = []
        if mode == 'OLS':
            W_ = np.ones(len(y))  # Ordinary Least Squares: all weights = 1
        elif mode == 'LAD':
            W_ = 1 / np.abs(y)  # Least Absolute Deviations: inverse of residuals
        elif mode == 'Huber':
            for obs in y:
                if abs(obs) <= c:
                    W_.append(1)
                else:
                    W_.append(c / abs(obs))
        elif mode == 'Trimmed':
            for obs in y:
                if abs(obs) <= c:
                    W_.append(1)
                else:
                    W_.append(1e-3)  # Assign very low weight to outliers
        elif mode == 'Tukey':
            for obs in y:
                if abs(obs) <= c:
                    W_.append((1 - (obs / c)**2)**2)
                else:
                    W_.append(1e-3)  # Assign very low weight to outliers
        else:
            rospy.logwarn(f"Unknown mode: {mode}. Defaulting to OLS.")
            W_ = np.ones(len(y))

        # Update weight matrix
        W = np.diag(W_)

        # Update position estimate
        Hy = H_inv @ y
        pos += Hy

        #rospy.loginfo(f"Iteration {iteration + 1}: delta_pos={Hy}, pos={pos}")

        # Check for convergence
        if np.max(np.abs(Hy)) < eps:
            converged = True
            #rospy.loginfo("ILS converged.")
            break

    if not converged:
        rospy.logwarn("ILS did not converge.")
    return pos, converged, W


def ils(BS, distances, dimension=2, mode="OLS"):
    """ILS wrapper for 2D or 3D positioning."""
    BS = np.asarray(BS, dtype=float)
    distances = np.asarray(distances, dtype=float)

    if dimension == 2:
        BS_2D = BS[:, :2]
        avg_altitude = np.mean(BS[:, 2])  # Promedio de altitudes
        initial_position = np.append(BS_2D[np.argmin(distances)], avg_altitude + 1)
    else:
        initial_position = BS[np.argmin(distances)] + 1

    return lop_ils(distances, BS, initial_position, mode)

def parse_rtt(rtt, bsWifiFtm=None, WiFi_excluded=None):
    if WiFi_excluded is None:
        WiFi_excluded = []

    if not isinstance(rtt, (str, list)):
        rospy.logerr(f"Unsupported RttInfo type: {type(rtt)}. Expected string or list.")
        return [], [], [], []

    devices, positions, distances, anchor_positions = [], [], [], []

    try:
        if isinstance(rtt, str):
            #rospy.loginfo(f"Parsing RttInfo string: {rtt}")
            results = re.findall(
                r"mac=([\w:]+).*?distanceMm=(-?\d+).*?distanceStdDevMm=(\d+).*?rssi=(-?\d+)",
                rtt,
                re.DOTALL
            )
        elif isinstance(rtt, list):
            #rospy.loginfo("Parsing RttInfo list.")
            results = [
                (entry.get("mac"), entry.get("distance", 0), entry.get("stdDev", 0), entry.get("rssi", 0))
                for entry in rtt
            ]

        for mac, distance_mm, _, _ in results:
            distance = max(int(distance_mm), 0) / 1000.0  # Convert mm to meters
            if distance == 0.0:
                rospy.logwarn(f"Replacing distance 0.0 with 0.2 for device {mac}")
                distance = 0.2

            if bsWifiFtm and mac in bsWifiFtm:
                lat, lon, alt = (
                    bsWifiFtm[mac].get("Y"),  # Correct: Latitude (Y)
                    bsWifiFtm[mac].get("X"),  # Correct: Longitude (X)
                    bsWifiFtm[mac].get("Z"),  # Altitude
                )

                if lat is None or lon is None or alt is None:
                    rospy.logwarn(f"Anchor {mac} has incomplete coordinates. Skipping.")
                    continue

                # Convert to ECEF
                x, y, z = gps2ecef(lon, lat, alt)
                #rospy.loginfo(f"Converted ECEF: X={x}, Y={y}, Z={z} for Anchor MAC={mac}")

                # Register the anchor
                #rospy.loginfo(f"Anchor MAC: {mac}, Lat: {lat}, Lon: {lon}, Alt: {alt}")

                positions.append([x, y, z])
                distances.append(distance)
                devices.append(mac)
                anchor_positions.append({"mac": mac, "lat": lat, "lon": lon, "alt": alt})

    except Exception as e:
        rospy.logerr(f"Error parsing RTT data: {e}")

    return devices, positions, distances, anchor_positions

def compute_position(Mode, RttInfo, id_mobile=None, Timestamp=None, groundTruth=None, dimension=2, bsPositions=None):
    #rospy.loginfo(f"Starting position computation with Mode: {Mode}, ID: {id_mobile}")

    if not bsPositions:
        rospy.logerr("No anchor positions provided.")
        return {"error": "No anchor positions"}

    #rospy.loginfo(f"Raw RttInfo: {RttInfo}")
    devices, positions_wifi, distances_wifi, anchor_positions = parse_rtt(RttInfo, bsWifiFtm=bsPositions)

    # Detailed logging of anchors
    """
    for anchor in anchor_positions:
        rospy.loginfo(
            f"Anchor MAC: {anchor['mac']}, Lat: {anchor['lat']}, Lon: {anchor['lon']}, Alt: {anchor['alt']}"
        )
    """
    if len(positions_wifi) < 3:
        rospy.logerr("Not enough anchors.")
        return {"error": "Not enough anchors"}

    user_position, converged, _ = ils(positions_wifi, distances_wifi, dimension, Mode)

    if converged:
        if dimension == 2:
            lat, lon, _ = ecef2gps(user_position[0], user_position[1], np.mean(positions_wifi, axis=0)[2])
            user_position = [lat, lon]
        else:
            lat, lon, alt = ecef2gps(user_position[0], user_position[1], user_position[2])
            user_position = [lat, lon, alt]

        #rospy.loginfo(f"Computed position: {user_position}")
        return {
            "user_position": user_position,
            "num_anchors_used": len(positions_wifi),
            "id_mobile": id_mobile,
            "timestamp": Timestamp,
            "ground_truth": groundTruth,
            "anchor_positions": anchor_positions,
        }

    return 0
    #return {"error": "ILS did not converge"}
