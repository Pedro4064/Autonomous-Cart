% Initialize Serial COM
clc; clear;
serial_connection = serialport("COM4", 115200);

% Initialize figure with desired layout
figure;

% Define subplot layout: 2 rows, 3 columns
tiledlayout('flow'); 

% First subplot: RPM for two motors
nexttile(1);  % First tile in the grid (top left)
hMotor(1) = animatedline('Color', 'r'); % Left motor (red)
hMotorAxis(1) = gca;

hMotor(2) = animatedline('Color', 'b'); % Right motor (blue)
hMotorAxis(2) = gca;
title('RPM Motores');
legend('Left Motor', 'Right Motor');

% Second subplot: Line sensors (5 sensors)
nexttile(2);  % Second tile (top center)
colors = lines(5);  % Generate distinct colors for each line sensor
for i = 1:5
    hLine(i) = animatedline('Color', colors(i, :));  % Set a different color for each sensor
    hLineAxis(i) = gca;
end
title('Sensores de Linha');
legend('Sensor 1', 'Sensor 2', 'Sensor 3', 'Sensor 4', 'Sensor 5');

% Third subplot: Battery charge (single line)
nexttile(3);  % Third tile (top right)
hBattery = animatedline('Color', 'g');   % Battery plot (green)
hBatteryAxis = gca;
title('Bateria');
legend('Battery Charge');

% Fourth subplot: IMU with dual y-axis
nexttile([2, 3]);  % Large plot spanning the second row

% First three IMU values on left y-axis
yyaxis left;
hIMU1 = animatedline('Color', 'm');  % Color for the first three IMU values
hIMU2 = animatedline('Color', 'c');  % Color for the second IMU value
hIMU3 = animatedline('Color', 'k');  % Color for the third IMU value
title('IMU');
legend('IMU 1', 'IMU 2', 'IMU 3', 'Location', 'northeast');

% Last three IMU values on right y-axis
yyaxis right;
hIMU4 = animatedline('Color', 'g');  % Color for the fourth IMU value
hIMU5 = animatedline('Color', 'b');  % Color for the fifth IMU value
hIMU6 = animatedline('Color', 'r');  % Color for the sixth IMU value
legend('IMU 4', 'IMU 5', 'IMU 6', 'Location', 'northeastoutside');

% Main loop to update the plots in real-time
time = 0; % Initialize time (optional if you want to plot against time)
duration = 20; % Duration to display in seconds

while true
    % Read data from the serial connection
    transmitted_data = read(serial_connection, 16, "single");
    
    % Extract the transmitted data
    left_motor_rpm  = transmitted_data(3);
    right_motor_rpm = transmitted_data(4);
    battery_charge  = transmitted_data(5);
    imu_data        = transmitted_data(6:11);
    line_data       = typecast(single(transmitted_data(12:end)), "uint32");

    % Update time for x-axis
    time = time + 1;

    % Add new data points to the motor RPM plots
    addpoints(hMotor(1), time, left_motor_rpm);  % Left motor
    xlim(hMotorAxis(1), [time - duration, time]);

    addpoints(hMotor(2), time, right_motor_rpm); % Right motor
    xlim(hMotorAxis(2), [time - duration, time]);
    % Add new data points to the line sensor plots
    for i = 1:5
        addpoints(hLine(i), time, line_data(i));
        xlim(hLineAxis(i), [time - duration, time]);
    end

    % Add new data points to the battery plot
    addpoints(hBattery, time, battery_charge);
    xlim(hBatteryAxis, [time - duration, time]);

    % Update IMU data on the left y-axis
    yyaxis left;
    addpoints(hIMU1, time, imu_data(1));  % IMU 1
    addpoints(hIMU2, time, imu_data(2));  % IMU 2
    addpoints(hIMU3, time, imu_data(3));  % IMU 3

    % Update IMU data on the right y-axis
    yyaxis right;
    addpoints(hIMU4, time, imu_data(4));  % IMU 4
    addpoints(hIMU5, time, imu_data(5));  % IMU 5
    addpoints(hIMU6, time, imu_data(6));  % IMU 6

    % Set x-axis limits to show only the last 'duration' seconds
    xlim([time - duration, time]);

    % Update the plots in real time
    drawnow limitrate;  % Efficiently update the plots
end
