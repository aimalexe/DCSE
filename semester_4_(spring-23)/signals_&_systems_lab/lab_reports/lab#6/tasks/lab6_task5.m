%{
Write a program to generate a continuous?time sine wave of frequency 3 Hz, positive phase 
shift of pi/2, and amplitude of 5. Also generate a continuous?time cosine wave of frequency 3 
Hz, amplitude of 5, and phase shift of 0. Plot the two signals on separate subplots and properly 
label them. Determine the relationship between the two signals.
%}

clc;
clear;
close all;

Amp = 5;
freq = 3;
time = -1 : 1 / 1000: 1;
phase1 = pi / 2;
phase2 = 0;

sig1 = Amp * sin(2* pi * freq * time + phase1);
sig2 = Amp * cos(2 * pi * freq * time + phase2);

% Plotting the graphs.
figure(1)
subplot(2, 1, 1);
plot(time,sig1,  'g', 'linewidth', 1.5)
title('Continuous-Time Sine Wave: A sin(2*\pi*f*t +\phi)') ;
xlabel('Time Index --sec--')
ylabel('Signal Amplitude') 
axis([time(1) time(end)-1 -Amp-2 Amp+2]) 
grid

subplot(2, 1, 2);
plot(time,sig2, 'r', 'linewidth', 2)
title('Continuous-Time Cos Wave: A cos(2*\pi*f*t +\phi)') ;
xlabel('Time Index --sec--')
ylabel('Signal Amplitude') 
axis([time(1) time(end) -Amp Amp]) 
grid



