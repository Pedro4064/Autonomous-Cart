function sensor_readings = sensor_emulation(x_world, y_world, theta)

    global track_map
    rotation_matrix = [cos(theta) -sin(theta)
                        sin(theta) cos(theta)];
    
    P_sensor_1 = [5.5e-2  7e-2]';
    P_sensor_2 = [3e-2    7e-2]';
    P_sensor_3 = [0     8.5e-2]';
    P_sensor_4 = [-3e-2   7e-2]';
    P_sensor_5 = [-5.5e-2 7e-2]';
    
    sensor_1_coord = [x_world y_world]' + rotation_matrix * P_sensor_1;
    sensor_2_coord = [x_world y_world]' + rotation_matrix * P_sensor_2;
    sensor_3_coord = [x_world y_world]' + rotation_matrix * P_sensor_3;
    sensor_4_coord = [x_world y_world]' + rotation_matrix * P_sensor_4;
    sensor_5_coord = [x_world y_world]' + rotation_matrix * P_sensor_5;
    
    sensor_1_coord = ceil(sensor_1_coord*1e3); % Convert to mm since 1px=1mm
    sensor_2_coord = ceil(sensor_2_coord*1e3); % Convert to mm since 1px=1mm
    sensor_3_coord = ceil(sensor_3_coord*1e3) % Convert to mm since 1px=1mm
    sensor_4_coord = ceil(sensor_4_coord*1e3); % Convert to mm since 1px=1mm
    sensor_5_coord = ceil(sensor_5_coord*1e3); % Convert to mm since 1px=1mm
    
    scatter(sensor_1_coord(1), sensor_1_coord(2), 100, 'filled');
    scatter(sensor_2_coord(1), sensor_2_coord(2), 100, 'filled');
    scatter(sensor_3_coord(1), sensor_3_coord(2), 100, 'filled');
    scatter(sensor_4_coord(1), sensor_4_coord(2), 100, 'filled');
    scatter(sensor_5_coord(1), sensor_5_coord(2), 100, 'filled');
    
    max_line_sensor_value = 2500;
    min_line_sensor_value = 500;
    
    sensor_readings = zeros(1, 5);
    sensor_readings(1) = track_map(sensor_1_coord(2), sensor_1_coord(1));
    sensor_readings(2) = track_map(sensor_2_coord(2), sensor_2_coord(1));
    sensor_readings(3) = track_map(sensor_3_coord(2), sensor_3_coord(1));
    sensor_readings(4) = track_map(sensor_4_coord(2), sensor_4_coord(1));
    sensor_readings(5) = track_map(sensor_5_coord(2), sensor_5_coord(1));
    
    sensor_readings(sensor_readings == 0) = min_line_sensor_value;
    sensor_readings(sensor_readings == 1) = max_line_sensor_value;
end