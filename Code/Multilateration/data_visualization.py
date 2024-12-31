import matplotlib as mpl
import matplotlib.pyplot as plt
from geopy.distance import geodesic
import rosbag
from std_msgs.msg import String
import time
import numpy as np
import sys
import os


output_dir = "/root/Figures"
os.makedirs(output_dir, exist_ok=True) 


P0 = -45  # RSSI value for 1 meter
n = 2.0   # fitting coefficient related to the path attenuation, which is obtained from tuning the logarithmic function to the data. 
d0 = 1.0  # Reference distance in meters

# Victim static positions (latitude, longitude, altitude)
P1_coords = (36.71541060, -4.49009390,  48.31)
X3_coords = (36.71538600, -4.49011380,  49.58)

# Distance estimation through RSSI
def estimate_distance(rssi, P0, n, d0=1.0):
    return d0 * 10 ** ((P0 - rssi) / (10 * n))

def euclidean_distance_3d(coord1, coord2, flag_evaluation):   
    test = flag_evaluation
    horizontal_distance = geodesic((coord1[0], coord1[1]), (coord2[0], coord2[1])).meters
    if test:
        alt_diff = abs(coord1[2] - 48.31)
    else:
        alt_diff = abs(coord1[2] - coord2[2])
    return np.sqrt(horizontal_distance**2 + alt_diff**2)

def filter_and_synchronize_data(times, data, real_position):
    filtered_times = []
    filtered_distances = []

    for time, gps in zip(times, data):
        distance = euclidean_distance_3d(gps, real_position, False)
        filtered_times.append(time)
        filtered_distances.append(distance)

    return filtered_times, filtered_distances

def synchronize_data(gps_times, gps_data, event_times, event_data):
    synchronized_data = []
    for event_time in event_times:
        closest_time = min(gps_times, key=lambda t: abs(t - event_time))
        index = gps_times.index(closest_time)
        synchronized_data.append((gps_data[index], event_data[event_times.index(event_time)]))
    return synchronized_data

