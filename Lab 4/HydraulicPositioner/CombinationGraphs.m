%% 9.a step PD 10 0.01

figure;
hold on
plot(at,ameas_pos)
title('9(a) PD [10 0 0.01] Step Input')
ylabel('Displacement (inches)')
xlabel('Time (sec)')

%% 9.b ramp P 10

figure;
hold on
plot(bt,bmeas_pos,LineType)
title('9(b) P [10 0 0] Ramp Input')
ylabel('Displacement (inches)')
xlabel('Time (sec)')

%% 9.b2 ramp PI 10 10 

figure;
hold on 
plot(b2t,b2meas_pos)
title('9(b2) PI [10 10 0] Ramp Input')
ylabel('Displacement (inches)')
xlabel('Time (sec)')

%% 9.c step PID 

figure;
hold on 
plot(ct,cmeas_pos)
title('9(c) PID [42.5 12 0.15] Step Input')
ylabel('Displacement (inches)')
xlabel('Time (sec)')

