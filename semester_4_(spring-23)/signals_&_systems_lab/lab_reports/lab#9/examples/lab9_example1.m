clc ;
clear all; 
close all;

t = -1:0.005:0.995; % time duration of given signal;
xt = cos(2*pi*t/2); % generate signal
plot(t, xt); % plot signal
xlabel('time, t');
ylabel('Amplitude, A');
title('Continuous Time Cosine');
abs_xt_2 = abs(xt).^2; % take absolute square of signal
T = 2; % length of interval
delta_t = 0.005; % interval duration
pxt = sum(abs_xt_2)*delta_t/T % power of given signal
