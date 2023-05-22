%{
Generate a triangular wave with N=11
%}

clc;
clear all;
close all;

time=0:0.01:0.45;
ff = 25;
sig1 = (-8/(pi^2))*exp(1i*(2*pi*ff*time));

for n = 3 : 2 : 21;
    fh = ff * n;
    sig2 = (-8/(pi^2*n^2))*exp(1i*(2*pi*fh*time));
    y = sig1 + sig2;
end
plot(time,real(y),'linewidth',3); 
title('Triangular Wave with N=11'); 
ylabel('Amplitude'); 
xlabel('Time');
%axis([0 .45 -1 1])
grid;