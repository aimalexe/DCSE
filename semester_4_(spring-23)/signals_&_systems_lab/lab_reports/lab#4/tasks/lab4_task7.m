%{
Create a function AmpScale that takes a discrete?time signal S and a threshold T from user and 
scales the amplitude of the input signal. The function saves and counts the number of samples 
with amplitude greater than T and less than -T and plots the amplitude scaled signal and gives 
the number of sample within the thresholds as output.
%}

clc;
clear;

x = [1 3 6 0 -3 5 -6 9 8 4]
ampScale(x, 5);

y = [3 5 4 -6 8 10 54 17];
ampScale(y, 2);

