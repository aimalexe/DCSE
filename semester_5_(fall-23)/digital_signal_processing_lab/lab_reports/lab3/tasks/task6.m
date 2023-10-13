clc;
clear;
close all;

% Triangular Signal
time = -10:0.5:10;
base = 2;
x1 = 1 - abs(time) / 2;
x2 = 0;
triangularSignal = x1 .* (abs(time) <= base) + x2 .* (abs(time)>base);

subplot(2, 1, 1)
plot(time, triangularSignal);
xlabel('time s');
ylabel('amplitude');
title('Triangular Continuous Signal');

subplot(2, 1, 2)
stem(time, triangularSignal);
xlabel('time s');
ylabel('amplitude mm');
title('Triangular Discrete Signal')
