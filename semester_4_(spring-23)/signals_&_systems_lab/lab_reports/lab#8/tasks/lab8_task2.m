%{
A signal is said to be anti?causal if it exists for values of n<0. Make the signal given in above example 
anti?causal.
%}

clc;
clear all;
close all;

time = -2:1/10:2;
sig = sin(2*pi*2*time);

subplot(3,1,1);
stem(time,sig,'filled');
xlabel('time');
ylabel('signal amplitude'); 
title('sin(2*\pi*f*t)');

mirroredUnit = (time<=0); 
nonCausalSig = sig.*mirroredUnit;

subplot(3,1,2);
stem(time, mirroredUnit, 'r','filled'); 
xlabel('time'); 
ylabel('Signal Amplitude'); 
title('- Unit Step');

subplot(3,1,3);
stem(time,nonCausalSig, 'k','filled'); 
xlabel('time');
ylabel('signal amplitude');
title('non-causal version of sin(2*\pi*f*t)');