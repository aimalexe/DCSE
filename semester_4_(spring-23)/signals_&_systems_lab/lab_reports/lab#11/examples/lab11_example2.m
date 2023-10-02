clc;
clear all;
close all;

% FS coefficients of periodic square wave 
k = -50:50; 
T = 1; 
T1 = 0.25;

ak = sin(k*2*pi*(T1/T))./(k*pi);
ak(51)=2*T1/T; % Manual correction for a0 ?> ak(51)

t = -1.5:0.005:1.5;
w0 = 2*pi/T;
xt = zeros(1,length(t));

% Amount of time shift 
t0 = 0.25; 

% FS coefficients of the time shifted signal w0 = 2*pi/T; 
bk = ak.*exp(-j*k*w0*t0); 

%construction of original square wave
for k = -50:50 
    xt = xt + ak(k+51)*exp(j*k*w0*t); 
end

% Reconstruction from bk's with 101 terms (M=50) 
yt = zeros(1,length(t));
for k = -50:50 
    yt = yt + bk(k+51)*exp(j*k*w0*t);
end

figure(1);

subplot(2,1,1);
plot(t,xt,'lineWidth',2);
xlabel('t');
ylabel('x(t)');
title('Periodic Square Wave with ak’’s'); 
axis([-1.5 1.5 -0.2 1.2]);
grid;

subplot(2,1,2);
plot(t,real(yt),'lineWidth',2);
xlabel('t'); ylabel('y(t)=x(t?0.5)');
title('Reconstruction from bk''s with 101 terms'); axis([-1.5 1.5 -0.2 1.2]);