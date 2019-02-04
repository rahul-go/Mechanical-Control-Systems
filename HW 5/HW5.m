%% ME 422 HW 5
% Rahul Goyal
%
% January 30, 2019

% Reset
clc;
clear all;
close all;

%% Problem 1
% System Stability using Hurwitz Criteria

% Part A
figure;
sim('HW5_1A');
plot(tout, simout, 'LineWidth', 2);
title('System Stability using Hurwitz Criteria, Part A');
xlabel({'Time (s)'
        ''
        % Figure label
        '\bfFigure 1: \rmSystem Stability using Hurwitz Criteria, Part A'});
ylabel('Response (units)');

% Part B
figure;
sim('HW5_1B');
plot(tout, simout, 'LineWidth', 2);
title('System Stability using Hurwitz Criteria, Part B');
xlabel({'Time (s)'
        ''
        % Figure label
        '\bfFigure 2: \rmSystem Stability using Hurwitz Criteria, Part B'});
ylabel('Response (units)');

% Part C
figure;
sim('HW5_1C');
plot(tout, simout, 'LineWidth', 2);
title('System Stability using Hurwitz Criteria, Part C');
xlabel({'Time (s)'
        ''
        % Figure label
        '\bfFigure 3: \rmSystem Stability using Hurwitz Criteria, Part C'});
ylabel('Response (units)');