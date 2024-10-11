function cost = cost_fun(x)
%COST_FUN Summary of this function goes here
%   Detailed explanation goes here

    global cost_map track_map;
    
    r = 3.5e-2;              % Radius of the wheel [m]
    L = 10e-2;               % Distance between wheels [m]
    
    theta_0 = deg2rad(-90);  % Initial Theta value
    x0 = 1;                  % Initial X Coordinate
    y0 = 1.146;              % Initial Y Coordinate

    model_name = 'LINE_CONTROL';
    sim_in     = Simulink.SimulationInput(model_name);
    sim_in     = sim_in.setVariable('k', x(1:3));
    sim_in     = sim_in.setVariable('P_right', x(4));
    sim_in     = sim_in.setVariable('I_right', x(5));
    sim_in     = sim_in.setVariable('D_right', x(6));
    sim_in     = sim_in.setVariable('P_left',  x(7));
    sim_in     = sim_in.setVariable('I_left',  x(8));
    sim_in     = sim_in.setVariable('D_left',  x(9));

    sim_in     = sim_in.setVariable('track_map', track_map);
    sim_in     = sim_in.setVariable('r', r);
    sim_in     = sim_in.setVariable('L', L);
    sim_in     = sim_in.setVariable('theta_0', theta_0);
    sim_in     = sim_in.setVariable('x0', x0);
    sim_in     = sim_in.setVariable('y0', y0);


    out = sim(sim_in);
    theta_dot= out.logsout{6}.Values.Data;
    x_points = out.logsout{8}.Values.Data;
    y_points = out.logsout{9}.Values.Data;
    
    cost = double(0);
    map_limits = flip(size(cost_map, 1:2));
    
    for data_index = 1:length(x_points)
        x_coord = ceil(x_points(data_index)*1e3);
        y_coord = ceil(y_points(data_index)*1e3);
    
        if any(map_limits<[x_coord y_coord], 'all') || any(0 > [x_coord y_coord], 'all')
            cost = cost + 1e3;
            continue;
        end
    
        offset_penality = double(cost_map(y_coord, x_coord));
        cost = cost + (255 - offset_penality);
    end
    
    theta_dot_diff = diff(theta_dot);           % Calculate rate of change of theta_dot
    jitter_penalty = sum(abs(theta_dot_diff));  % Sum of absolute differences
    cost = cost + jitter_penalty * 1e2;         % Apply a scaling factor to the penalty
end