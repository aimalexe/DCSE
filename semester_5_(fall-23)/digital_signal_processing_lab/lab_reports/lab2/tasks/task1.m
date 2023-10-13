clear all;
clc;
close all;

%% (d) Use MATLAB as a calculator
pi*pi - 10
sin(pi/4)
ans ^ 2

%% (e)	Do variable name assignment in MATLAB. 
x = sin( pi/5 );
cos( pi/5 ) %<--- assigned to what?
y = sqrt( 1 - x*x )
ans

%% (f)	Complex numbers are natural in MATLAB. 
z = 3 + 4i, w = -3 + 4j
real(z), imag(z)
abs([z,w]) %<-- Vector constructor
conj(z+w)
angle(z)
exp( j*pi )
exp(j*[ pi/4, 0, -pi/4 ])
