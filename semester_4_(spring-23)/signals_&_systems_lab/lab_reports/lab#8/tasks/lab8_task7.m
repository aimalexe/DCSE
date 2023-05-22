%{
Given the impulse response of the systems as:
h[n]= 2impulse[n] + impulse[n-1]+ 2impulse[n-2]+ 4impulse[n-3]+ 3impulse[n-4]
If the input x[n] = impulse[n]+ 4impulse[n-1] +3impulse[n-2] + 2impulse[n-3] is applied to the system,
determine the output of the system.
%}

clc;
clear all;
close all;

time = -5 : 1: 5;
impulse = [zeros(1, 5) 1 zeros(1, 5)];
impulse1 = [zeros(1, 6) 1 zeros(1, 4)];
impulse2 = [zeros(1, 7) 1 zeros(1, 3)];
impulse3 = [zeros(1, 8) 1 zeros(1, 2)];
impulse4 = [zeros(1, 9) 1 zeros(1, 1)];

impulseResponse = 2 * impulse + impulse1 + 2 * impulse2 + 4 * impulse3 + 3 * impulse4;
inputSig = impulse + 4 * impulse1 + 3 * impulse2 + 2 * impulse3;

outputSig = conv(impulseResponse, inputSig);

figure(1);
subplot(3, 1, 1);
stem(time, inputSig, 'g');
title('Discrete Filter Input x[n]'); 
xlabel('index, n');
ylabel('Value, x[n]');

subplot(3,1,2);
stem(time, impulseResponse, 'r');
title('Discrete impulse response h[n]');
xlabel('index, n');
ylabel('Value, h[n]');

subplot(3,1,3);
stem(outputSig, 'm');
title('Discrete Filter Output y[n]');
xlabel('index, n');
ylabel('Value, y[n]');

