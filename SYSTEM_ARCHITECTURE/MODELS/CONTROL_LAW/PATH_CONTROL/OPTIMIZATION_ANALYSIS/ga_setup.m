%% Load Constants and Maps Data %%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

load track_map.mat

global track_map cost_map;




%% Define Bounds for Optimization %%%%%%%%
% All PID values must be greater than zero
%but the k gains may be less than zero.
% Furthermore, set an upper bound of 1000
%of all variables.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

lb = zeros(1, 6);        % Lower bounds (0 for each parameter)
ub = ones(1, 6) * 10;    % Upper bounds (for example, you can adjust as needed)

%% Configure and Run Optimization %%%%%%%%%
% Configure to use parallel in multi core
%systems, and display iterations.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
options = optimoptions('ga', 'Display', 'iter', 'PopulationSize',100, 'PlotFcn','gaplotbestf');%, 'UseParallel', true);

% Run the Genetic Algorithm optimization
%[x_opt, fval, exit_flag, output, population, cores] = ga(@cost_fun, 9, [], [], [], [], lb, ub, [], options);
[x_opt, fval, exit_flag, output, population, cores] = ga(@cost_fun, 6, [], [], [], [], lb, ub, [], options);

% Display the optimized values and final cost
disp('Optimized PID values:');
disp(x_opt);
disp('Final cost:');
disp(fval);