# Read the ROS 1 bag.
def read_ros1_bag(bag_path, bag_start_time, start_interval, end_interval, altitude_threshold, P0, n, d0):
    
    gps_data_j8, gps_times_j8 = [], []
    gps_data_uav, gps_times_uav = [], []

    
    rssi_data_P1_j8, rssi_times_P1_j8, rssi_data_X3_j8, rssi_times_X3_j8 = [], [], [], []     
    rssi_data_P1_uav, rssi_times_P1_uav, rssi_data_X3_uav, rssi_times_X3_uav = [], [], [], []
    
    multilateration_distances_P1_j8, multilateration_times_P1_j8, multilateration_distances_X3_j8, multilateration_times_X3_j8 = [], [], [], []
    multilateration_distances_P1_uav, multilateration_times_P1_uav, multilateration_distances_X3_uav, multilateration_times_X3_uav = [], [], [], []
    
    rtt_distances_P1_uav, rtt_distances_times_P1_uav, rtt_distances_X3_uav, rtt_distances_times_X3_uav = [], [], [], []
    
    rtt_distances_P1_j8, rtt_distances_times_P1_j8, rtt_distances_X3_j8, rtt_distances_times_X3_j8 = [], [], [], []
    X3_coord_estimated, P1_coord_estimated = [], []
    
    rssi_values_X3_j8, rssi_values_P1_j8 = [], []
    rssi_values_X3_uav, rssi_values_P1_uav = [], []

    # Anchor 1F: 
    rtt_distances_P1_1F   = []   
    rtt_distances_X3_1F = []
    rtt_distances_times_X3_1F = []
    rtt_distances_times_P1_1F  = []

    # Anchor AA: 
    rtt_distances_P1_AA = [] 
    rtt_distances_times_P1_AA = [] 
    rtt_distances_X3_AA = [] 
    rtt_distances_times_X3_AA = [] 

    with rosbag.Bag(bag_path, 'r') as bag:
        
        bag_start_time = bag.get_start_time()
        
        for topic, msg, t in bag.read_messages():
            time_relative = (t.to_sec()) - bag_start_time  
            if time_relative < start_interval or time_relative > end_interval:
                continue

            # GNSS values for the UGV
            if topic == '/gps0/J8/fix':
                tipo_detectado = str(type(msg))
                
                if str(type(msg)) == tipo_detectado:
                    altitude = msg.altitude  
                    gps_data_j8.append((msg.latitude, msg.longitude, msg.altitude))
                    gps_times_j8.append(time_relative)
                    
            if gps_data_j8 and gps_data_j8[-1][2] < altitude_threshold:
                continue


            elif topic == '/RoverJ8/wifi_rtt_estimation':
                tipo_detectado = str(type(msg))
                if str(type(msg)) == tipo_detectado:
                    parts = msg.data.split(',')
                    label = parts[3]
                    estimated_distance = float(parts[0])
                    rssi = int(parts[2])

                    if label == 'P1':
                        rtt_distances_P1_j8.append(estimated_distance)
                        rtt_distances_times_P1_j8.append(time_relative)
                        
                        rssi_values_P1_j8.append(rssi)
                        estimated_distance = estimate_distance(rssi, P0, n, d0)   
                        rssi_data_P1_j8.append(estimated_distance)  
                        rssi_times_P1_j8.append(time_relative)                    

                    elif label == 'X3':
                        rtt_distances_X3_j8.append(estimated_distance)
                        rtt_distances_times_X3_j8.append(time_relative)
                        rssi_values_X3_j8.append(rssi)
                        estimated_distance = estimate_distance(rssi, P0, n, d0)
                        rssi_data_X3_j8.append(estimated_distance)
                        rssi_times_X3_j8.append(time_relative)

            # GNSS values for the UAV
            if topic == '/FV8/mavros/gps1/navsatfix/raw':
                tipo_detectado = str(type(msg))
            
                if str(type(msg)) == tipo_detectado:
                    gps_data_uav.append((msg.latitude, msg.longitude, msg.altitude))
                    gps_times_uav.append(time_relative)

                if float(msg.altitude) < altitude_threshold:
                        print("Altitud del UAV: ", msg.altitude)
                        continue

    
            elif topic == '/FV8/wifi_rtt_estimation':
                tipo_detectado = str(type(msg))

                if str(type(msg)) == tipo_detectado:
                    parts = msg.data.split(',')
                    label = parts[3]
                    estimated_distance = float(parts[0])
                    rssi = int(parts[2])

                    if label == 'P1':
                        rtt_distances_P1_uav.append(estimated_distance)
                        rtt_distances_times_P1_uav.append(time_relative)
                        rssi_values_P1_uav.append(rssi)

                        estimated_distance = estimate_distance(rssi, P0, n, d0)
                        rssi_data_P1_uav.append(estimated_distance)
                        rssi_times_P1_uav.append(time_relative)                    

                    elif label == 'X3':
                        rtt_distances_X3_uav.append(estimated_distance)
                        rtt_distances_times_X3_uav.append(time_relative)
                        rssi_values_X3_uav.append(rssi)
                        estimated_distance = estimate_distance(rssi, P0, n, d0)
                        rssi_data_X3_uav.append(estimated_distance)
                        rssi_times_X3_uav.append(time_relative)

            elif topic == '/Anchor1F/wifi_rtt_estimation':
                tipo_detectado = str(type(msg))
                
                if str(type(msg)) == tipo_detectado:
                    parts = msg.data.split(',')
                    label = parts[3]
                    estimated_distance = float(parts[0])
                    rssi = int(parts[2])

                    if label == 'P1':
                        rtt_distances_P1_1F.append(estimated_distance)
                        rtt_distances_times_P1_1F.append(time_relative)
        
                    elif label == 'X3':
                        rtt_distances_X3_1F.append(estimated_distance)
                        rtt_distances_times_X3_1F.append(time_relative)
                
            elif topic == '/AnchorAA/wifi_rtt_estimation':
                tipo_detectado = str(type(msg))
               
                if str(type(msg)) == tipo_detectado:
                    parts = msg.data.split(',')
                    label = parts[3]
                    estimated_distance = float(parts[0])
                    rssi = int(parts[2])

                    if label == 'P1':
                        rtt_distances_P1_AA.append(estimated_distance)
                        rtt_distances_times_P1_AA.append(time_relative)
        
                    elif label == 'X3':
                        rtt_distances_X3_AA.append(estimated_distance)
                        rtt_distances_times_X3_AA.append(time_relative)

            elif topic == '/geo_multilateration':

                tipo_detectado = str(type(msg))

                if str(type(msg)) == tipo_detectado:
                    parts = msg.data.split(',')

                    lat = float(parts[0])   
                    lon = float(parts[1])
                    alt = 48.31  # forced projection
                    label = parts[3]

                    if label == 'P1':
                        P1_coord_estimated.append((lat, lon, 48.31))
                    elif label == 'X3':
                        X3_coord_estimated.append((lat, lon, 48.31))

                    if gps_data_uav:
                        
                        # UAV position when the current value was detected by multilateration
                        uav_position = gps_data_uav[-1]  # GPS en este instante
                        estimated_distance_fromUAV = euclidean_distance_3d(uav_position, (lat, lon, alt), True)  
                        
                        if label == 'P1':     
                            multilateration_distances_P1_uav.append(estimated_distance_fromUAV)
                            multilateration_times_P1_uav.append(time_relative)
                            
                             
                        elif label == 'X3':
                            multilateration_distances_X3_uav.append(estimated_distance)
                            multilateration_times_X3_uav.append(time_relative)

                    if gps_data_j8:

                        # UGV position when the current value was detected by multilateration
                        j8_position = gps_data_j8[-1] 
                        estimated_distance_fromUAV = euclidean_distance_3d(j8_position, (lat, lon, alt), True)  
                        
                        if label == 'P1':     
                            multilateration_distances_P1_j8.append(estimated_distance_fromUAV)
                            multilateration_times_P1_j8.append(time_relative)
                             
                        elif label == 'X3':
                            multilateration_distances_X3_j8.append(estimated_distance)
                            multilateration_times_X3_j8.append(time_relative)

    return (gps_data_j8, gps_times_j8, gps_data_uav, gps_times_uav, rssi_data_P1_uav, rssi_times_P1_uav, rssi_data_X3_uav, rssi_times_X3_uav,
            multilateration_distances_P1_uav, multilateration_times_P1_uav, multilateration_distances_X3_uav, multilateration_times_X3_uav,
            rtt_distances_P1_uav, rtt_distances_times_P1_uav, rtt_distances_X3_uav, rtt_distances_times_X3_uav, rssi_data_P1_j8, rssi_times_P1_j8, rssi_data_X3_j8, rssi_times_X3_j8,
            multilateration_distances_P1_j8, multilateration_times_P1_j8, multilateration_distances_X3_j8, multilateration_times_X3_j8, multilateration_distances_P1_uav, multilateration_times_P1_uav, multilateration_distances_X3_uav, multilateration_times_X3_uav,
            rtt_distances_P1_j8, rtt_distances_times_P1_j8, rtt_distances_X3_j8, rtt_distances_times_X3_j8,  X3_coord_estimated, P1_coord_estimated, rssi_values_P1_j8, rssi_values_X3_j8, rssi_values_P1_uav, rssi_values_X3_uav, rtt_distances_P1_1F, rtt_distances_X3_1F, rtt_distances_X3_AA, rtt_distances_P1_AA)

