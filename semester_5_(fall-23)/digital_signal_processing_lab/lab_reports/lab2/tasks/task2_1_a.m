clc;
clear all;
close all;

%% (a)	Make sure that you understand the colon notation. In particular, explain in words what the following MATLAB code will produce
jkl = 0 : 6
jkl = 2 : 4 : 17
jkl = 99 : -1 : 88
ttt = 2 : (1/9) : 4
tpi = pi * [ 0:0.1:2 ];

%% (b)	Extracting and/or inserting numbers into a vector is very easy to do.
xx = [ zeros(1,3), linspace(0,1,5), ones(1,4) ]
xx(4:6)
size(xx)
length(xx)
xx(2:2:length(xx))
xx(2:2:end)

%% (c)	Observe the result of the following assignments
yy = xx; 
yy(4:6) = pi*(1:3)