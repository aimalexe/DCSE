clc;
clear;
close all

%% 1.	Set the sampling frequency to 2kHz and carrier frequency to 200 Hz. Generate a time vector having a duration of 0.2 s.
samplingFrequency = 2000; % Sampling Frequency
carrierFrequency = 200;  % Carrier Frequency
time = (0:1/samplingFrequency:0.2);

%% 2.	Create two tone sinusoidal signal with frequencies 30 and 60 Hz
basebandSignal1 = cos(2*pi*30*time);
basebandSignal2 = cos(2*pi*60*time);
toneSignal = basebandSignal1 + basebandSignal2;

%% 3.	Generate a Carrier Signal with the freq of 200Hz
carrierSignal = cos(2*pi*carrierFrequency*time);


%% 4.	Plot the modulating Signal and Carrier Signal figures;
subplot(3, 1, 1);
plot(time, toneSignal, 'k*--', time, carrierSignal, 'r');
xlabel('Time (s)');
ylabel('Amplitude');
legend('baseband', 'carrier');
title('baseband and carrier signals');


%% 6. Set the frequency deviation to 50 Hz.
frequencyDeviation = 50;
        
%% 7. Frequency modulate x (Modulating Signal) using fmmod.
modulatedSignal = fmmod(toneSignal,carrierFrequency,samplingFrequency,frequencyDeviation);

%% 8. Plot the original and modulated signals.
subplot(3, 1, 2);
plot(time,toneSignal,'k*--',time,modulatedSignal,'g')
xlabel('Time (s)')
ylabel('Amplitude')
legend('Original Signal','Modulated Signal');
title('Original and Modulated Signal');

%% 11. Perform Frequency Demodulation using Matlab function fmdemod
demodulatedSignal = fmdemod(modulatedSignal,carrierFrequency,samplingFrequency,frequencyDeviation);

%% 12. Plot the original and demodulated signals
subplot(3, 1, 3);
plot(time,toneSignal,'k',time,demodulatedSignal,'co');
xlabel('Time (s)');
ylabel('Amplitude');
legend('Original Signal','Demodulated Signal');
title('Original and Demodulated Signals');