def calculate_error(estimated_distances, real_distances):
    errors = []
    for estimated, real in zip(estimated_distances, real_distances):

        if isinstance(real, tuple):
            real_value = real[2]
        else:
            real_value = real
        errors.append(abs(estimated - real_value))

    return errors

def plot_multilateration_rtt_error(multilateration_distances_P1, multilateration_times_P1, multilateration_distances_X3, multilateration_times_X3,
                                   rtt_distances_P1, rtt_distances_times_P1, rtt_distances_X3, rtt_distances_times_X3,
                                   gps_times, gps_distances_P1, gps_distances_X3, gps_data, P1_coord_estimated, X3_coord_estimated):

    P1_realPosition = (36.71678533, -4.48830800, 48.31)
    X3_realPosition = (36.71680367, -4.48832033, 48.31)

    gps_distances_P1_rtt = [euclidean_distance_3d(gpsToP1_rtt, P1_realPosition, False) for gpsToP1_rtt in gps_data] 
    gps_distances_X3_rtt = [euclidean_distance_3d(gpsToX3_rtt, X3_realPosition, False) for gpsToX3_rtt in gps_data]  

    gps_distances_P1_multilat = [euclidean_distance_3d(gpsToP1_multilat, P1_realPosition, False) for gpsToP1_multilat in gps_data]  
    gps_distances_X3_multilat = [euclidean_distance_3d(gpsToX3_multilat, X3_realPosition, False) for gpsToX3_multilat in gps_data]  

    rtt_error_P1 = calculate_error(rtt_distances_P1, gps_distances_P1_rtt)
    rtt_error_X3 = calculate_error(rtt_distances_X3, gps_distances_X3_rtt)

    multilateration_error_P1 = calculate_error(multilateration_distances_P1, gps_distances_P1_multilat)   
    multilateration_error_X3 = calculate_error(multilateration_distances_X3, gps_distances_X3_multilat)
 

    return rtt_error_P1, rtt_error_X3, multilateration_error_P1, multilateration_error_X3   


def filter_data(times, data):
    return [t for t, d in zip(times, data) if t >= 100], \
            [d for t, d in zip(times, data) if t >= 100]



def get_gps_positions_at_times(gps_times, gps_positions, target_times):

    gps_times = np.array(gps_times)
    gps_positions = np.array(gps_positions)
    target_times = np.array(target_times)

    corresponding_gps_positions = []

   
    for time in target_times:
        index = np.argmin(np.abs(gps_times - time))
        corresponding_gps_positions.append(gps_positions[index])

        print(f"Goal time: {time}, GNSS time updated: {gps_times[index]}")


    corresponding_gps_positions_tuplas= [tuple(pos) for pos in corresponding_gps_positions]
    
    return corresponding_gps_positions_tuplas

def calculate_multilat_errors(gps_data, gps_times, rssi_data_P1, rssi_times_P1, rssi_data_X3, rssi_times_X3,
                                   multilateration_distances_P1, multilateration_times_P1, multilateration_distances_X3, multilateration_times_X3,
                                   rtt_distances_P1, rtt_distances_times_P1, rtt_distances_X3, rtt_distances_times_X3, P1_coord_estimated, X3_coord_estimated):
    
 
    P1_realPosition = (36.71541060, -4.49009390,  48.31)
    X3_realPosition = (36.71538600, -4.49011380,  49.58)

    gps_times_filtered, gps_distances_P1 = filter_and_synchronize_data(gps_times, gps_data, P1_realPosition)
    _, gps_distances_X3 = filter_and_synchronize_data(gps_times, gps_data, X3_realPosition)

    p1_multilat2real_distances = [euclidean_distance_3d(coord, P1_realPosition, True) for coord in P1_coord_estimated]
    x4_multilat2real_distances = [euclidean_distance_3d(coord, X3_realPosition, True) for coord in X3_coord_estimated]

    return p1_multilat2real_distances, x4_multilat2real_distances


