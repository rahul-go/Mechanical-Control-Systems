%% ME 422 Lab 2A
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
title('Closed-Loop Motomatic Response Simulation');
xlabel({'Time (s)'
        ''
        % Figure label
        '\bfFigure 1: \rmClosed-Loop Motomatic Step Response'});
ylabel('Response (deg)');
legend('Experimental Data', 'Linear Simulation', ...
       'Nonlinear Simulation', 'Nonlinear Simulation, Tuned', ...
       'Location', 'southeast');
xlim([0, 4]);



%% Open-Loop Step Response

figure;
hold on;

% Experimental Data
load('MotoMatic/stepresponse.mat');
plot(MotoOpenLoop(:, 1)-0.53, (MotoOpenLoop(:, 2)-0.1514)*40, 'LineWidth', 2);
% Linear Simulation
sim('OpenLoopLinear');
plot(tout, simout, 'LineWidth', 2);
% Nonlinear Simulation
sim('OpenLoopNonlinear');
plot(tout, simout, 'LineWidth', 2);
% Plot labeling
title('Experimental Step Response');
xlabel({'Time (s)'
        ''
        % Figure label
        '\bfFigure 2: \rmOpen-Loop Motomatic Step Response'});
ylabel('Response (deg)');
legend('Experimental Data', 'Linear Simulation', ...
       'Nonlinear Simulation', 'Location', 'southeast')
xlim([0, 4]);