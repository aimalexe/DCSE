clc;
clear;
close all;

%% Data Generation
samples = 1000;
time = 0:1/samples:0.25;
signal = sin(2*pi*50*time) + sin(2*pi*120*time);

%% Adding Noise
% Noise standard deviation
sigma = 2;
noisySignal = signal + randn(size(time))*sigma;

%% Plotting Noisy Time Domain Signal
figure;
plot(time,noisySignal);
xlabel('Time (s)');
ylabel('Signal Amplitude');
title('Noisy Time Domain Signal');

%% Computing Discrete Fourier Transform
NOISY_SIGNAL = fft(noisySignal,251);

%% Computing Power Spectral Density
Pyy = NOISY_SIGNAL.*conj(NOISY_SIGNAL)/251;
freqAxis = 1000/251*(0:127);

%% Plotting Power Spectral Density
figure;
plot(freqAxis,10*log10(Pyy(1:128)));
xlabel('Frequency (Hz)');
ylabel('Power Spectral Density (dB)');
title('Power Spectral Density');

%% Computing and Plotting Periodogram
[Pyy2,w] = periodogram(noisySignal,rectwin(length(noisySignal)),length(noisySignal), 1000);
figure;
plot(w,10*log10(Pyy2));
xlabel('Frequency (Hz)');
ylabel('Periodogram (dB)');
title('Periodogram');

%% Zooming In to Show Peaks
figure;
plot(freqAxis(1:50),Pyy(1:50));
xlabel('Frequency (Hz)');
ylabel('Power Spectral Density (dB)');
title('Zoomed-In Power Spectral Density');
