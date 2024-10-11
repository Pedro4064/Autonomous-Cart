%x = x_opt;
%x =     [0.0001    1.3405    7.5021    0.6319    0.0005    0.0001    0.0000    6.4999    9.6661];
%x =     [6.3328    5.1110    8.9397    2.3632    6.0819    5.3784    8.6901    0.3448    5.5464]
%x  = [1.8198    0.2780    4.2303    8.0298    1.2317    6.1204    3.2980    0.4734    4.0140];

load track_map
r = 3.5e-2;              % Radius of the wheel [m]
L = 10e-2;               % Distance between wheels [m]

theta_0 = deg2rad(-90);  % Initial Theta value
x0 = 1;                  % Initial X Coordinate
y0 = 1.146;              % Initial Y Coordinate

model_name = 'LINE_CONTROL';
sim_in     = Simulink.SimulationInput(model_name);
sim_in     = sim_in.setVariable('k_1', x(1));
sim_in     = sim_in.setVariable('k_2', x(2));
sim_in     = sim_in.setVariable('k_3', x(3));
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
x_points = squeeze(out.logsout{8}.Values.Data);
y_points = squeeze(out.logsout{9}.Values.Data);

%imshow(track_map, [0 1]);  % Display the image
imshow(cost_map);
hold(gca, 'on');           % Hold the current axes for further plotting

% Set axis limits to match image pixel dimensions (1 pixel per mm)
axis on;                           % Turn on the axis
ax = gca;                          % Get current axes handle
ax.XLim = [0 size(track_map, 2)];  % Set X-axis limits to image width (in pixels)
ax.YLim = [0 size(track_map, 1)];  % Set Y-axis limits to image height (in pixels)

% Now scatter the point at 1 meter (1000 mm) in both x and y
scatter(x_points*1e3, y_points*1e3, 100, 'filled');
hold on;
