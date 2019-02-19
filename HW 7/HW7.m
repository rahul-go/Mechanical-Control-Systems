%% ME 422 HW 7
% Rahul Goyal
%
% February 19, 2019

% Reset
clc;
clear all;
close all;

%% Problem 4

G_OL = zpk([], [0, -3, -6], 1);
rlocus(G_OL);
rlocfind(G_OL)



%% Problem 5

G_OL = zpk([], [0, -3, -6], 1);
rltool(G_OL);