def plot_ecdf_conjunta(em_P1, em_X3, rtt_error_P1_uav, rtt_error_X3_uav, rtt_error_P1_j8, rtt_error_X3_j8, rtt_error_X3_1F, rtt_error_P1_1F, rtt_error_P1_AA, rtt_error_X3_AA):
    
    def ecdf(data):
        x = np.sort(data)
        y = np.arange(1, len(x) + 1) / len(x)
        return x, y
    
    def calcular_percentil(data, percentil):
        return np.percentile(data, percentil)

    fig, axes = plt.subplots(1, 2, figsize=(20, 6), sharey=True)
    ax_rtt, ax_mlt = axes  
    palette = {
        'uav_P1': '#1f77b4',  # Blue
        'uav_X3': '#ff7f0e',  # Organge
        'j8_P1': '#2ca02c',   # Green
        'j8_X3': '#d62728',   # Red
        '1f_P1': '#9467bd',   # Purple
        '1f_X3': '#17becf',   # Turquoise
        'aa_P1': '#8c564b',   # Brown
        'aa_X3': '#e377c2',   # Pink
    }
    linestyles = {'uav': '-', 'j8': '-', '1f': '--', 'aa': '--'}
    linewidth = 2.5  

    # ===============================
    # Subplot 1: RTT Error ECDF
    # ===============================
    curves_rtt = [
        ('P1 from UAV (detected ' + str(len(rtt_error_P1_uav)) + ' times)', rtt_error_P1_uav, 'uav_P1', 'uav'), 
        ('X3 from UAV (detected ' + str(len(rtt_error_X3_uav)) + ' times)', rtt_error_X3_uav, 'uav_X3', 'uav'),

        ('P1 from UGV (detected ' + str(len(rtt_error_P1_j8)) + ' times)', rtt_error_P1_j8, 'j8_P1', 'j8'),    
        ('X3 from UGV (detected ' + str(len(rtt_error_X3_j8)) + ' times)', rtt_error_X3_j8, 'j8_X3', 'j8'),

        ('P1 from 1F (detected ' + str(len(rtt_error_P1_1F)) + ' times)', rtt_error_P1_1F, '1f_P1', '1f'),    
        ('X3 from 1F (detected ' + str(len(rtt_error_X3_1F)) + ' times)', rtt_error_X3_1F, '1f_X3', '1f'),   

        ('P1 from AA (detected ' + str(len(rtt_error_P1_AA)) + ' times)', rtt_error_P1_AA, 'aa_P1', 'aa'),    
        ('X3 from AA (detected ' + str(len(rtt_error_X3_AA)) + ' times)', rtt_error_X3_AA, 'aa_X3', 'aa')
    ]


    all_percentiles = []  # List to store (abscissa, graph, initial ordinate, marker type) 

  
    for label, data, color_key, linestyle_key in curves_rtt:
        if len(data) > 0:  
            x, y = ecdf(data)

            x_80 = calcular_percentil(x, 80)
            x_95 = calcular_percentil(x, 95)

            all_percentiles.append((x_80, label, 0.80, 's', color_key)) 
            all_percentiles.append((x_95, label, 0.95, 'o', color_key))  

            ax_rtt.plot(x, y, label=label, color=palette[color_key], linestyle=linestyles[linestyle_key], linewidth=2.0)

   
    all_percentiles = sorted(all_percentiles, key=lambda p: p[0])

 
    toggle = True 

    for x_val, label, y_init, marker, color_key in all_percentiles:
       
        y_pos = 0.45 if toggle else 0.60
        toggle = not toggle  

        ax_rtt.scatter(x_val, y_init, marker=marker, color='black', s=100, edgecolors='k', alpha=0.4)

        ax_rtt.plot([x_val, x_val], [y_init, y_pos], color='black', linestyle='--', linewidth=0.8, alpha=0.8)

        ax_rtt.annotate(f'{x_val:.2f}', xy=(x_val, y_pos), xytext=(5, -10),
                        textcoords='offset points', fontsize=14, color=palette[color_key])

    ax_rtt.set_title('RTT Error ECDF', fontsize=15)
    ax_rtt.set_xlabel('RTT Distance Error (m)', fontsize=14)
    ax_rtt.set_ylabel('Cumulative Probability', fontsize=14)
    ax_rtt.legend(fontsize=12, loc='lower right')
    ax_rtt.grid(True, linestyle='--', alpha=0.7)


    # ===============================
    # Subplot 3: Multilateration Error ECDF
    # ===============================


    curves_mlt = [
        ('Multilateration to P1 (located ' + str(len(em_P1)) + ' times)', em_P1,'uav_P1', 'uav'), 
        ('Multilateration to X3 (located ' + str(len(em_X3)) + ' times)', em_X3,'uav_X3', 'uav'), 
    ]

    all_percentiles = [] 

    for label, data, color_key, linestyle_key in curves_mlt:
        if len(data) > 0:  
            x, y = ecdf(data)

            x_80 = calcular_percentil(x, 80)
            x_95 = calcular_percentil(x, 95)

            all_percentiles.append((x_80, 0.80, 's', label, color_key))  
            all_percentiles.append((x_95, 0.95, 'o', label, color_key))  


    all_percentiles = sorted(all_percentiles, key=lambda p: p[0])

    toggle = True  

    for x_val, y_init, marker, label, color_key in all_percentiles:
        
        y_pos = 0.45 if toggle else 0.75
        toggle = not toggle  

     
        ax_mlt.scatter(x_val, y_init, marker=marker, color='black', s=100, edgecolors='k', alpha=0.5)
        ax_mlt.plot([x_val, x_val], [y_init, y_pos], color='black', linestyle='--', linewidth=0.8, alpha=0.8)
        ax_mlt.annotate(f'{x_val:.2f}', xy=(x_val, y_pos), xytext=(5, -10),
                        textcoords='offset points', fontsize=10, color=palette[color_key])


    for label, data, color_key, linestyle_key in curves_mlt:
        if len(data) > 0: 
            x, y = ecdf(data)

            ax_mlt.plot(x, y, label=label, color=palette[color_key], linestyle='-', linewidth=0.8, alpha=0.7)
            ax_mlt.scatter(x, y, color=palette[color_key], edgecolors='k', alpha=0.75, s=50)

    ax_mlt.set_title('Multilateration Error ECDF', fontsize=15)
    ax_mlt.set_xlabel('Positioning Error (m)', fontsize=15)
    ax_mlt.legend(fontsize=14, loc='lower right')
    ax_mlt.grid(True, linestyle='--', alpha=0.6)

    plt.tight_layout()
    
    output_file = os.path.join(output_dir, "ecdf.png")
    fig.savefig(output_file, dpi=300)  
    plt.close(fig)
    print(f"Figure saved successfully at {output_file}")

    #plt.show()
    #plt.close()

