%% ME 422 Lab 3A
% Tristan Faulkner
%
% Rahul Goyal
%
% February 25, 2019

% Reset
clc;
clear all;
close all;



%% Experimental and Simulated Data

% P-Only Controller
figure;
load('Two Tank/POnlyController');
sim('Lab3BSimulinkPOnly')

% Top Tank
subplot(2, 1, 1);                       % 2 rows, one column, first graph
hold on;
plot(TwoTank(:, 1), TwoTank(:, 2), 'LineWidth', 2);
plot(tout, simout, 'LineWidth', 3);
title('Top Tank Height, Experimental and Simulated Data, P-Only Controller');
xlabel('Time (s)');
ylabel('Height (in)');
legend('Experimental', 'Simulated', 'Location', 'southeast');
xlim([0, 600]);

% Bottom Tank
subplot(2, 1, 2);                       % 2 rows, one column, second graph
hold on;
plot(TwoTank(:, 1), TwoTank(:, 3), 'LineWidth', 2);
plot(tout, simout1, 'LineWidth', 3);
title('Bottom Tank Height, Experimental and Simulated Data, P-Only Controller');
xlabel({'Time (s)'
        ''
        % Figure label
        '\bfFigure 1: \rmExperimental and Simulated Data, P-Only Controller'});
ylabel('Height (in)');
legend('Experimental', 'Simulated', 'Location', 'southeast');
xlim([0, 600]);



% PI Controller
figure;
load('Two Tank/PIController');
sim('Lab3BSimulinkPI')

% Top Tank
subplot(2, 1, 1);                       % 2 rows, one column, first graph
hold on;
plot(TwoTank(:, 1), TwoTank(:, 2), 'LineWidth', 2);
plot(tout, simout, 'LineWidth', 3);
title('Top Tank Height, Experimental and Simulated Data, PI Controller');
xlabel('Time (s)');
ylabel('Height (in)');
legend('Experimental', 'Simulated', 'Location', 'southeast');
xlim([0, 600]);

% Bottom Tank
subplot(2, 1, 2);                       % 2 rows, one column, second graph
hold on;
plot(TwoTank(:, 1), TwoTank(:, 3), 'LineWidth', 2);
plot(tout, simout1, 'LineWidth', 3);
title('Bottom Tank Height, Experimental and Simulated Data, PI Controller');
xlabel({'Time (s)'
        ''
        % Figure label
        '\bfFigure 2: \rmExperimental and Simulated Data, PI Controller'});
ylabel('Height (in)');
legend('Experimental', 'Simulated', 'Location', 'southeast');
xlim([0, 600]);



% PD Controller
figure;
load('Two Tank/PDController');
sim('Lab3BSimulinkPD')

% Top Tank
subplot(2, 1, 1);                       % 2 rows, one column, first graph
hold on;
plot(TwoTank(:, 1), TwoTank(:, 2), 'LineWidth', 2);
plot(tout, simout, 'LineWidth', 3);
title('Top Tank Height, Experimental and Simulated Data, PD Controller');
xlabel('Time (s)');
ylabel('Height (in)');
legend('Experimental', 'Simulated', 'Location', 'southeast');
xlim([0, 600]);

% Bottom Tank
subplot(2, 1, 2);                       % 2 rows, one column, second graph
hold on;
plot(TwoTank(:, 1), TwoTank(:, 3), 'LineWidth', 2);
plot(tout, simout1, 'LineWidth', 3);
title('Bottom Tank Height, Experimental and Simulated Data, PD Controller');
xlabel({'Time (s)'
        ''
        % Figure label
        '\bfFigure 3: \rmExperimental and Simulated Data, PD Controller'});
ylabel('Height (in)');
legend('Experimental', 'Simulated', 'Location', 'southeast');
xlim([0, 600]);



%% Root Locus
figure;
G_OL = zpk([], [-120, 0], 3.57);
rlocus(G_OL)