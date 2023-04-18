%{
Write a general program that takes ‘n’ sinusoids from user of same frequency, amplitude, and 
phase. Plot the individual sinusoids & the resultant using subplot function on same figure. Do 
perform proper labeling. Note: Take the amplitude, frequency, and phase given in example of 
case 1. Run the code for different values of n and state the result on paper.
%}

clc;
clear;
close all;

amp = input('Enter Amplitude? ');
freq = input('Enter Frequency? ');
phase = input('Enter Phase? ');
time = -2 : 0.01: 2;
resultant = 0;
amount = input('How many signals are you plotting? ');

for i = 1 : amount
  sig = amp * sin(2* pi * freq * time + phase);
   resultant = resultant + sig;
   
   figure(1)
   subplot(amount+1,1,i)
    plot(time,sig,'linewidth', 1.5)
    title('Continuous-Time Sine Wave: Amp * sin(2*\pi*f*t +\phi)') ;
    xlabel('Time Index --sec--')
    ylabel('Signals Amplitude') 
    axis([time(1) time(end) -amp amp]) 
    grid;
end

subplot(amount + 1,1, amount+1);
plot(time,resultant,  'g', 'linewidth', 1.5)
title('Continuous-Time Resultant Sine Wave: Amp * sin(2*\pi*f*t +\phi)') ;
xlabel('Time Index --sec--')
ylabel('Resultant Signals Amplitude') 
grid