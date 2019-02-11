%% ME 422 Lab 2B
% Rahul Goyal
%
% Jake Rogers
%
% February 11, 2019

% Reset
clc;
clear all;
close all;




%% Open-Loop Step Response

load('MotoMatic/stepresponse.mat');
plot(MotoOpenLoop(:, 1)-0.53, MotoOpenLoop(:, 2)*6, 'LineWidth', 2);

low = 0.1514;
high1 = 1.816;
high2 = 1.709;
high = (high1 + high2) / 2;

delta = high - low;
tc_y = 0.632 * delta;

time1 = 1.54;
time2 = 1.83;

tc = time2 - time1;



%% Position vs. Time (Saturated at 200 deg)

K_pot = 0.0851;
load('MotoMatic/stepresponse_rf5k.mat');
plot(MotoOpenLoop(:, 1)-1.18, MotoOpenLoop(:, 2)/K_pot, 'LineWidth', 2);
load('MotoMatic/stepresponse_rf10k.mat');
plot(MotoOpenLoop(:, 1)-1.10, MotoOpenLoop(:, 2)/K_pot, 'LineWidth', 2);
load('MotoMatic/stepresponse_rf20k.mat');
plot(MotoOpenLoop(:, 1)-1.03, MotoOpenLoop(:, 2)/K_pot, 'LineWidth', 2);
legend('Rf = 5k Ohm', 'Rf = 10k Ohm', 'Rf = 20k Ohm');
xlim([0, 3]);

os_rf5k = (4.541 - 3.65) / 3.65
os_rf10k = (5.405 - 3.07) / 3.07
os_rf20k = (5.762 - 3.12) / 3.12