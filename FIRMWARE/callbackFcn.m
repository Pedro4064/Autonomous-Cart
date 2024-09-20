function callbackFcn(src, ~, motors_plots, line_plots, battery_plots, imu_plots)
    % Parse transmitted data
    transmitted_data = read(src, 16, "single");
    
    left_motor_rpm  = transmitted_data(3);
    right_motor_rpm = transmitted_data(4);
    battery_charge  = transmitted_data(5);
    imu_data        = transmitted_data(6:11);
    line_data       = typecast(single(transmitted_data(12:end)), "uint32");

    % Update time for x-axis
    motors_plots{1}.YData = [motors_plots{1}.YData(2:end), left_motor_rpm];
    motors_plots{2}.YData = [motors_plots{2}.YData(2:end), right_motor_rpm];

    line_plots{1}.YData = [line_plots{1}.YData(2:end), line_data(1)];
    line_plots{2}.YData = [line_plots{2}.YData(2:end), line_data(2)];
    line_plots{3}.YData = [line_plots{3}.YData(2:end), line_data(3)];
    line_plots{4}.YData = [line_plots{4}.YData(2:end), line_data(4)];
    line_plots{5}.YData = [line_plots{5}.YData(2:end), line_data(5)];

    battery_plots{1}.YData = [battery_plots{1}.YData(2:end), battery_charge(1)];

    imu_plots{1}.YData = [imu_plots{1}.YData(2:end), imu_data(1)];
    imu_plots{2}.YData = [imu_plots{2}.YData(2:end), imu_data(2)];
    imu_plots{3}.YData = [imu_plots{3}.YData(2:end), imu_data(3)];
    imu_plots{4}.YData = [imu_plots{4}.YData(2:end), imu_data(4)];
    imu_plots{5}.YData = [imu_plots{5}.YData(2:end), imu_data(5)];   

    drawnow();
end
