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



%% Data

% P-only Controller
figure;
hold on;
load('Two Tank/POnlyController');
sim('Lab3BSimulinkPID')
plot(TwoTank(:, 1), TwoTank(:, 2), TwoTank(:, 1), TwoTank(:, 3), 'LineWidth', 2);
plot(tout, simout);
legend('Top Tank', 'Bottom Tank');
xlim([0, 600]);

% PI Controller
figure;
load('Two Tank/PIController');
plot(TwoTank(:, 1), TwoTank(:, 2), TwoTank(:, 1), TwoTank(:, 3), 'LineWidth', 2);
legend('Top Tank', 'Bottom Tank');
xlim([0, 600]);

% PD Controller
figure;
load('Two Tank/PDController');
plot(TwoTank(:, 1), TwoTank(:, 2), TwoTank(:, 1), TwoTank(:, 3), 'LineWidth', 2);
legend('Top Tank', 'Bottom Tank');
xlim([0, 600]);

%%

% P-Only Controller
load('Two Tank/POnlyController');
sim('Lab3BSimulinkPOnly')

% Top Tank
figure;
hold on;
plot(TwoTank(:, 1), TwoTank(:, 2), 'LineWidth', 2);
plot(tout, simout, 'LineWidth', 4);
title('Top Tank Height, Experimental and Simulated Data, P-Only Controller');
xlabel({'Time (s)'
        ''
        % Figure label
        '\bfFigure 1: \rmTop Tank Height, Experimental and Simulated Data, P-Only Controller'});
ylabel('Height (in)');
legend('Experimental', 'Simulated', 'Location', 'northwest');
xlim([0, 600]);

% Bottom Tank
figure;
hold on;
plot(TwoTank(:, 1), TwoTank(:, 3), 'LineWidth', 2);
plot(tout, simout1, 'LineWidth', 4);
title('Bottom Tank Height, Experimental and Simulated Data, P-Only Controller');
xlabel({'Time (s)'
        ''
        % Figure label
        '\bfFigure 2: \rmBottom Tank Height, Experimental and Simulated Data, P-Only Controller'});
ylabel('Height (in)');
legend('Experimental', 'Simulated', 'Location', 'northwest');
xlim([0, 600]);



% PI Controller
load('Two Tank/PIController');
sim('Lab3BSimulinkPI')

% Top Tank
figure;
hold on;
plot(TwoTank(:, 1), TwoTank(:, 2), 'LineWidth', 2);
plot(tout, simout, 'LineWidth', 4);
title('Top Tank Height, Experimental and Simulated Data, PI Controller');
xlabel({'Time (s)'
        ''
        % Figure label
        '\bfFigure 3: \rmTop Tank Height, Experimental and Simulated Data, PI Controller'});
ylabel('Height (in)');
legend('Experimental', 'Simulated', 'Location', 'northwest');
xlim([0, 600]);

% Bottom Tank
figure;
hold on;
plot(TwoTank(:, 1), TwoTank(:, 3), 'LineWidth', 2);
plot(tout, simout1, 'LineWidth', 4);
title('Bottom Tank Height, Experimental and Simulated Data, PI Controller');
xlabel({'Time (s)'
        ''
        % Figure label
        '\bfFigure 4: \rmBottom Tank Height, Experimental and Simulated Data, PI Controller'});
ylabel('Height (in)');
legend('Experimental', 'Simulated', 'Location', 'northwest');
xlim([0, 600]);



% PD Controller
load('Two Tank/PDController');
sim('Lab3BSimulinkPD')

% Top Tank
figure;
hold on;
plot(TwoTank(:, 1), TwoTank(:, 2), 'LineWidth', 2);
plot(tout, simout, 'LineWidth', 4);
title('Top Tank Height, Experimental and Simulated Data, PD Controller');
xlabel({'Time (s)'
        ''
        % Figure label
        '\bfFigure 5: \rmTop Tank Height, Experimental and Simulated Data, PD Controller'});
ylabel('Height (in)');
legend('Experimental', 'Simulated', 'Location', 'northwest');
xlim([0, 600]);

% Bottom Tank
figure;
hold on;
plot(TwoTank(:, 1), TwoTank(:, 3), 'LineWidth', 2);
plot(tout, simout1, 'LineWidth', 4);
title('Bottom Tank Height, Experimental and Simulated Data, PD Controller');
xlabel({'Time (s)'
        ''
        % Figure label
        '\bfFigure 6: \rmBottom Tank Height, Experimental and Simulated Data, PD Controller'});
ylabel('Height (in)');
legend('Experimental', 'Simulated', 'Location', 'northwest');
xlim([0, 600]);