def plot_altitudeUAV(gps_data_uav, gps_times_uav, rtt_distances_P1_uav, rtt_distances_X3_uav, rtt_distances_times_P1_uav, rtt_distances_times_X3_uav,
                     rssi_data_P1_uav, rssi_times_P1_uav,
                     rssi_data_X3_uav, rssi_times_X3_uav,
                     rssi_values_X3_uav, rssi_values_P1_uav):
    """
    Plots UAV altitude, RSSI values for P1 and X3, and estimated distances over time.
    """
    import matplotlib.pyplot as plt
    import matplotlib as mpl

    mpl.rcParams['text.usetex'] = False
    mpl.rcParams['font.family'] = 'serif'
    mpl.rcParams['font.size'] = 12

    P1_realPosition = (36.71541060, -4.49009390, 48.31)
    X3_realPosition = (36.71538600, -4.49011380, 49.58)

    groundT_uavToP1 = [euclidean_distance_3d(gps_value, P1_realPosition, False) for gps_value in gps_data_uav]
    groundT_uavToX3 = [euclidean_distance_3d(gps_value, X3_realPosition, False) for gps_value in gps_data_uav]

    altitudes = [data[2] for data in gps_data_uav]

    fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(14, 12))
    plt.subplots_adjust(hspace=0.03)

    # ---------------------
    # Plot 1: UAV Altitude and RSSI (ax1)
    # ---------------------
    dash_dot_dot_dot = (0, (3, 1, 1, 1, 1, 1))

    ax1.plot(gps_times_uav, altitudes, label='UAV Altitude',
             color='green', linewidth=3, linestyle=dash_dot_dot_dot)
    ax1.set_ylabel('Altitude (m)', fontsize=14, color='green')
    ax1.set_ylim(45, 71)
    ax1.set_title('UAV Altitude Over Time', fontsize=16, fontweight='bold')
    ax1.tick_params(axis='y', which='major', labelsize=12, colors='green')
    ax1.set_facecolor('#f0f0f0')
    ax1.grid(True, linestyle='--', linewidth=0.5, alpha=0.45)

    ax_rssi = ax1.twinx()
    scatter_rssi_p1 = ax_rssi.scatter(rssi_times_P1_uav, rssi_values_P1_uav, label='RSSI for P1', marker='*', color='#d62728', edgecolors='k', s=100, alpha=0.45)
    scatter_rssi_x3 = ax_rssi.scatter(rssi_times_X3_uav, rssi_values_X3_uav, label='RSSI for X3', marker='o', color='#ff9896', edgecolors='k', s=100, alpha=0.45)
    ax_rssi.set_ylabel('RSSI (dBm)', fontsize=14, color='red')
    ax_rssi.tick_params(axis='y', labelsize=12, colors='red')
    ax_rssi.spines['right'].set_color('red')

    handles1, labels1 = ax1.get_legend_handles_labels()
    handles2, labels2 = ax_rssi.get_legend_handles_labels()
    combined_handles = handles1 + handles2
    combined_labels = labels1 + labels2

    legend_altitude_uav = ax1.legend(handles=combined_handles, labels=combined_labels, fontsize=14, loc='upper left')
    legend_altitude_uav.set_draggable(True)  

    # ---------------------
    # Plot 2: Estimated Distance and Ground Truth (ax2)
    # ---------------------
    scatter_dist_p1 = ax2.scatter(rtt_distances_times_P1_uav, rtt_distances_P1_uav, label='RTT estimation to P1', marker='*', color='#1f77b4', edgecolors='k', s=100, alpha=0.45)
    scatter_dist_x3 = ax2.scatter(rtt_distances_times_X3_uav, rtt_distances_X3_uav, label='RTT estimation to X3', marker='o', color='#aec7e8', edgecolors='k', s=100, alpha=0.45)
    line_gt_p1, = ax2.plot(gps_times_uav, groundT_uavToP1, label='Ground Truth to P1', color='green', linewidth=2, linestyle='-')
    line_gt_x3, = ax2.plot(gps_times_uav, groundT_uavToX3, label='Ground Truth to X3', color='green', linewidth=2, linestyle='--')

    ax2.set_xlim(-10, 454)
    ax1.set_xlim(-10, 454)
    ax2.set_ylabel('Distance (m)', fontsize=14, color='blue')
    ax2.tick_params(axis='y', labelsize=12, colors='blue')
    ax2.spines['left'].set_color('blue')
    ax2.set_facecolor('#f0f0f0')
    ax2.grid(True, linestyle='--', linewidth=0.5, alpha=0.7)

    legend_distances = ax2.legend(handles=[scatter_dist_p1, scatter_dist_x3, line_gt_p1, line_gt_x3], fontsize=14, loc='upper right')
    legend_distances.set_draggable(True)

    fig.suptitle('UAV Experimental Data Overview', fontsize=18, fontweight='bold')
    plt.tight_layout(rect=[0, 0.03, 1, 0.95])
    
    output_file = os.path.join(output_dir, "uav_altitude.png")
    fig.savefig(output_file, dpi=300)  
    plt.close(fig)
    print(f"Figure saved successfully at {output_file}")
    
    #plt.show()
    #plt.close()

    
