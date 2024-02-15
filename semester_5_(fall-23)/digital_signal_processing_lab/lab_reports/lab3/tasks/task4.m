clc;
clear;
close all;

% Parabolic Signal
time = -10:10;
parabolicSignal = time.^2;

subplot(2, 1, 1)
plot(time, parabolicSignal);
xlabel('time s');
ylabel('amplitude');
title('Parabolic Continuous Signal');

subplot(2, 1, 2)
stem(time, parabolicSignal);
xlabel('time s');
ylabel('amplitude mm');
title('Parabolic Discrete Signal')
