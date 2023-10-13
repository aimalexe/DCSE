clc;
clear;
close all;

% Unit Sample Sequence
time = -10:10;
unitImpulse = time == 0;

subplot(2, 1, 1)
plot(time, unitImpulse);
xlabel('time s');
ylabel('amplitude');
title('Unit Sample Continuous Signal');

subplot(2, 1, 2)
stem(time, unitImpulse);
xlabel('time s');
ylabel('amplitude mm');
title('Unit Sample Discrete Signal')
