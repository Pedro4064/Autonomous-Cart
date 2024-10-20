function y_dot_theta = OBSERVATION_theta_dot(x)
%OBSERVATION_THETA_DOT Summary of this function goes here
%   Detailed explanation goes here
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
% This function is responsible for representing h of ddot_theta.
y_dot_theta = x(6);
end

