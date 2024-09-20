clc; clear;

data_analysis_window = figure();
tiledlayout('flow');

nexttile(1);
axes_motors = gca;
motors_plots = cell(1,2);
motors_plots{1} = plot(zeros(1, 100),'r-','parent',axes_motors), hold(axes_motors, 'on');
motors_plots{2} = plot(zeros(1, 100),'g-','parent',axes_motors);



nexttile(2);
axes_line = gca;
line_plots = cell(1,5);
line_plots{1} = plot(zeros(1, 100),'r-','parent',axes_line), hold(axes_line, 'on');
line_plots{2} = plot(zeros(1, 100),'g-','parent',axes_line);
line_plots{3} = plot(zeros(1, 100), 'b-','parent',axes_line);
line_plots{4} = plot(zeros(1, 100),'k-','parent',axes_line), 
line_plots{5} = plot(zeros(1, 100),'k-','parent',axes_line), hold(axes_line, 'off');

nexttile(3);
axes_battery = gca;
battery_plots = cell(1,1);
battery_plots{1} = plot(zeros(1, 100),'r-','parent',axes_battery);

nexttile([2, 3]);  
axes_imu = gca;
imu_plots = cell(1, 6);
imu_plots{1} = plot(zeros(1, 100),'r-','parent',axes_imu), hold(axes_imu, 'on');
imu_plots{2} = plot(zeros(1, 100),'g-','parent',axes_imu);
imu_plots{3} = plot(zeros(1, 100), 'b-','parent',axes_imu);
imu_plots{4} = plot(zeros(1, 100),'k-','parent',axes_imu), 
imu_plots{5} = plot(zeros(1, 100),'k-','parent',axes_imu), 
imu_plots{6} = plot(zeros(1, 100),'k-','parent',axes_imu), hold(axes_imu, 'off');



serial_connection = serialport("COM3", 115200);
configureCallback(serial_connection,"byte",64,@(src, event) callbackFcn(src, event, motors_plots, line_plots, battery_plots, imu_plots));
