function y_ddot_x_body = OBSERVATION_x_ddot_body(x)
%OBSERVATION_X_DDOT_BODY Function responsible to transform the states of
%the system into the measured value.
%
% The kinematic model has the following states:
% 
%     [ x_hat         ]
%     [ x_dot_hat     ]
% x = [ y_hat         ]
%     [ y_dot_hat     ]
%     [ theta_hat     ]
%     [ theta_dot_hat ]
%
% where:
%   - x_hat         : Estimated position in the x-direction
%   - x_dot_hat     : Estimated velocity in the x-direction
%   - y_hat         : Estimated position in the y-direction
%   - y_dot_hat     : Estimated velocity in the y-direction
%   - theta_hat     : Estimated orientation angle
%   - theta_dot_hat : Estimated angular velocity
%
% And the available measurements are:
% z_k = [ ddot_x_robot  ]
%       [ dot_theta     ]
%
% The matrix h is given by:
%
% h = [ (T^2*cos(theta))^(-1)  (T*cos(theta))^(-1)  (T^2*sin(theta))^(-1)  (T*sin(theta))^(-1)  0  0 ]
%     [ 0                      0                      0                      0                  0  1 ]
%
% where:
%   - ddot_x_robot : Acceleration of the robot in the x-direction
%   - dot_theta    : Rate of change of the orientation angle theta
%
% This function is responsible for representing h of ddot_x_body, which is
% the transformation from the robot's frame to the world frame, and all its
% resulting states.
%
% This model also requires the Ts variable (the sampling period), r (the radious
% of the wheel), and L (distance between wheels) to be loaded into the workspace!!

y_ddot_x_body = (Ts.^2 .* cos(x(5))).^-1 + (Ts .* cos(x(5))).^-1 + (Ts.^2 .* sin(x(5))).^-1 + (Ts .* sin(x(5))).^-1;
end

