%{
Write a general program that takes �n� sinusoids from user of same amplitude and phase with 
varying frequencies. Take each frequency from user on run time. Plot the individual sinusoids & 
the resultant using subplot function on same figure. Do perform proper labeling. Note: Take 
the amplitude and phase given in example of case 3. Run the code for different values of n and 
state the result on paper.
%}

clc;
clear;
close all;

amount = input('How many signals will you be plotting? ');

Amp = 1;
time = -2: 0.01 : 2;
phase = 0;
resultant = 0;

for i = 1 : 1: amount 
   freq = input('Enter frequency of this signal? '); 
   sig = Amp * sin(2* pi * freq * time + phase);
   resultant = resultant + sig;
   
   figure(1)
   subplot(amount+1,1,i)
    plot(time,sig,'linewidth', 1.5)
    title('Continuous-Time Sine Wave: Amp * sin(2*\pi*f*t +\phi)') ;
    xlabel('Time Index --sec--')
    ylabel('Signals Amplitude') 
    axis([time(1) time(end) -Amp Amp]) 
    grid;
end

subplot(amount + 1,1, amount+1);
plot(time,resultant,  'g', 'linewidth', 1.5)
title('Continuous-Time Resultant Sine Wave: Amp * sin(2*\pi*f*t +\phi)') ;
xlabel('Time Index --sec--')
ylabel('Resultant Signals Amplitude') 
grid

