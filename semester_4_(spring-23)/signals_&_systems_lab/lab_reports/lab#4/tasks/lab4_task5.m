%{
Create a function PlotCircle that takes points x, y and radius r from user as inputs and 
generates a graph of circle centered at point (x,y) with a radius equal to r. Use axis equal to 
use equal data units along each coordinate direction and use axis square to view square axis.
(Hint: use circle equation: x-axis = r*cos(theta)+x; y-axis=r*sin(theta)+y; where 
theta=0:1/100:2*pi and plot x-axis versus y-axis)
%}

clc;
clear;

x = input('Enter x? ');
y = input('Enter y? ');
r = input('Enter radius? ');

theta = 0:1/100:2*pi;
x_axis = r*cos(theta)+x;
y_axis= r*sin(theta)+y;

plot(x_axis, y_axis, 'g--');

