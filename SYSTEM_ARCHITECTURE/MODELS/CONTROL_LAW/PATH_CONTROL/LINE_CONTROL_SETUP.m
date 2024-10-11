load track_map.mat
r = 3.5e-2;   % Radius of the wheel [m]
L = 10e-2;    % Distance between wheels [m]
Ts = 1/10;    % Sampling Rate of system

theta_0 = deg2rad(-90);  % Initial Theta value
x0 = 1;                  % Initial X Coordinate
y0 = 1.146;              % Initial Y Coordinate
states_0 = [0 0 0 0 0 0 theta_0 0];
k = [1 1 1];

P_left = 1;
I_left = 1;
D_left = 1;

P_right = 1;
I_right = 1;
D_right = 1;
%%
imshow(track_map, [0 1]);  % Display the image
hold(gca, 'on');    % Hold the current axes for further plotting

% Set axis limits to match image pixel dimensions (1 pixel per mm)
axis on;            % Turn on the axis
ax = gca;           % Get current axes handle
ax.XLim = [0 size(track_map, 2)];  % Set X-axis limits to image width (in pixels)
ax.YLim = [0 size(track_map, 1)];  % Set Y-axis limits to image height (in pixels)
%ax.YDir = 'normal'; % Ensure that Y-axis is not flipped (origin at top-left)

% Now scatter the point at 1 meter (1000 mm) in both x and y
scatter(1e3, 1.146e3, 100, 'filled');
hold on;


%%
global track_map cost_map;
sensor_emulation(x0, y0, deg2rad(-90))
