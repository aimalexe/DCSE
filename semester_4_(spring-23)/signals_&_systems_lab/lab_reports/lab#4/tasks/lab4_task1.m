%{
Given the signals:
x1[n] = [2 5 8 4 3] 
x2[n] = [4 3 2]
a) Write a MatLab program that adds these two signals. Use vector addition and 
multiplication. 
b) Instead of using vector addition and multiplication, use for loop to add and multiply the 
signals. 
c) Design a function SigPlot that takes the original signals and their sum and product as input 
and plots them as:
i) Separate Figures,
ii) Single Figure overlapping all the signals, and
iiI) Single Figure with separate signal plots using subplots
%}

clc
clear all
close all

sig1 = [2 5 8 4 3];
sig2 = [4 3 2 0 0];

%a)
sigAddition = sig1 + sig2
sigProduct = sig1 .* sig2

% b)
for i = 1 : length(sig1)
    sig3(i) = sig1(i) + sig2(i);
end
disp('The vector addition using loops are: ');
disp(sig3);

for i = 1 : length(sig1)
    sig4(i) = sig1(i) * sig2(i);
end
disp('The vector product using loops are: ');
disp(sig4);

% c)
sigPlot1(sig1, sig2, sig3, sig4)
























