%{
Write a user-defined MatLab function “Calculate”, with two input and two output arguments that determines the height
in centimeters (cm) and mass in kilograms (kg) of a person from his height in inches (in.) and weight in pounds (lb).   
(a)	Determine the height and mass of a 5 ft. 15 in. person in SI units who weight 180 lb.  
(b)	Determine your own height and weight in SI units.   
%}

function [centimeter, kilogram]=calculate(inches, pounds)
    centimeter = inches * 2.54;
    kilogram = pounds * 0.453;

