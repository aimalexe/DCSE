%{
Modify the example given in topic 6.2 to generate a sine wave with phase shift of +pi/2. Then 
plot a cosine wave of same frequency, amplitude, and phase shift of 0 in another subplot. 
Compare both the signals and determine the relationship between the two.
%}

clc;
clear;
close all;

% a) First signal
fs = 1000; 
time = -3: 1/fs : 3; 
Amp = 2; 
phase1 = pi / 2; 
freq = 1;
sig1 =Amp * sin(2 * pi * freq * time + phase1);

% b) Second signal.
phase2 = 0; 
sig2 =Amp * cos(2 * pi * freq * time + phase2);

% Plotting the graphs.
figure(1)
subplot(2, 1, 1);
plot(time,sig1,  'm', 'linewidth', 1.5)
title('Continuous-Time Sine Wave: A sin(2*\pi*f*t +\phi)') ;
xlabel('Time Index --sec--')
ylabel('Signal Amplitude') 
axis([time(1) time(end) -Amp Amp]) 
grid

subplot(2, 1, 2);
plot(time,sig2, 'r', 'linewidth', 2)
title('Continuous-Time Cos Wave: A cos(2*\pi*f*t +\phi)') ;
xlabel('Time Index --sec--')
ylabel('Signal Amplitude') 
axis([time(1) time(end) -Amp Amp]) 
grid
