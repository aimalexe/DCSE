clc;
clear;
close all;

% Unit Step Signal
time = -10:10;
unitStep = time >= 0;

subplot(2, 1, 1)
plot(time, unitStep);
xlabel('time s');
ylabel('amplitude');
title('Unit Step Continuous Signal');

subplot(2, 1, 2)
stem(time, unitStep);
xlabel('time s');
ylabel('amplitude mm');
title('Unit Step Discrete Signal')
