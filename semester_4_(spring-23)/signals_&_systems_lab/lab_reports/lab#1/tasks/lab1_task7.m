%{
Devise an algorithm in MatLab that takes ten inputs from the user and normalizes them 
between [0-1]. Hints: Find the pair-wise max (maxi) and min (mini) of ten numbers using the
max and min built-in command. Find the normalized value for each input using formula (inputmini)/(maxi-mini).
Note: Do not use loops or if else structures.
%}
clc;
clear;

% Ask the user for ten inputs
inputs = input('Enter ten numbers: ');

% Find the maximum and minimum values of the inputs using max and min built-in commands
maxi = max(inputs);
mini = min(inputs);

% Normalize each input using the formula (input-mini)/(maxi-mini)
normalized_inputs = (inputs - mini) ./ (maxi - mini);

% Display the normalized inputs
disp('The normalized inputs are:');
disp(normalized_inputs);
