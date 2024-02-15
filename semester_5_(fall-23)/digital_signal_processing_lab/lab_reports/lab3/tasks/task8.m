clc;
clear;
close all;

% Sinc Signal
time = -10:0.1:10;
frequency = 1;
sincSignal = sin(2*pi*frequency*time) ./ (pi * time);

subplot(2, 1, 1)
plot(time, sincSignal);
xlabel('time s');
ylabel('amplitude');
title('Sinc Continuous Signal');

subplot(2, 1, 2)
stem(time, sincSignal);
xlabel('time s');
ylabel('amplitude mm');
title('Sinc Discrete Signal')
