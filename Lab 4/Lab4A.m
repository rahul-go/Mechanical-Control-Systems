%% ME 422 Lab 4A
% Rahul Goyal
% 
% Keyanna Henderson
%
% March 04, 2019

% Reset
clc;
clear all;
close all;



%% Step Response Plot

figure;
sim('Lab4SimulinkStep')
plot(tout, simout, 'LineWidth', 2);
title('Step Response Plot, Kp = 82');
xlabel({'Time (s)'
        ''
        % Figure label
        '\bfFigure 1: \rmStep Response Plot, Kp = 82'});
ylabel('Height (in)');
xlim([0.8, 2]);



%% Ramp Response Plot

figure;
sim('Lab4SimulinkRamp')
plot(tout, simout, 'LineWidth', 2);
title('Ramp Response Plot, Kp = 82');
xlabel({'Time (s)'
        ''
        % Figure label
        '\bfFigure 2: \rmRamp Response Plot, Kp = 82'});
ylabel('Height (in)');