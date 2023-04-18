%{
Given the signal exp(?x)sin(8x) for 0?x?2?, plot its continuous?time and discrete?time 
representations. Use subplot and label properly.
%}
clc;
clear;
close all;

x = -1: 0.005: 1;

sig = exp(-x) * sin(8 *x);
    
figure(1);
subplot(2, 1, 1);
plot(x, sig, 'm');
xlabel('time --sec--');
ylabel('Continuous Signal');
title('Graph of sinosoid');

subplot(2, 1, 2);
stem(x, sig, 'g');
xlabel('time --sec--');
ylabel('Discrete Signal');
title('Graph of sinosoid');