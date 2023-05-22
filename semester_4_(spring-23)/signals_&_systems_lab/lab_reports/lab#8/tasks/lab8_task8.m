%{
Two systems are connected in cascade:
h1[n]=[1 3 2 1] 
h2[n]=[1 1 2]
If the input x[n] = impulse[n]+ 4impulse[n-1] +3impulse[n-2] +2impulse[n-3] is applied, determine the output.

%}

clc;
clear all;
close all;

time = -5 : 1: 5;
impulse = [zeros(1, 5) 1 zeros(1, 5)];
impulse1 = [zeros(1, 6) 1 zeros(1, 4)];
impulse2 = [zeros(1, 7) 1 zeros(1, 3)];
impulse3 = [zeros(1, 8) 1 zeros(1, 2)];

h1 = [1 3 2 1];
h2 = [1 1 2];
input = impulse + 4*impulse1 + 3*impulse2 + 2*impulse3;

output1 = conv(input, h1);
output2 = conv(output1, h2);

figure(1);
subplot(3, 1, 1);
stem(input);
title('Discrete Filter Input x[n]'); 
xlabel('index, n');
ylabel('Value, x[n]');

subplot(3,1,2);
stem(output1, 'k');
title('Discrete Filter Output y1[n]');
xlabel('index, n');
ylabel('Value, y2[n]');

subplot(3,1,3);
stem(output2, 'r');
title('Discrete Filter Output y2[n]');
xlabel('index, n');
ylabel('Value, y2[n]');