%{
Generate the 1x10 row vector v whose ith component is cos (i*pi/4)
%}

clc;
clear;
close all;

vector = 0;

for i = 1: 10
   vector(i) = cos(i * pi /4); 
end
vector
