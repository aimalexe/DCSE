clc;
clear;
close all;

% Ramp Signal
time = 0:10;
rampSignal = time;

subplot(2, 1, 1)
plot(time, rampSignal);
xlabel('time s');
ylabel('amplitude');
title('Ramp Continuous Signal');

subplot(2, 1, 2)
stem(time, rampSignal);
xlabel('time s');
ylabel('amplitude mm');
title('Ramp Discrete Signal')
