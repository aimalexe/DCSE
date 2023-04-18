%{
Write matlab code that draw graphs of sin (n*PI*x) on the interval -1<=x<=1 for n = 1, 2, 3, …, 8. 
(Hint: Use for loop)
%}

clc;
clear;
close all;

x = -1: 0.005: 1;
for n = 1  : 8
    sig = sin(n * pi * x);
    
    figure(1);
    subplot(2, 1, 1);
    plot(x, sig, 'm');
    xlabel('time --sec--');
    ylabel('Continuous Signal');
    title('Graph of sinosoid');
    
    subplot(2, 1, 2);
    stem(x, sig, 'g');
    xlabel('time --sec--');
    ylabel('Discrete Signal');
    title('Graph of sinosoid');
end;


