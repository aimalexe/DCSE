clc;
clear;
close all;

% Sinusoidal Signal
time = -10:0.1:10;
frequency = 0.5;
amplitude = 2;
sinusoidalSignal = amplitude * sin(2*pi*frequency*time);

subplot(2, 1, 1)
plot(time, sinusoidalSignal);
xlabel('time s');
ylabel('amplitude');
title('Sinusoidal Continuous Signal');

subplot(2, 1, 2)
stem(time, sinusoidalSignal);
xlabel('time s');
ylabel('amplitude mm');
title('Sinusoidal Discrete Signal')
