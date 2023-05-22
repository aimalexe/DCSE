%{
Sample the signal given in above example to get its discrete?time counterpart (take 10 samples/sec 
as sampling rate). Make the resultant signal causal. Display the lollipop plot of each signal.
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

unit = (time>=0); 
causalSig = sig.*unit;

subplot(3,1,2);
stem(time, unit, 'r','filled'); 
xlabel('time'); 
ylabel('Signal Amplitude'); 
title('Unit Step');

subplot(3,1,3);
stem(time,causalSig, 'k','filled'); 
xlabel('time');
ylabel('signal amplitude');
title('causal version of sin(2*\pi*f*t)');