r = 3.5e-2;   % Radius of the wheel [m]
L = 10e-2;    % Distance between wheels [m]

Ts = 1/10;                           % Sampling Rate of system
theta_0 = deg2rad(0);                % Initial Theta value
states_0 = [0 0 0 0 0 0 theta_0 0];

R = eye(2)*10;
Q = eye(8)*0.1;