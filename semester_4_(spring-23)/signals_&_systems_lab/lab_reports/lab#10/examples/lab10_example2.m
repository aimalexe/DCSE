clc;
clear all;
close all;

t = -1.5:0.005:1.5; %duration of square wave
xcos = cos(2*pi*t); %cosine wave of 1 Hz
xpsqw = xcos>0; %thresholding cosine wave using relational operator

figure;
plot(t,xpsqw,'lineWidth',2);
xlabel('t');
ylabel('x(t)');
title('Periodic Square Wave (T=1)'); 
axis([-1.5 1.5 -0.1 1.1]);
grid;



