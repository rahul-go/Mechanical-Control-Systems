plot(MotoOpenLoop(:, 1), MotoOpenLoop(:, 2), 'LineWidth', 2);

low = 0.1514;
high1 = 1.816;
high2 = 1.709;
high = (high1 + high2) / 2;

delta = high - low;
tc_y = 0.632 * delta

time1 = 1.54;
time2 = 1.83;

tc = time2 - time1