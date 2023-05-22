%{
Calculate the power of discrete?time cosine signal with period 20, defined over interval 0:19 
using the following formula:
%}

clc;
clear all;
close all;

time = 0 : 1 : 19;
freq = 1/20;
sig = cos(2*pi*freq*time);

stem(time, sig, 'm', 'filled');
xlabel('time, t');
ylabel('Amplitude, A');
title('Continuous Time Cosine');

dt = 1; %fragments of time.
T=length(time); %intervals of time.
power_sig = (sum(abs(sig).^2)*dt)/ T