def plot_altitudeRoverJ8(gps_data_j8, gps_times_j8, rtt_distances_P1_j8, rtt_distances_X3_j8, rtt_distances_times_X3_j8, rtt_distances_times_P1_j8,
                         rssi_data_P1_j8, rssi_times_P1_j8, 
                         rssi_data_X3_j8, rssi_times_X3_j8, 
                         rssi_values_X3_j8, rssi_values_P1_j8):
    """
    Plots UGV altitude, RSSI values for P1 and X3, and estimated distances over time.
    """
    import matplotlib.pyplot as plt
    import matplotlib as mpl

    mpl.rcParams['text.usetex'] = False
    mpl.rcParams['font.family'] = 'serif'
    mpl.rcParams['font.size'] = 12

    P1_realPosition = (36.71541060, -4.49009390, 48.31)
    X3_realPosition = (36.71538600, -4.49011380, 49.58) 

    groundT_j8ToP1 = [euclidean_distance_3d(gps_value, P1_realPosition, False) for gps_value in gps_data_j8]
    groundT_j8ToX3 = [euclidean_distance_3d(gps_value, X3_realPosition, False) for gps_value in gps_data_j8]

    altitudes = [data[2] for data in gps_data_j8]

    fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(14, 12))
    plt.subplots_adjust(hspace=0.03)

    # ---------------------
    # Plot 1: Altitude and RSSI (ax1)
    # ---------------------
    dash_dot_dot_dot = (0, (3, 1, 1, 1, 1, 1))

    ax1.plot(gps_times_j8, altitudes, label='UGV Altitude',
             color='green', linewidth=3, linestyle=dash_dot_dot_dot)
    ax1.set_ylabel('Altitude (m)', fontsize=14, color='green')
    ax1.set_ylim(45, 71)
    ax1.set_title('UGV Altitude Over Time', fontsize=16, fontweight='bold')
    ax1.tick_params(axis='y', which='major', labelsize=12, colors='green')
    ax1.set_facecolor('#f0f0f0')
    ax1.grid(True, linestyle='--', linewidth=0.5, alpha=0.45)

    ax_rssi = ax1.twinx()
    scatter_rssi_p1 = ax_rssi.scatter(rssi_times_P1_j8, rssi_values_P1_j8, label='RSSI for P1', marker='*', color='#d62728', edgecolors='k', s=100, alpha=0.45)
    scatter_rssi_x3 = ax_rssi.scatter(rssi_times_X3_j8, rssi_values_X3_j8, label='RSSI for X3', marker='o', color='#ff9896', edgecolors='k', s=100, alpha=0.45)
    ax_rssi.set_ylabel('RSSI (dBm)', fontsize=14, color='red')
    ax_rssi.tick_params(axis='y', labelsize=12, colors='red')
    ax_rssi.spines['right'].set_color('red')

    ax1.annotate('', xy=(152, 58), xytext=(0, 58),
                 arrowprops=dict(arrowstyle='<|-|>', color='red'))
    ax1.text(76, 59, "Maximum GNSS altitude error: 1.49 m", color='red', fontsize=12, ha='center')

    ax1.plot([0, 0], [0, 58], color='red', linestyle='-.', linewidth=0.5)
    ax1.plot([152, 152], [0, 58], color='red', linestyle='-.', linewidth=0.5)

    handles1, labels1 = ax1.get_legend_handles_labels()
    handles2, labels2 = ax_rssi.get_legend_handles_labels()
    combined_handles = handles1 + handles2
    combined_labels = labels1 + labels2

    legend_alt_ugv = ax1.legend(handles=combined_handles, labels=combined_labels, fontsize=14, loc='upper left')
    legend_alt_ugv.set_draggable(True)  

    # ---------------------
    # Plot 2: Estimated Distance and Ground Truth (ax2)
    # ---------------------
    ax2.axvline(x=152, color='red', linestyle='--', linewidth=1.5)
    ax2.text(153, 20, "Rover J8 starts \nto move", color='red', fontsize=12, ha='left', va='bottom')

    ax2.set_xlabel('Time (s)', fontsize=14)
    ax2.set_facecolor('#f0f0f0')
    ax2.grid(True, linestyle='--', linewidth=0.5, alpha=0.7)

    scatter_dist_p1 = ax2.scatter(rtt_distances_times_P1_j8, rtt_distances_P1_j8, label='RTT estimation to P1', marker='*', color='#1f77b4', edgecolors='k', s=100, alpha=0.45)
    scatter_dist_x3 = ax2.scatter(rtt_distances_times_X3_j8, rtt_distances_X3_j8, label='RTT estimation to X3', marker='o', color='#aec7e8', edgecolors='k', s=100, alpha=0.45)
    line_gt_p1, = ax2.plot(gps_times_j8, groundT_j8ToP1, label='Ground Truth to P1', color='green', linewidth=2, linestyle='-')
    line_gt_x3, = ax2.plot(gps_times_j8, groundT_j8ToX3, label='Ground Truth to X3', color='green', linewidth=2, linestyle='--')

    ax2.set_ylim(0, 35)
    ax2.set_xlim(-10, 454)
    ax1.set_xlim(-10, 454)
    ax2.set_ylabel('Distance (m)', fontsize=14, color='blue')
    ax2.tick_params(axis='y', labelsize=12, colors='blue')
    ax2.spines['left'].set_color('blue')

    legend_distances = ax2.legend(handles=[scatter_dist_p1, scatter_dist_x3, line_gt_p1, line_gt_x3], fontsize=14, loc='upper right')
    legend_distances.set_draggable(True)

    fig.suptitle('UGV Experimental Data Overview', fontsize=18, fontweight='bold')
    plt.tight_layout(rect=[0, 0.03, 1, 0.95])
    
    output_file = os.path.join(output_dir, "ugv_altitude.png")
    fig.savefig(output_file, dpi=300)  
    plt.close(fig)
    print(f"Figure saved successfully at {output_file}")
    #plt.show()


