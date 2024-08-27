%% Create custum data type definitions for Firmware Architecture%%%%%%%%%%%
% As to keep the architecture models more faithfull to the implementation,
% custum data types are necessay. For mode information Regarding Matlab's
% documentation on how to do it: 
% https://www.mathworks.com/help/systemcomposer/ref/simulink.dictionary.architecturaldata.html
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

data_dictionary = "data_definitions.sldd";
arch_data_obj = Simulink.dictionary.archdata.open(data_dictionary);

%% Custom Data Types %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Add datatypes for custom structs definitions, enums and any other type
% that may be used in the implementation of the firmware for the project.
% Keep in mind that if any custom data types are created here, it may also
% be of interest to create the corresponding pointer data type (in the next
% code block)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Enum for which motor to use
motor_enum = addEnumType(arch_data_obj, "Motor");
motor_enum.addEnumeral("LEFT_MOTOR", "0", "Left Motor");
motor_enum.addEnumeral("RIGHT_MOTOR", "1", "Right Motor");

% Enum for Motor spin direction
motor_spin_enum = addEnumType(arch_data_obj, "MotorSpin");
motor_spin_enum.addEnumeral("CLOCKWISE", "0", "Clock-whise direction");
motor_spin_enum.addEnumeral("COUNTER_CLOCKWISE", "1", "Counter clock-wise direction");

% Motor Commands
motor_commands = addStructType(arch_data_obj, "MotorCommands");

left_motor_dir = motor_commands.addElement("xLeftMotorSpinDirection");
left_motor_dir.Type.DataType = 'MotorSpin';

right_motor_dir = motor_commands.addElement("xRightMotorSpinDirection");
right_motor_dir.Type.DataType = 'MotorSpin';

left_motor_speed = motor_commands.addElement("fLeftMotorSpeed");
left_motor_speed.Type.DataType = 'float';

right_motor_speed = motor_commands.addElement("fRightMotorSpeed");
right_motor_speed.Type.DataType = 'float';

% IMU Readings
imu_readings = addStructType(arch_data_obj, "ImuReadings");

x_accel = imu_readings.addElement("fAccelX");
x_accel.Type.DataType = 'float';

y_accel = imu_readings.addElement("fAccelY");
y_accel.Type.DataType = 'float';

z_accel = imu_readings.addElement("fAccelz");
z_accel.Type.DataType = 'float';

x_gyro = imu_readings.addElement("fGyroX");
x_gyro.Type.DataType = 'float';

y_gyro = imu_readings.addElement("fGyroY");
y_gyro.Type.DataType = 'float';

z_gyro = imu_readings.addElement("fGyroz");
z_gyro.Type.DataType = 'float';


% Telemetry Data
telemetry_data = addStructType(arch_data_obj, "TelemetryData");

imu_data = telemetry_data.addElement("xTelemetryData");
imu_data.Type.DataType = 'ImuReadings';

line_sensors = telemetry_data.addElement("fLineSensorsData");
line_sensors.Type.DataType = 'float';
line_sensors.Type.Dimensions = '5';

ultrassonic_sensor = telemetry_data.addElement("fUltrassonicDistanceData");
ultrassonic_sensor.Type.DataType = 'float';

infrared_dist_sensor = telemetry_data.addElement("fInfraredDistanceData");
infrared_dist_sensor.Type.DataType = 'float';

bat_sensor = telemetry_data.addElement("fBatteryChargeData");
bat_sensor.Type.DataType = 'float';

left_encoder = telemetry_data.addElement("fLeftMotorCount");
left_encoder.Type.DataType = 'uint32';

right_encoder = telemetry_data.addElement("fRightMotorCount");
right_encoder.Type.DataType = 'uint32';

% State Estimate Strcut Definition
state_estimation = addStructType(arch_data_obj, "StateEstimate");

total_distance = state_estimation.addElement("fTotalDistance");
total_distance.Type.DataType = 'float';

