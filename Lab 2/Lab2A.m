%% ME 422 Lab 2A
% Rahul Goyal
%
% Jake Rogers
%
% February 04, 2019

% Reset
clc;
clear all;
close all;



%% Plot

figure;
hold on;
% Linear
sim('ClosedLoopLinear');
plot(tout, simout, 'LineWidth', 2);
% Nonlinear
sim('ClosedLoopNonlinear');
plot(tout, simout, 'LineWidth', 2);
% Plot labeling
title('Closed-Loop Motomatic Response Simulation, Linear vs. Nonlinear');
xlabel({'Time (s)'
        ''
        % Figure label
        '\bfFigure 1: \rmClosed-Loop Motomatic Response Simulation, Linear vs. Nonlinear'});
ylabel('Response (deg)');
legend('Closed Loop Linear', 'Closed Loop Nonlinear');
xlim([1, 5]);