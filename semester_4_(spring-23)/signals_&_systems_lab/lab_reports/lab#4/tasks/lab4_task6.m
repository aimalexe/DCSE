%{
Given the signals:
X1[n] = 2?[n] + 5?[n?1] + 8?[n?2] + 4?[n?3] + 3?[n?4]
X2[n] = ?[n?4] + 4?[n?5] +3?[n?6] + 2?[n?7]
Write a Matlab program that adds these two signals. Plot the original signals as well as the final 
results using different plotting designs.
%}

clc;
clear;

x1 = [2 5 8 4 3 0 0 0];
x2 = [0 0 0 0 1 4 3 2];

sum = x1 + x2;

figure(1)
subplot(1,3,1)
plot(x1, 'r');
xlabel('x1');
ylabel('time');

title('x2 signal');
subplot(1,3,2)
plot(x2, 'g--');
xlabel('x2');
ylabel('time');
title('x2 signal');

subplot(1,3,3)
plot(sum, 'b');
xlabel('sum');
ylabel('time');
title('x1 + x2');

