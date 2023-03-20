%{
Write a Matlab program to compare the signals x1[n] and x2[n]. Determine the index where a 
sample of x1[n] has smaller amplitude as compared to the corresponding sample of x2[n]. Use 
for loop.
Design a function SigPlot that takes the original signals as input from the main calling program 
and plots them as:
i) Separate Figures using stem command,
ii) Single Figure overlapping both the signals using multiple stem commands with hold on,
iii) Single Figure with separate signal plots using subplots and stem commands.
%}

clc;
clear;

x1 = [1 2 2 1 1];
x2 = [3 2 0 1 2];

x3 = [x1 > x2];

sigPlot3(x1, x2)

