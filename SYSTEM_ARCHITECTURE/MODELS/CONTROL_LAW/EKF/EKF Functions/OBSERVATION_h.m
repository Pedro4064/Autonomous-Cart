function z = OBSERVATION_h(x)
%OBSERVATION_h Function responsible to transform the states of
%the system into the measured value.
%
% The kinematic model has the following states:
% 
%     [ x_hat          ]
%     [ x_dot_hat      ]
%     [ x_ddot_hat     ]
% x = [ y_hat          ]
%     [ y_dot_hat      ]
%     [ y_ddot_hat     ]
%     [ theta_hat      ]
%     [ theta_dot_hat  ]
%
% where:
%   - x_hat         : Estimated position in the x-direction
%   - x_dot_hat     : Estimated velocity in the x-direction
%   - x_ddot_hat    : Estimated acceleration in the x-direction
%   - y_hat         : Estimated position in the y-direction
%   - y_dot_hat     : Estimated velocity in the y-direction
%   - y_ddot_hat    : Estimated acceleration in the x-direction
%   - theta_hat     : Estimated orientation angle
%   - theta_dot_hat : Estimated angular velocity
%
% And the available measurements are:
% z_k = [ ddot_x_robot  ]
%       [ dot_theta     ]
%
% The matrix h is given by:
%
% h = [ 0     0     cos(theta)   0         0    sin(theta)    0 0]
%     [ 0     0     0            0         0        0         0 1]
%
% where:
%   - ddot_x_robot : Acceleration of the robot in the x-direction
%   - dot_theta    : Rate of change of the orientation angle theta
%
% This function is responsible for representing h of ddot_x_body, which is
% the transformation from the robot's frame to the world frame, and all its
% resulting states.

    z = [
            x(3).*cos(x(7)) + x(6).*sin(x(7));
            x(8)
        ];

end

