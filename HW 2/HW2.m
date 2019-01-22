%% RAHUL GOYAL | ME 422-03 | HW #2
clc;
clear all;
close all;

%% 2.1
figure;
t = 0.1:0.1:200;
x = exp(-t/40) .* heaviside(t);
plot(t, x, 'LineWidth', 2);
title('Time History of delta-h');
xlabel('t');
ylabel('delta-h');

%% 2.2
figure;
t = 0.1:0.1:200;
x = 4 * (1-exp(-t/40)) .* heaviside(t);
plot(t, x, 'LineWidth', 2);
title('Time History of delta-h');
xlabel('t');
ylabel('delta-h');

%% 2.3
figure;
t = 0.1:0.1:10;
x = (1/80 + 1/(-240*sqrt(215)+3440) * exp((-30+2*sqrt(215))*t) + ...
     1/(240*sqrt(215)+3440) * exp((-30-2*sqrt(215))*t)) .* heaviside(t);
plot(t, x, 'LineWidth', 2);
title('Unit Step Response');
xlabel('t');
ylabel('x');

%% 2.4
figure;
t = 0.01:0.01:3;
x = 1/32 * (1 - (1+4*t).*exp(-4*t)) .* heaviside(t);
plot(t, x, 'LineWidth', 2);
title('Unit Step Response');
xlabel('t');
ylabel('x');

%% 2.5
figure;
t = 0.01:0.01:20;
x = 1/16 * (1 - exp(-t/4) .* (cos(sqrt(7+15/16)*t) + ...
    1/(4*(sqrt(7+15/16))) .* sin(sqrt(7+15/16)*t))) .* heaviside(t);
plot(t, x, 'LineWidth', 2);
title('Unit Step Response');
xlabel('t');
ylabel('x');

%% 2.6
figure;
t = 0.01:0.01:10;
x = 1/10 * (1 - cos(sqrt(5)*t)) .* heaviside(t);
plot(t, x, 'LineWidth', 2);
title('Unit Step Response');
xlabel('t');
ylabel('x');