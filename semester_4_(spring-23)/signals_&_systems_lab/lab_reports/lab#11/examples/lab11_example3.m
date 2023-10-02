clc;
clear all;
close all;

% Generation of periodic square wave 
t = -1.5:0.005:1.5; 
xcos = cos(2*pi*t); 
xt = xcos>0;

% FS coefficients of periodic square wave 
k = -50:50; 
T = 1; 
T1 = 0.25; 
ak = sin(k*2*pi*(T1/T))./(k*pi); 
ak(51) = 2*T1/T; % Manual correction for a0 ?> ak(51)

% Time scaling parameters 
alp1 = 0.5; 

% w's for the time scaled signals 
w0 = 2*pi/T; 
w1 = alp1*w0;

% Reconstruction from ak's with 101 terms (M=50) 
xat1 = zeros(1,length(t)); 

for k = -50:50 
    xat1 = xat1 +ak(k+51)*exp(j*k*w1*t); 
end


figure(1);
subplot(2,1,1);
plot(t,xt,'lineWidth',2);
ylabel('x(t)');
title('Periodic Square Wave (T=1, T1=0.25)'); 
axis([-1.5 1.5 -0.2 1.2]);
grid;

subplot(2,1,2);
plot(t,real(xat1),'lineWidth',2);
ylabel('x(t)');
title('Reconstruction from ak''s (alp1=0.5, w1=0.5*w0)');
axis([-1.5 1.5 -0.2 1.2]);
grid;
