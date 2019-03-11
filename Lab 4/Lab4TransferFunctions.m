W = 28.91; 
g = (32.2 * 12);
m = W/g;

Ka = 4.6;
Kq = 0.01235;
A = 0.1473;
Kp = 82;
wn = 145.95; 
Bvt = 18363; 
Kce = 0.0017; 

%% Open Loop 

num = [4*A*Bvt*Kp*Ka*Kq];
den = [m 4*Bvt*Kce*m 4*Bvt*(A^2) 0];

tf(num,den)
rlocus(num,den)

%% Closed Loop 4a

clear Kp
Kp = 10

num = [4*Bvt*(A/m)*Kp*Ka*Kq]
den = [1 4*Bvt*Kce + 4*Bvt*(A^2)*(1/m) Kp*Ka*Kq*4*Bvt*(A/m)]

tf(num,den)
rlocus(num,den) 

%% Closed Loop 4b

clear Kp
Kp = 20

num = [4*Bvt*(A/m)*Kp*Ka*Kq]
den = [1 4*Bvt*Kce + 4*Bvt*(A^2)*(1/m) Kp*Ka*Kq*4*Bvt*(A/m)]

tf(num,den)
rlocus(num,den) 

%% Closed Loop 4c

clear Kp
Kp = 37

num = [4*Bvt*(A/m)*Kp*Ka*Kq]
den = [1 4*Bvt*Kce + 4*Bvt*(A^2)*(1/m) Kp*Ka*Kq*4*Bvt*(A/m)]

tf(num,den)
rlocus(num,den) 

%% Closed Loop 4d

clear Kp
Kp = 82

num = [4*Bvt*(A/m)*Kp*Ka*Kq]
den = [1 4*Bvt*Kce + 4*Bvt*(A^2)*(1/m) Kp*Ka*Kq*4*Bvt*(A/m)]

tf(num,den)
rlocus(num,den) 