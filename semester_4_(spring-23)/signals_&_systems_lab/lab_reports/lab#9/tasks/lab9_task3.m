%{
Write a program that plots the signal s(t).
OR
What do you conclude from TASKS 2 & 3?
%}

clc;
clear all;
close all;

time = 0 : 0.001 : 9;
fundamentalFreq = 0.5;

sig = ((4/pi)*sin(2*pi*fundamentalFreq*time))/time;

for k = 1 : 2 : 9;
    harmonicFreq = k * fundamentalFreq;
    x = ((4/(k * pi))*sin(2*pi*harmonicFreq * time));
    sig = sig + x;
end

plot(time, sig,'k', 'linewidth', 1.5);
xlabel('time, t');
ylabel('Amplitude, A');