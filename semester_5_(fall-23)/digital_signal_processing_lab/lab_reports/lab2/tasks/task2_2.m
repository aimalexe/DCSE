clc;
clear all;
close all;

%% (a)	Experiment with vectors in MATLAB. Think of the vector as a set of numbers. 
xk = cos( pi*(0:11)/4 ) %<---comment: compute cosines

%% (b) Rewrite this computation without using the loop (follow the style in the previous part).
yy = [ ]; %<--- initialize the yy vector to be empty
for k=-5:5
yy(k+6) = cos( k*pi/3 );
end
yy
yy_2 = cos(pi*(-5:5)/3)

%% (c)	Plotting is easy in MATLAB for both real and complex numbers. The basic plot command will plot a vector y versus a vector x connecting successive points by straight lines. 
x = [-3 -1 0 1 3];
y = x.*x - 3*x;
plot( x, y )
z = x + y*sqrt(-1)
plot( z ) %<---- complex values: plot imag vs. real

%% (d)	Use the built-in MATLAB editor to create a script file called mylab1.m containing the following lines
tt = -1 : 0.01 : 1;
xx = cos(5*pi*tt);
zz = 1.4*exp(j*pi/2)*exp(j*5*pi*tt);
plot(tt, xx, 'b-', tt, real(zz), 'r--') %<--- plot a sinusoid
grid on
title('TEST PLOT of a S')

%% (e)	Run your script from MATLAB. To run the file mylab1 that you created previously, try
task1 %<---will run the commands in the file
type task1 %<---will type out the contents of
% mylab1.m to the screen