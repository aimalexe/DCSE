%{
Sinusoidal sequences are implemented using sin() & cos() functions.
Example: Continuous?Time Sinusoid
%}

clc;
clear;
close all;

f0 = 3;
A = 5;
t = -1: 0.005: 1;

sig = A * cos(2 * pi * f0 * t);

figure(1);
plot(t, sig, '*:');
xlabel('time --sec--');
ylabel('Amplitude');
title('Graph of sinosoid');