%{
Write your own function downsamp that takes a signal as input, retain odd numbered samples 
of the original signal and discard the even?numbered (down sampling by 2). The function must 
return the down sampled version of that signal as output.
a) Call this function from a matlab file. Verify your result by using the built-in command 
“downsample”. Plot the original signal, downsampled signal determined by your 
program, and downsampled signal obtained by the command downsample.
b) Modify your function to work as generic down sampling function that takes both the 
input signal and the sampling factor from the user. Your function must also check the 
possibility of down sampling by comparing the sampling rate with the number of 
samples in the input signal.
%}

clc;
clear all;
close all;

x =[ 0 1 2 3 4 5 6 7 8 ];
disp('Real signal');
disp(x)

y = downSample(x, 2);
disp('downsampled signal')
disp(y)