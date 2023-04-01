%{
a) Generate the signal x(t) = Ae(j?t + ?) for A = 3, ?= ?0.4, and ? = 2?(125). Take a range for t 
that will cover 2 or 3 periods. 
b) Plot the real part versus t and the imaginary part versus t. Use subplot(2,1,i) to put both 
plots in the same window. 
c) Verify that the real and imaginary parts are sinusoids and that they have the correct 
frequency, phase, and amplitude. 
%}

clc;
clear;
close all;

t = linspace(0, 0.025, 1000);
amp = 3;
phase = -0.4;
f = 2 * pi * 125;

sig = amp * exp(j * f * t + phase);

% plot the real part
subplot(2,1,1)
plot(t, real(sig))
title('Real part of complex sig') 
xlabel('time')
ylabel('signal real amplitude') 
grid

% plot the imaginary 
subplot(2,1,2)
plot(t, imag(sig)) 
title('Imaginary part of complex sig') 
xlabel('time')
ylabel('signal imaginary amplitude') 
grid