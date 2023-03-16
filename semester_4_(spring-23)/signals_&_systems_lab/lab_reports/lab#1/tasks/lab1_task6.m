%{
Implement a temperature conversion scenario in MatLab that takes the temperature from the 
user in Fahrenheit and displays the output in Centigrade.
%}
clear;
clc;

% Taking temp in farenheit from user
farenheit = input('Enter farenheit scale temprature? ');

%Converting to centigrade scale
centigrade = (farenheit - 32)/ 1.8