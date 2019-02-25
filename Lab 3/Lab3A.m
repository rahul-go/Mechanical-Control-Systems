%% ME 422 Lab 3A
% Tristan Faulkner
%
% Rahul Goyal
%
% February 19, 2019

% Reset
clc;
clear all;
close all;



%% Data

figure;
load('Two Tank/StepResponse1');
plot(TwoTank(:, 1), TwoTank(:, 2), TwoTank(:, 1), TwoTank(:, 3), 'LineWidth', 2);
figure;
load('Two Tank/StepResponse2');
plot(TwoTank(:, 1), TwoTank(:, 2), TwoTank(:, 1), TwoTank(:, 3), 'LineWidth', 2);
figure;
load('Two Tank/StepResponse3');
plot(TwoTank(:, 1), TwoTank(:, 2), TwoTank(:, 1), TwoTank(:, 3), 'LineWidth', 2);
figure;
load('Two Tank/Disturbance');
plot(TwoTank(:, 1), TwoTank(:, 2), TwoTank(:, 1), TwoTank(:, 3), 'LineWidth', 2);

figure;
load('Two Tank/StepResponse1');
plot(smooth(TwoTank(:, 1), 10), smooth(TwoTank(:, 2), 10), ...
     smooth(TwoTank(:, 1), 10), smooth(TwoTank(:, 3), 10), 'LineWidth', 2);
figure;
load('Two Tank/StepResponse2');
plot(smooth(TwoTank(:, 1), 10), smooth(TwoTank(:, 2), 10), ...
     smooth(TwoTank(:, 1), 10), smooth(TwoTank(:, 3), 10), 'LineWidth', 2);
figure;
load('Two Tank/StepResponse3');
plot(smooth(TwoTank(:, 1), 10), smooth(TwoTank(:, 2), 10), ...
     smooth(TwoTank(:, 1), 10), smooth(TwoTank(:, 3), 10), 'LineWidth', 2);
figure;
load('Two Tank/Disturbance');
plot(smooth(TwoTank(:, 1), 10), smooth(TwoTank(:, 2), 10), ...
     smooth(TwoTank(:, 1), 10), smooth(TwoTank(:, 3), 10), 'LineWidth', 2);



%% Experimental and Simulated Data

load('Two Tank/StepResponse2');
sim('Lab3ASimulinkOpenLoop')

% Top Tank
figure;
hold on;
plot(TwoTank(:, 1), TwoTank(:, 2), 'LineWidth', 2);
plot(tout, simout, 'LineWidth', 4);
title('Top Tank Height, Experimental and Simulated Data');
xlabel({'Time (s)'
        ''
        % Figure label
        '\bfFigure 1: \rmTop Tank Height, Experimental and Simulated Data'});
ylabel('Height (in)');
legend('Experimental', 'Simulated', 'Location', 'northwest');
xlim([0, 600]);

% Bottom Tank
figure;
hold on;
plot(TwoTank(:, 1), TwoTank(:, 3), 'LineWidth', 2);
plot(tout, simout1, 'LineWidth', 4);
title('Bottom Tank Height, Experimental and Simulated Data');
xlabel({'Time (s)'
        ''
        % Figure label
        '\bfFigure 2: \rmBottom Tank Height, Experimental and Simulated Data'});
ylabel('Height (in)');
legend('Experimental', 'Simulated', 'Location', 'northwest');
xlim([0, 600]);



%% Closed-Loop Proportional Controller Simulation

figure;
sim('Lab3ASimulinkClosedLoop')
plot(tout, simout, 'LineWidth', 2);
title('Closed-Loop Proportional Controller Simulation');
xlabel({'Time (s)'
        ''
        % Figure label
        '\bfFigure 3: \rmClosed-Loop Proportional Controller Simulation'});
ylabel('Height (in)');



%% Closed-Loop Proportional Controller Disturbance Simulation

figure;
sim('Lab3ASimulinkClosedLoopDisturbance')

% Top Tank
subplot(2, 1, 1);                       % 2 rows, one column, first graph
plot(tout, simout, 'LineWidth', 2);
title('Top Tank');
xlabel('Time (s)');
ylabel('Height (in)');

% Bottom Tank
subplot(2, 1, 2);                       % 2 rows, one column, second graph
plot(tout, simout1, 'LineWidth', 2);
title('Bottom Tank');
xlabel({'Time (s)'
        ''
        % Figure label
        '\bfFigure 4: \rmClosed-Loop Proportional Controller Disturbance Simulation'});
ylabel('Height (in)');



%% Root Locus
figure;
G_OL = zpk([], [-120, -60], 3.57);
rlocus(G_OL)