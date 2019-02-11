%% Step Response
% plot(MotoOpenLoop(:, 1), MotoOpenLoop(:, 2), 'LineWidth', 2);
% 
% low = 0.1514;
% high1 = 1.816;
% high2 = 1.709;
% high = (high1 + high2) / 2;
% 
% delta = high - low;
% tc_y = 0.632 * delta
% 
% time1 = 1.54;
% time2 = 1.83;
% 
% tc = time2 - time1

%% Position vs. Time (Saturated at 200 deg)
K_pot = 0.0851;
load('stepresponse_rf5k.mat');
plot(MotoOpenLoop(:, 1), MotoOpenLoop(:, 2) / K_pot, 'LineWidth', 2);

os_rf5k = (4.541 - 3.65) / 3.65;
os_rf10k = (5.405 - 3.07) / 3.07;
os_rf20k = (5.762 - 3.12) / 3.12;