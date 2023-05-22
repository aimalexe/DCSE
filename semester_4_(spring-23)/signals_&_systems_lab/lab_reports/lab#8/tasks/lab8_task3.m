%{
Create a function by name of sig_causal in matlab that has two input arguments: (i) a discrete?time 
signal, and (ii) a position vector. The function should make the given signal causal and return the 
resultant signal to the calling program.
%}

clc;
clear all;
close all;

sig = [ 3 4 5];
pos = [ 4 6 100];

causalSig = sig_causal(sig, pos);

disp(causalSig);




