clc;
clear all;
close all;

k = -15:15; %number of square wave coefficients
T = 1; %time period of square wave
T1 = 1/4; %duty cycle of square wave
ak1 = sin(k*2*pi*(T1/T))./(k*pi); %square wave Fourier series coefficients

% Ignore the "divide by zero" warning that happens 
% because k in the denominator hits 0. We will now do 
% a manual correction for a0 ?> ak1(16) 
ak1(16) = 2*T1/T;

figure;
subplot(3,1,1);
stem(k,ak1,'filled');
ylabel('ak');
title('FS Coefficients for Periodic Square Wave (T=1, T1=1/4)');

T1 = 1/8;
ak2 = sin(k*2*pi*(T1/T))./(k*pi);
ak2(16) = 2*T1/T; % Manual correction for a0 ?> ak2(16)

subplot(3,1,2);
stem(k,ak2,'filled');
ylabel('ak');
title('FS Coefficients for Periodic Square Wave... (T=1, T1=1/8)');

T1 = 1/16;
ak3 = sin(k*2*pi*(T1/T))./(k*pi);
ak3(16) = 2*T1/T; % Manual correction for a0 ?> ak3(16)

subplot(3,1,3);
stem(k,ak3,'filled');
xlabel('k');
ylabel('ak');
title('FS Coefficients for Periodic Square Wave (T=1, T1=1/16)');