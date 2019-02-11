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



%% Plot

figure;
hold on;
% Nonlinear Tuned
sim('ClosedLoopNonlinearTuned');
plot(tout, simout, 'LineWidth', 2);
% Plot labeling
title('Closed-Loop Motomatic Response Simulation, Nonlinear Tuned');
xlabel({'Time (s)'
        ''
        % Figure label
        '\bfFigure 1: \rmClosed-Loop Motomatic Response Simulation, Nonlinear Tuned'});
ylabel('Response (deg)');
xlim([1, 5]);