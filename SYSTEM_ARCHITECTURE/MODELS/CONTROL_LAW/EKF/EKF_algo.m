function x = EKF_algo(z,u, R, Q)
    persistent P_posteriori;   %Pn,n
    persistent P_priori;       %Pn+1,n
    persistent x_hat_posteriori;%x_hat_n,n
    persistent x_hat_priori;    %x_hat_n+1,n

    %Chute inicial
    if isempty(x_hat_priori)
        x_hat_priori = zeros(8,1);
        x_hat_posteriori = zeros(8,1);
        P_posteriori = eye(8)*0.1;
        P_priori = zeros(8);

        % Initial Prediction
        F = A_Jacobian(x_hat_posteriori,u);

        x_hat_priori = DifferentialRobotModel(x_hat_posteriori ,u);
        P_priori = F*P_posteriori*F' + Q;

        x = x_hat_posteriori;
        return;
    end

    %Measure
    H = H_jacobian(x_hat_priori);
    K = P_priori*H' * inv(H*P_priori*H' + R);

    %Estimate
    h = OBSERVATION_h(x_hat_priori);
    x_hat_posteriori = x_hat_priori + K*(z - h);
    P_posteriori = (eye(8) - K*H) * P_priori* (eye(8) - K*H)' + K*R*K';

    %Predict
    F = A_Jacobian(x_hat_posteriori,u);

    x_hat_priori = DifferentialRobotModel(x_hat_posteriori ,u);
    P_priori = F*P_posteriori*F' + Q;


    %Return
    x = x_hat_posteriori;

end