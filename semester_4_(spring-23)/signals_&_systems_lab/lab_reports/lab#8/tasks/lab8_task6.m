%{
Convolution is commutative. Given x[n] and h[n] as:
X[n]=[1 3 2 1]
H[n]=[1 1 2]
Show that x[n] * h[n] = h[n] * x[n].
%}

clc;
clear all;
close all;

impulseResponse = [1 1 2];
inputSig = [1 3 2 1];

lhs = conv(inputSig, impulseResponse)
rhs = conv(impulseResponse, inputSig)

figure(1);
subplot(2, 1, 1);
stem(lhs);
title('h[n]*x[n]'); 
xlabel('index, n');
ylabel('Value, left hand side');

subplot(2,1,2);
stem(rhs, 'r');
title('x[n]*h[n]');
xlabel('index, n');
ylabel('Value, right hand side');