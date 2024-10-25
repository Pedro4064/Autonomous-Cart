clc; clear;

n_points = 50;
data_analysis_window = figure();
tiledlayout('flow');

nexttile(1);
axes_motors = gca;
motors_plots = cell(1,2);

motors_plots{1} = plot(zeros(1, n_points),'r-','parent',axes_motors), hold(axes_motors, 'on');
motors_plots{2} = plot(zeros(1, n_points),'g-','parent',axes_motors);
ylim([0 80]);
title('RPM - Motores');



nexttile(2);
axes_line = gca;
line_plots = cell(1,5);
line_plots{1} = plot(zeros(1, n_points),'r-','parent',axes_line), hold(axes_line, 'on');
line_plots{2} = plot(zeros(1, n_points),'g-','parent',axes_line);
line_plots{3} = plot(zeros(1, n_points), 'b-','parent',axes_line);
line_plots{4} = plot(zeros(1, n_points),'k-','parent',axes_line), 
line_plots{5} = plot(zeros(1, n_points),'m-','parent',axes_line), hold(axes_line, 'off');
title('Sensores de Linha');
% legend('Sen. 1', 'Sen. 2', 'Sen. 3', 'Sen. 4', 'Sen. 5');

nexttile(3);
axes_battery = gca;
battery_plots = cell(1,1);
battery_plots{1} = plot(zeros(1, n_points),'r-','parent',axes_battery);
title('Sensoriamento - Bateria');

nexttile([2, 3]);  
axes_imu = gca;
imu_plots = cell(1, 6);
yyaxis left;
imu_plots{1} = plot(zeros(1, n_points),'Color', 'm', 'LineStyle', '-', 'LineWidth', 2.0 ,'parent',axes_imu), hold(axes_imu, 'on');
imu_plots{2} = plot(zeros(1, n_points),'Color', 'g', 'LineStyle', '-', 'LineWidth', 2.0 ,'parent',axes_imu);
imu_plots{3} = plot(zeros(1, n_points), 'Color', 'b',  'LineStyle', '-', 'LineWidth', 2.0 ,'parent',axes_imu);
ylim([-3 3]);

yyaxis right;
imu_plots{4} = plot(zeros(1, n_points),'Color', 'm', 'LineStyle', '--', 'LineWidth', 2.0 ,'parent',axes_imu), 
imu_plots{5} = plot(zeros(1, n_points),'Color', 'g', 'LineStyle', '--', 'LineWidth', 2.0 ,'parent',axes_imu), 
imu_plots{6} = plot(zeros(1, n_points),'Color', 'b', 'LineStyle', '--', 'LineWidth', 2.0 ,'parent',axes_imu), hold(axes_imu, 'off');
ylim([-300 300]);
title('IMU - MPU6050');
% legend('Acc. X', 'Acc. Y', 'Acc. Z', 'Gyr. X', 'Gyr. Y', 'Gyr. Z');



serial_connection = serialport("COM3", 115200);
configureCallback(serial_connection,"byte",84,@(src, event) callbackFcn(src, event, motors_plots, line_plots, battery_plots, imu_plots));
