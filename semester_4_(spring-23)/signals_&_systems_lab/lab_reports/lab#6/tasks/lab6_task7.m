%{
Write a general program that takes ‘n’ sinusoids from user of same frequency and phase with 
varying amplitudes. Take amplitude from user on run time. Plot the individual sinusoids & the 
resultant using subplot function on same figure. Do perform proper labeling. Note: Take the
amplitude and frequency given in example of case 2. Run the code for different values of n and 
state the result on paper.
%}

clc;
clear;
close all;

amount = input('How many signals will you be plotting? ');

freq = 0.5;
time = -2: 0.01 : 2;
phase = 0;
resultant = 0;

for i = 1 : 1: amount 
    Amp = input('Enter amplitude for this signal? '); 
    sig = Amp * sin(2* pi * freq * time + phase);

    resultant = resultant + sig;

    figure(1)
    subplot(amount +1,1,i);
    plot(time,sig,  'm', 'linewidth', 1.5)
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
grid;
