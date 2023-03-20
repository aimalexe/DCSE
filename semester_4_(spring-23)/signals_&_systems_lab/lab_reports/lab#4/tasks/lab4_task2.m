%{
Amplitude scaling by a factor ? causes each sample to get multiplied by ?. Write a user?defined 
function ScaleSig that has two input arguments: (i) a signal to be scaled and (ii) scaling factor ?. 
The function should return the scaled output to the calling program. In the calling program, get 
the discrete time signal as well as the scaling factor from user and then call the 
above?mentioned function.
Design a function SigPlot that takes the original signals and their scaled versions as input from 
the main calling program and plots them as:
i) Separate Figures,
ii) Single Figure overlapping all the signals, and
iiI) Single Figure with separate signal plots using subplot.
%}
clc;
clear;

x = 1: 4: 20;
sig = [1 3 5 7 8]
scaled = scaleSig(sig, 2)

% 1)
sigPlot2(sig, scaled)

% 2)
figure(3)
plot(x, sig, x, scaled)
xlabel('time')
ylabel('signals')
title('Both Graphs')

% 3)
figure(4)

subplot(2,2,1)
plot(x, sig)
xlabel('time')
ylabel('Signals')

subplot(2,2,2)
plot(x, scaled)
xlabel('time')
ylabel('Scaled signals')
