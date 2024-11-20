x = x_opt;
load track_map

r = 3.5e-2;              % Radius of the wheel [m]
L = 10e-2;               % Distance between wheels [m]

theta_0 = deg2rad(0);    % Initial Theta value
x0 = 1;                  % Initial X Coordinate
y0 = 1.146;              % Initial Y Coordinate

model_name = 'THETA_ERROR_LINE_CONTROL';
sim_in     = Simulink.SimulationInput(model_name);
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

imshow(cost_map);
hold(gca, 'on');           % Hold the current axes for further plotting

% Set axis limits to match image pixel dimensions (1 pixel per mm)
axis on;                           % Turn on the axis
ax = gca;                          % Get current axes handle
ax.XLim = [0 size(track_map, 2)];  % Set X-axis limits to image width (in pixels)
ax.YLim = [0 size(track_map, 1)];  % Set Y-axis limits to image height (in pixels)

% Now scatter the point at 1 meter (1000 mm) in both x and y
scatter(x_points*1e3, y_points*1e3, 100, 'filled');

% And plot theta dot for jitter analysis
figure;
plot(out.tout(1:end-1), diff(theta_dot));