%{
Write your own function to upsamp a signal i.e. copy the 1st sample of original signal in the 
new signal and then place an extra sample of 0, copy the 2nd sample of original signal and then 
place a 0, and so on.
a)  Call this function from a matlab file. Verify your result by using the built-in command 
“upsample”. Plot the original signal, upsampled signal determined by your function 
upsamp, and upsampled signal obtained by the command upsample.
b)  Modify your function to work as generic up sampling function that takes both the input 
signal and the sampling factor from the user. 
c)  Your function must also perform other up sampling methods such as instead of 0, the 
new sample is the copy of preceding or succeeding sample of the original signal or the 
new sample is the average of both. Check for possibility new up sampling methods by 
comparing the samples in the input signal.
%}

clc;
clear;

x =[ 0 1 2 3 4 5 6 7 8 ];
disp('Real signal');
disp(x)

y = upSample(x, 2, 2);
disp('upsampled signal')
disp(y)
