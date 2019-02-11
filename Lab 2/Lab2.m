%% ME 422 Lab 2
% Rahul Goyal
%
% Jake Rogers
%
% February 11, 2019

% Reset
clc;
clear all;
close all;



%% Closed-Loop, Experimental and Simulated (Linear, Nonlinear, Nonlinear Tuned)

figure;
hold on;

% Experimental Data
K_pot = 0.0851;
load('MotoMatic/stepresponse_rf5k.mat');
plot(MotoOpenLoop(:, 1)-1.18, MotoOpenLoop(:, 2)/K_pot, 'LineWidth', 2);
% Linear Simulation
sim('ClosedLoopLinear');
plot(tout, simout, 'LineWidth', 2);
% Nonlinear Simulation
sim('ClosedLoopNonlinear');
plot(tout, simout, 'LineWidth', 2);
% Nonlinear Simulation, Tuned
sim('ClosedLoopNonlinearTuned');
plot(tout, simout, 'LineWidth', 2);
% Plot labeling
title('Closed-Loop Motomatic Step Response');
xlabel({'Time (s)'
        ''
        % Figure label
        '\bfFigure 4: \rmClosed-Loop Motomatic Step Response'});
ylabel('Angular Position (deg)');
legend('Experimental Data', 'Linear Simulation', ...
       'Nonlinear Simulation', 'Nonlinear Simulation, Tuned', ...
       'Location', 'southeast');
xlim([0, 4]);



%% Open-Loop Step Response

figure;
hold on;

% Experimental Data
load('MotoMatic/stepresponse.mat');
plot(MotoOpenLoop(:, 1)-0.53, (MotoOpenLoop(:, 2)-0.1514)*60, 'LineWidth', 2);
% Linear Simulation
sim('OpenLoopLinear');
plot(tout, simout, 'LineWidth', 2);
% Nonlinear Simulation
sim('OpenLoopNonlinear');
plot(tout, simout, 'LineWidth', 2);
% Plot labeling
title('Open-Loop Motomatic Step Response');
xlabel({'Time (s)'
        ''
        % Figure label
        '\bfFigure 5: \rmOpen-Loop Motomatic Step Response'});
ylabel('Angular Velocity (deg/s)');
legend('Experimental Data', 'Linear Simulation', ...
       'Nonlinear Simulation', 'Location', 'southeast')
xlim([0, 4]);
ylim([0, 100]);

figure;
K_pot = 0.0851;

% Rf = 5k Ohms
load('MotoMatic/stepresponse_rf5k.mat');
subplot(3, 1, 1);                       % 3 rows, one column, first graph
plot(MotoOpenLoop(:, 1)-1.18, MotoOpenLoop(:, 2)/K_pot, 'LineWidth', 2);
% Plot labeling
title('Closed-Loop Motomatic Step Response, Rf = 5k Ohms');
xlabel('Time (s)');
ylabel('Angular Position (deg)');
xlim([0, 3]);

% Rf = 10k Ohms
load('MotoMatic/stepresponse_rf10k.mat');
subplot(3, 1, 2);                       % 3 rows, one column, second graph
plot(MotoOpenLoop(:, 1)-1.10, MotoOpenLoop(:, 2)/K_pot, 'LineWidth', 2);
% Plot labeling
title('Closed-Loop Motomatic Step Response, Rf = 10k Ohms');
xlabel('Time (s)');
ylabel('Angular Position (deg)');
xlim([0, 3]);

% Rf = 20k Ohms
load('MotoMatic/stepresponse_rf20k.mat');
subplot(3, 1, 3);                       % 3 rows, one column, third graph
plot(MotoOpenLoop(:, 1)-1.03, MotoOpenLoop(:, 2)/K_pot, 'LineWidth', 2);
% Plot labeling
title('Closed-Loop Motomatic Step Response, Rf = 20k Ohms');
xlabel({'Time (s)'
        ''
        % Figure label
        '\bfFigure 6: \rmClosed-Loop Motomatic Step Response, Rf = 20k Ohms'});
ylabel('Angular Position (deg)');
xlim([0, 3]);