clc;
clear all; 
close all;

% FS coefficients of periodic square waves 
k = -50:50;
T1 = 0.25;
T=1;
ak = sin(k*2*pi*(T1/T))./(k*pi);
ak(51)=2*T1/T; % Manual correction for a0 ?> ak(51)
t = -1.5:0.005:1.5;
xt = zeros(1,length(t)); 

for k = -50:50
    xt = xt + ak(k+51)*exp(j*k*2*pi/T *t); 
end
T1 = 0.125;
T=1;
k = -50:50;

bk = sin(k*2*pi*(T1/T))./(k*pi);
bk(51) = 2*T1/T; % Manual correction for b0 ?> bk(51)

yt = zeros(1,length(t)); 

for k = -50:50
    yt = yt + bk(k+51)*exp(j*k*2*pi/T *t); 
end

sum=xt+yt;

% Application of linearity property of FS 
ck = ak+bk; 

% Reconstruction with M=50 
w0 = 2*pi/T;
zt = zeros(1,length(t)); 

for k = -50:50
    zt = zt + ck(k+51)*exp(j*k*w0*t); 
end

figure(1);
plot(t,real(sum),'lineWidth',2);
xlabel('t');
ylabel('x(t)+y(t)');
title('original x(t)+y(t) with ak''s and bk''s with 101 terms');
grid;

figure(2);
plot(t,real(zt),'lineWidth',2);
xlabel('t');
ylabel('z(t)=x(t)+y(t)');
title('Reconstruction of y(t)from ak+bk''s with 101 terms'); 
grid;