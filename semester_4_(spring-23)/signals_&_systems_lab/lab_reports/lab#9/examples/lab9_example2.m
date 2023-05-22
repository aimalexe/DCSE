clc;
clear all;
close all;

t=0:0.0001:8;
ff=0.5;
% WE ARE USING SINE FUNCTION BECAUSE FROM EXPONENTIAL FORM OF FOURIER 
% SERIES FINALLY WE ARE LEFT WITH SINE TERMS 
y = (4/pi)*sin(2*pi*ff*t);
% COMPLEX AMPLITUDE = (4/(j*pi*k)) 
for k = 3:2:7
    fh=k*ff;
    x = (4/(k*pi))*sin(2*pi*fh*t); y=y+x;
end
plot(t,y,'linewidth',1.5);
title('A square wave with harmonics 1st, 3rd, 5th, and 7th'); xlabel('Time');
ylabel('Amplitude');