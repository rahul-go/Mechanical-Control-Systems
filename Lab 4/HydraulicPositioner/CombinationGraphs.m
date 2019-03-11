%% 4.a step P 10 

figure;
hold on
plot(at,a4meas_pos,'r:','LineWidth',2)
plot(tout,simout_4a,'b')
legend('Experimental','Model','Location','best')
title('P [10 0 0] Step Input')
ylabel('Displacement (inches)')
xlabel('Time (sec)')

%% 4.b step P 20

figure;
hold on
plot(at,b4meas_pos,'r:','LineWidth',2)
plot(tout,simout_4b,'b')
legend('Experimental','Model','Location','best')
title('P [20 0 0] Step Input')
ylabel('Displacement (inches)')
xlabel('Time (sec)')

%% 4.c step P 37

figure;
hold on
plot(at,c4meas_pos,'r:','LineWidth',2)
plot(tout,simout_4c,'b')
legend('Experimental','Model','Location','best')
title('P [37 0 0] Step Input')
ylabel('Displacement (inches)')
xlabel('Time (sec)')

%% 4.d step P 82

figure;
hold on
plot(tout,d4meas_pos,'r:','LineWidth',2)
plot(tout,simout_4d,'b')
legend('Experimental','Model','Location','best')
title('P [82 0 0] Step Input')
ylabel('Displacement (inches)')
xlabel('Time (sec)')

%% 9.a step PD 10 0.01

figure;
hold on
plot(at,ameas_pos,'r:','LineWidth',2)
plot(tout,simout_9a,'b')
legend('Experimental','Model','Location','best')
title('PD [10 0 0.01] Step Input')
ylabel('Displacement (inches)')
xlabel('Time (sec)')

%% 9.b ramp P 10

figure;
hold on
plot(bt,bmeas_pos,'r:','LineWidth',2)
plot(tout,simout_9b,'b')
legend('Experimental','Model','Location','best')
title('P [10 0 0] Ramp Input')
ylabel('Displacement (inches)')
xlabel('Time (sec)')

%% 9.b2 ramp PI 10 10 

figure;
hold on 
plot(b2t,b2meas_pos,'r:','LineWidth',2)
plot(tout,simout_9b2,'b')
legend('Experimental','Model','Location','best')
title('PI [10 10 0] Ramp Input')
ylabel('Displacement (inches)')
xlabel('Time (sec)')

%% 9.c step PID 42.5 12 0.15

figure;
hold on 
plot(ct,cmeas_pos,'r:','LineWidth',2)
plot(tout,simout_9c,'b') 
legend('Experimental','Model','Location','best')
title('PID [42.5 12 0.15] Step Input')
ylabel('Displacement (inches)')
xlabel('Time (sec)')

%% Linear TF Open Loop 



