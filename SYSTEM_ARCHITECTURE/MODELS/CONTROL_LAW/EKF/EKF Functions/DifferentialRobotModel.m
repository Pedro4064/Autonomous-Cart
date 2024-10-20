function x = DifferentialRobotModel(x, u)
%DIFFERENTIALROBOTMODEL Kinematic model of a differential drive robot
% The kinematic model has the following parameters:
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
% Furthermore, it has the following inputs:
% u =    [ phi_dot_hat_L ]
%        [ phi_dot_hat_R ]
%
% where:
%   - phi_dot_hat_L : Estimated rate of change of angle (angular velocity) phi for the left side
%   - phi_dot_hat_R : Estimated rate of change of angle (angular velocity) phi for the right side
%
% This model also requires the Ts variable (the sampling period), r (the radious
% of the wheel), and L (distance between wheels) to be loaded into the workspace!!

    Ts = 0.1;
    r = 0.035;
    L = 0.1;
    
    x = [(x(1) + x(2).*Ts + 0.5*x(3)*Ts^2);
         (r./2).*cos(x(7)).*(u(1) + u(2));
         x(3);
         x(4) + x(5).*Ts + 0.5*x(6)*Ts^2;
         (r./2).*sin(x(7)).*(u(1) + u(2));
         x(6);
         x(7) + x(8).*Ts;
         (r./L) .* (u(2) - u(1))
        ];
    % x_new = [0.0 0.0 0.0 0.0 0.0 0.0];
    % x_new(1) = x(1) + x(2).*Ts;
    % x_new(2) = (r./2).*cos(x(5)).*(u(1) + u(2));
    % x_new(3) = x(3) + x(4).*Ts;
    % x_new(4) = (r./2).*sin(x(5)).*(u(1) + u(2));
    % x_new(5) = x(5) + x(6).*Ts;
    % x_new(6) = (r./L) .* (u(2) - u(1));
end

