function cost = cost_fun(x)
%COST_FUN Summary of this function goes here
%   Detailed explanation goes here
    disp(x);
    global cost_map track_map;
    
    r = 3.5e-2;              % Radius of the wheel [m]
    L = 10e-2;               % Distance between wheels [m]
    
    theta_0 = deg2rad(0);    % Initial Theta value
    x0 = 1;                  % Initial X Coordinate
    y0 = 1.146;              % Initial Y Coordinate

    %model_name = 'LINE_CONTROL';
    model_name = 'THETA_ERROR_LINE_CONTROL';
    sim_in     = Simulink.SimulationInput(model_name);
    %sim_in     = sim_in.setVariable('k_1', x(1));
    %sim_in     = sim_in.setVariable('k_2', x(2));
    %sim_in     = sim_in.setVariable('k_3', x(3));
    sim_in     = sim_in.setVariable('P_right', x(1));
    sim_in     = sim_in.setVariable('I_right', x(2));
    sim_in     = sim_in.setVariable('D_right', x(3));
    sim_in     = sim_in.setVariable('P_left',  x(4));
    sim_in     = sim_in.setVariable('I_left',  x(5));
    sim_in     = sim_in.setVariable('D_left',  x(6));

    sim_in     = sim_in.setVariable('P_sensor_1', [5.5e-2  7e-2]');
    sim_in     = sim_in.setVariable('P_sensor_2', [3e-2    7e-2]');
    sim_in     = sim_in.setVariable('P_sensor_3', [0     8.5e-2]');
    sim_in     = sim_in.setVariable('P_sensor_4', [-3e-2   7e-2]');
    sim_in     = sim_in.setVariable('P_sensor_5', [-5.5e-2 7e-2]');

    sim_in     = sim_in.setVariable('track_map', track_map);
    sim_in     = sim_in.setVariable('r', r);
    sim_in     = sim_in.setVariable('L', L);
    sim_in     = sim_in.setVariable('theta_0', theta_0);
    sim_in     = sim_in.setVariable('x0', x0);
    sim_in     = sim_in.setVariable('y0', y0);


    out = sim(sim_in);
    theta_dot= squeeze(out.logsout{10}.Values.Data);
    x_points = squeeze(out.logsout{12}.Values.Data);
    y_points = squeeze(out.logsout{13}.Values.Data);
    
    cost = double(0);
    map_limits = flip(size(cost_map, 1:2));
    
    % Calculate total distance traveled
    %total_distance = sum(sqrt(diff(x_points).^2 + diff(y_points).^2));
    
    %movement_threshold = 0.1;  % Total distance threshold in meters (adjust as needed)
    %total_distance = sqrt((x_points(end) - x_points(1))^2 + (y_points(end) - y_points(1))^2);
    %movement_threshold = 0.08;  % Threshold in meters (50mm for example)
    

    % Penalize if total distance traveled is below the threshold
    %if total_distance < movement_threshold
    %    cost = cost + 1e5;  % Large penalty for lack of movement
    %    return;             % Exit early if there is no significant movement
    %end

    % Regular cost calculation based on following the track
    for data_index = 1:length(x_points)
        x_coord = ceil(x_points(data_index)*1e3);
        y_coord = ceil(y_points(data_index)*1e3);
    
        if any(map_limits<[x_coord y_coord], 'all') || any(0 >= [x_coord y_coord], 'all')
            cost = cost + 1e3;
            continue;
        end
    
        offset_penality = double(cost_map(y_coord, x_coord));
        cost = cost + (255 - offset_penality);
    end
    
    theta_dot_diff = diff(theta_dot);           % Calculate rate of change of theta_dot
    jitter_penalty = max(abs(theta_dot_diff));  % Sum of absolute differences
    cost = cost + jitter_penalty * 1e2;         % Apply a scaling factor to the penalty
end