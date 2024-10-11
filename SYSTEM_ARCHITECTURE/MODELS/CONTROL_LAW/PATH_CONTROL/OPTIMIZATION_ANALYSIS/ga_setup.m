%% Load Constants and Maps Data %%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

load track_map.mat

global track_map cost_map;

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

%% Define Bounds for Optimization %%%%%%%%
% All PID values must be greater than zero
%but the k gains may be less than zero.
% Furthermore, set an upper bound of 1000
%of all variables.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

lb = zeros(1, 9);        % Lower bounds (0 for each parameter)
lb(1:3) = -100;          % K gains can be less than zero

ub = ones(1, 9) * 1000;  % Upper bounds (for example, you can adjust as needed)

%% Configure and Run Optimization %%%%%%%%%
% Configure to use parallel in multi core
%systems, and display iterations.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
options = optimoptions('ga', 'Display', 'iter', 'UseParallel', true);

% Run the Genetic Algorithm optimization
[x_opt, fval] = ga(@cost_fun, 9, [], [], [], [], lb, ub, [], options);

% Display the optimized values and final cost
disp('Optimized PID and gain values:');
disp(x_opt);
disp('Final cost:');
disp(fval);