current_speed = state_estimation.addElement("fCurrentSpeed");
current_speed.Type.DataType = 'float';

avg_speed = state_estimation.addElement("fAverageSpeed");
avg_speed.Type.DataType = 'float';

current_rot_speed = state_estimation.addElement("fCurrentRotationalSpeed");
current_rot_speed.Type.DataType = 'float';

current_orientation = state_estimation.addElement("fCurrentOrientation");
current_orientation.Type.DataType = 'float';

%% Pointer Data Types %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Add datatypes for pointer parameters. The strategy that will be used is
% to have a struct as each pointer type containing two fields, the data and
% the memorry address, so any logic of verifying if pointer not null and
% data assignment will be possible to simulate.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Pointer to an INT on a 32 bit system definition
int_pointer = addStructType(arch_data_obj, "intPointer");

int_pointer_mem = int_pointer.addElement("mem_add");
int_pointer_mem.Type.DataType = 'fixdt(1,8)';             % Size of Pointer

int_pointer_val = int_pointer.addElement("val");
int_pointer_val.Type.DataType = 'int32';
int_pointer_val.Type.Dimensions = '1';

% Pointer to a float on a 32 bit system defintion
float_pointer = addStructType(arch_data_obj, "floatPointer");

float_pointer_mem = float_pointer.addElement("mem_add");
float_pointer_mem.Type.DataType = 'fixdt(1,8)';

float_pointer_val = float_pointer.addElement("val");
float_pointer_val.Type.DataType = 'float';
float_pointer_val.Type.Dimensions = '1';

% Pointer to Motor Commands Struct
motor_commands_pointer = addStructType(arch_data_obj, "MotorCommandsPointer");

motor_commands_pointer_mem = motor_commands_pointer.addElement("mem_add");
motor_commands_pointer_mem.Type.DataType = 'fixdt(1,8)';

motor_commands_pointer_val = motor_commands_pointer.addElement("val");
motor_commands_pointer_val.Type.DataType = 'MotorCommands';
motor_commands_pointer_val.Type.Dimensions = '1';

% Pointer to IMU Readings Struct
imu_readings_pointer = addStructType(arch_data_obj, "ImuReadingsPointer");

imu_readings_pointer_mem = imu_readings_pointer.addElement("mem_add");
imu_readings_pointer_mem.Type.DataType = 'fixdt(1,8)';

imu_readings_pointer_val = imu_readings_pointer.addElement("val");
imu_readings_pointer_val.Type.DataType = 'ImuReadings';
imu_readings_pointer_val.Type.Dimensions = '1';

% Pointer to Telemetry Data Struct
telemetry_data_pointer = addStructType(arch_data_obj, "TelemetryDataPointer");

telemetry_data_pointer_mem = telemetry_data_pointer.addElement("mem_add");
telemetry_data_pointer_mem.Type.DataType = 'fixdt(1,8)';

telemetry_data_pointer_val = telemetry_data_pointer.addElement("val");
telemetry_data_pointer_val.Type.DataType = 'TelemetryData';
telemetry_data_pointer_val.Type.Dimensions = '1';

% Pointer to void function with no arguments
void_function_pointer = addAliasType(arch_data_obj,'VoidFunctionPointer',BaseType="function_handle");


% Pointer to State Estimation Struct
state_estimate_pointer = addStructType(arch_data_obj, "StateEstimatePointer");

state_estimate_pointer_mem = state_estimate_pointer.addElement("mem_add");
state_estimate_pointer_mem.Type.DataType = 'fixdt(1,8)';

state_estimate_pointer_val = state_estimate_pointer.addElement("val");
state_estimate_pointer_val.Type.DataType = 'StateEstimate';
state_estimate_pointer_val.Type.Dimensions = '1';

%% Save custum data type definitions for Firmware Architecture  %%%%%%%%%%%
% Save the changes made to the data dictionary to be used in the model
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

save(arch_data_obj);