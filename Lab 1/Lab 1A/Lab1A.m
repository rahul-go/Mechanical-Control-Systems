%% ME 422 Lab 1
% Rahul Goyal
%
% Jake Rogers

% Reset
clc;
clear all;
close all;



%% Exercise 1
% Mass-damper system with a force input. FBD and MAD from Figure 1.1 and
% equations derived from the diagrams. The state variable is v, the
% velocity of the mass; mass m and friction coefficient b are constants,
% and force f(t) is the system input. The input force changes from zero at
% time t < 1 sec to a constant nonzero value (let’s choose 1.0 N for
% simplicity) at all times t > 1 sec.

figure;
sim('Lab1_1');

% Derivative of X
subplot(2, 1, 1);                       % 2 rows, one column, first graph
plot(tout, simout(:,1), 'LineWidth', 2);
grid on;
title('Derivative of X');
xlabel('Time [sec]');
ylabel('Value [units/sec]');
axis([0 2 -0.2 1.2]);

% Value of X 
subplot(2, 1, 2);                       % 2 rows, one column, second graph
plot(tout, simout(:,2), '--','LineWidth', 2);
grid on;
title('Value of X');
xlabel('Time [sec]');
ylabel('Value [units]');
axis([0 2 -1 5]);



%% Exercise 2
% First-order systems with varying settling times and steady-state gains.

figure;

% Time Constant: 1s | Gain: 0.5
sim('Lab1_2A');
subplot(3, 1, 1);                       % 3 rows, one column, first graph
plot(tout, simout, 'LineWidth', 2);
title('Time Constant: 1s | Gain: 0.5');
xlabel('Time (s)');
ylabel('Response (units)');
xlim([0 6]);

% Time Constant: 0.2s | Gain: 8
sim('Lab1_2B');
subplot(3, 1, 2);                       % 3 rows, one column, second graph
plot(tout, simout, 'LineWidth', 2);
title('Time Constant: 0.2s | Gain: 8');
xlabel('Time (s)');
ylabel('Response (units)');
xlim([0 3]);

% Time Constant: 14.5s | Gain: -0.7
sim('Lab1_2C');
subplot(3, 1, 3);                       % 3 rows, one column, third graph
plot(tout, simout, 'LineWidth', 2);
title('Time Constant: 14.5s | Gain: -0.7');
xlabel('Time (s)');
ylabel('Response (units)');
xlim([0 60]);

%% Exercise 2 Questions
% The system behaves as expected: it approaches a final output change of
% 0.5 and takes one second to reach about 63.2% of this final output
% change.
%
% To produce a steady-state response twice as great in the same time frame,
% the steady-state gain can be multiplied by 2.
%
% To accelerate the system such that it responds twice as quickly as the
% original system, the time constant can be divided by 2.



%% Exercise 3
% Second-order systems with varying steady-state gains, damping ratios, and
% natural frequencies.

figure;

% Damping Ratio: 0.15 | Frequency: 1.0 Hz
sim('Lab1_3A');
subplot(3, 1, 1);                       % 3 rows, one column, first graph
plot(tout, simout, 'LineWidth', 2);
title('Damping Ratio: 0.15 | Frequency: 1.0 Hz');
xlabel('Time(s)');
ylabel('Response (units)');
xlim([0 7]);

% Damping Ratio: 0.30 | Frequency: 1.0 Hz
sim('Lab1_3B');
subplot(3, 1, 2);                       % 3 rows, one column, second graph
plot(tout, simout, 'LineWidth', 2);
title('Damping Ratio: 0.30 | Frequency: 1.0 Hz');
xlabel('Time(s)');
ylabel('Response (units)');
xlim([0 4]);

% Damping Ratio: 0.15 | Frequency: 2.0 Hz
sim('Lab1_3C');
subplot(3, 1, 3);                       % 3 rows, one column, third graph
plot(tout, simout, 'LineWidth', 2);
title('Damping Ratio: 0.15 | Frequency: 2.0 Hz');
xlabel('Time(s)');
ylabel('Response (units)');
xlim([0 4]);

%% Exercise 3 Questions
% Doubling the damping coefficient causes the step response to approach
% steady-state twice as quickly.
%
% Doubling the oscillation frequency causes the step response to both
% oscillate at twice the frequency and, as a side-effect, also approach
% steady-state twice as quickly.



%% Exercise 4
% Systems with two first-order systems in series.

figure;

% Sys1Gain: 2, Sys1TC: 1s | Sys2Gain: 2, Sys2TC: 1s
sim('Lab1_4A');
subplot(2, 1, 1);                       % 2 rows, one column, first graph
plot(tout, simout, 'LineWidth', 2);
title('KSS1: 2, TC1: 1s | KSS2: 2, TC2: 1s');
xlabel('Time(s)');
ylabel('Response (units)');
xlim([0 10]);

% Sys1Gain: 0.1, Sys1TC: 0.1s | Sys2Gain: 10, Sys2TC: 5s
sim('Lab1_4B');
subplot(2, 1, 2);                       % 2 rows, one column, second graph
plot(tout, simout, 'LineWidth', 2);
title('KSS1: 0.1, TC1: 0.1s | KSS2: 10, TC2: 5s');
xlabel('Time(s)');
ylabel('Response (units)');
xlim([0 30]);

%% Exercise 4 Questions
% The second-order system constituted by two first-order systems in series
% does not oscillate. Rather, it acts like a step response.
% 
% The two first-order systems in series results in a step-response. This
% step-response has a gain equal to the product of the gains of each
% subsystem and a time constant equal to the sum of the time constants of
% each subsystem.