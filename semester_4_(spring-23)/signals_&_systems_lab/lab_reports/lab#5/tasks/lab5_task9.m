%{
Plot the discrete signal x=a^|n| for n ranging from ?10 to 10. Draw two subplots for 0<a<1 and 
a>1.
%}

clc;
clear;
close all;

% a)
n = -10: 2 : 10;

amp1 = 0: 0.1: 1;
sig1 = amp1 .^ abs(n);

subplot(2,1,1)
stem(n, sig1, 'filled', 'r')
title('first signal') 
grid

% b)
amp2 = 1 : 2: 22;
sig2 = amp2 .^ abs(n);

subplot(2,1,2)
stem(n, sig2, 'filled', 'g') 
title('Second signal') 
grid