def main():

    # Read `bag_path`, `bag_start_time`, and `bag_end_time` from command line arguments
    if len(sys.argv) > 3:
        bag_path = sys.argv[1]
        bag_start_time = float(sys.argv[2])
        bag_end_time = float(sys.argv[3])
    else:
        print("Error: 'bag_path', 'bag_start_time', and 'bag_end_time' are required arguments.")
        return

    print(f"Using bag_path: {bag_path}")
    print(f"Using bag_start_time: {bag_start_time}")
    print(f"Using bag_end_time: {bag_end_time}")

    start_interval = 0   
    end_interval   = bag_end_time - bag_start_time 
    altitude_threshold = 0

    (gps_data_j8, gps_times_j8, gps_data_uav, gps_times_uav, rssi_data_P1_uav, rssi_times_P1_uav, rssi_data_X3_uav, rssi_times_X3_uav,
            multilateration_distances_P1_uav, multilateration_times_P1_uav, multilateration_distances_X3_uav, multilateration_times_X3_uav,
            rtt_distances_P1_uav, rtt_distances_times_P1_uav, rtt_distances_X3_uav, rtt_distances_times_X3_uav, rssi_data_P1_j8, rssi_times_P1_j8, rssi_data_X3_j8, rssi_times_X3_j8,
            multilateration_distances_P1_j8, multilateration_times_P1_j8, multilateration_distances_X3_j8, multilateration_times_X3_j8, multilateration_distances_P1_uav, multilateration_times_P1_uav, multilateration_distances_X3_uav, multilateration_times_X3_uav,
            rtt_distances_P1_j8, rtt_distances_times_P1_j8, rtt_distances_X3_j8, rtt_distances_times_X3_j8,  X3_coord_estimated, P1_coord_estimated, rssi_values_P1_j8, rssi_values_X3_j8, rssi_values_P1_uav, rssi_values_X3_uav, rtt_distances_P1_1F, rtt_distances_X3_1F, rtt_distances_X3_AA, rtt_distances_P1_AA) = read_ros1_bag(bag_path, bag_start_time, start_interval, end_interval, altitude_threshold, P0, n, d0)

    gps_distances_P1_j8 = [euclidean_distance_3d(gps, P1_coords, False) for gps in gps_data_j8]  
    gps_distances_X3_j8 = [euclidean_distance_3d(gps, X3_coords, False) for gps in gps_data_j8] 

    gps_distances_P1_uav = [euclidean_distance_3d(gps, P1_coords, False) for gps in gps_data_uav]  
    gps_distances_X3_uav = [euclidean_distance_3d(gps, X3_coords, False) for gps in gps_data_uav]  


    

    plot_altitudeRoverJ8(gps_data_j8, gps_times_j8, rtt_distances_P1_j8, rtt_distances_X3_j8, rtt_distances_times_X3_j8, rtt_distances_times_P1_j8,
                         rssi_data_P1_j8, rssi_times_P1_j8, 
                         rssi_data_X3_j8, rssi_times_X3_j8, 
                         rssi_values_X3_j8, rssi_values_P1_j8)
        

    plt.close()

    plot_altitudeUAV(gps_data_uav, gps_times_uav, rtt_distances_P1_uav, rtt_distances_X3_uav, rtt_distances_times_P1_uav, rtt_distances_times_X3_uav,
                    rssi_data_P1_uav, rssi_times_P1_uav,
                    rssi_data_X3_uav, rssi_times_X3_uav,
                    rssi_values_X3_uav, rssi_values_P1_uav)
    
    plt.close()
    
    em_P1,em_X3=calculate_multilat_errors(gps_data_j8, gps_times_j8, rssi_data_P1_j8, rssi_times_P1_j8, rssi_data_X3_j8, rssi_times_X3_j8,
                      multilateration_distances_P1_j8, multilateration_times_P1_j8, multilateration_distances_X3_j8, multilateration_times_X3_j8,
                      rtt_distances_P1_j8, rtt_distances_times_P1_j8, rtt_distances_X3_j8, rtt_distances_times_X3_j8, P1_coord_estimated, X3_coord_estimated)

 
    anchor1F_position = (36.7154688, -4.4902751, 48.63)
    groundTruth_1F_P1 = euclidean_distance_3d(anchor1F_position, P1_coords, False)
    vector_groundTruth_1F_P1 = [groundTruth_1F_P1]*len(rtt_distances_P1_1F) 
    groundTruth_1F_X3 = euclidean_distance_3d(anchor1F_position, X3_coords, False)
    vector_groundTruth_1F_X3 = [groundTruth_1F_X3]*len(rtt_distances_X3_1F) 


    anchorAA_position = (36.7155386,  -4.4900179, 48.63)
    groundTruth_AA_P1 = euclidean_distance_3d(anchorAA_position, P1_coords, False)
    vector_groundTruth_AA_P1 = [groundTruth_AA_P1]*len(rtt_distances_P1_AA) 
    groundTruth_AA_X3 = euclidean_distance_3d(anchorAA_position, X3_coords, False)
    vector_groundTruth_AA_X3 = [groundTruth_AA_X3]*len(rtt_distances_X3_AA) 


    rtt_error_P1_AA = calculate_error(rtt_distances_P1_AA, vector_groundTruth_AA_P1)
    rtt_error_X3_AA = calculate_error(rtt_distances_X3_AA, vector_groundTruth_AA_X3)

    rtt_error_P1_1F = calculate_error(rtt_distances_P1_1F, vector_groundTruth_1F_P1)
    rtt_error_X3_1F = calculate_error(rtt_distances_X3_1F, vector_groundTruth_1F_X3)
    
    rtt_error_P1_j8 = calculate_error(rtt_distances_P1_j8, gps_distances_P1_j8)
    rtt_error_X3_j8 = calculate_error(rtt_distances_X3_j8, gps_distances_X3_j8)

    rtt_error_P1_uav = calculate_error(rtt_distances_P1_uav, gps_distances_P1_uav)
    rtt_error_X3_uav = calculate_error(rtt_distances_X3_uav, gps_distances_X3_uav)

    print(sorted(rtt_error_X3_j8))

    plot_ecdf_conjunta(em_P1, em_X3, rtt_error_P1_uav, rtt_error_X3_uav, rtt_error_P1_j8, rtt_error_X3_j8, rtt_error_X3_1F, rtt_error_P1_1F, rtt_error_P1_AA, rtt_error_X3_AA)

    plt.close()

if __name__ == '__main__':
    main()

