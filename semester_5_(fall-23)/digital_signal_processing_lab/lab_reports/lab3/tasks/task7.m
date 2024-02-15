clc;
clear;
close all;

% Signum Signal
time = -10:1:10;
signumSignal = [-ones(1, 10) 0 ones(1,10)];

subplot(2, 1, 1)
plot(time, signumSignal);
xlabel('time s');
ylabel('amplitude');
title('Signum Continuous Signal');

subplot(2, 1, 2)
stem(time, signumSignal);
xlabel('time s');
ylabel('amplitude mm');
title('Signum Discrete Signal')
