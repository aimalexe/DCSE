%{
Given the signals:
x1[n]= 2impulse[n] -3impulse[n-1]+ 3impulse[n-2] +4impulse[n-3] -2impulse[n-4] 
x2[n]= 4impulse[n]+ 2impulse[n-1]+ 3impulse[n-2] - impulse[n-3] -2impulse[n-4] 
x3[n]= 3impulse[n]+ 5impulse[n-1] - 3impulse[n-2] +4impulse[n-3]
Verify that
x1[n] * (x2[n] * x3[n]) = (x1[n] * x2[n]) * x3[n] 
x1[n] * x2[n]= x2[n] * x1[n]
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

sig1= 2*impulse - 3*impulse1 + 3*impulse2 + 4*impulse3 - 2*impulse4; 
sig2= 4*impulse + 2*impulse1 + 3*impulse2 - impulse3 - 2*impulse4; 
sig3= 3*impulse + 5*impulse1 - 3*impulse2 + 4*impulse3;

lhs = conv(conv(sig1, sig2), sig3)
rhs =  conv(sig1, conv(sig2, sig3))

figure(1);
subplot(2, 1, 1);
stem(lhs);
title('(x1[n]*x2[n])*x3[n]'); 
xlabel('index, n');
ylabel('Value, left hand side');

subplot(2,1,2);
stem(rhs, 'r');
title('x1[n]*(x2[n]*x3[n])');
xlabel('index, n');
ylabel('Value, right hand side');