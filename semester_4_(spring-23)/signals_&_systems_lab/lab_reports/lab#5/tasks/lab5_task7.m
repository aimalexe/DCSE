%{
a) Generate a real?exponential x=a * exp(jn) for a=0.7 and n ranging from 0?10. Find the 
discrete time as well as the continuous time version of this signal. Plot the two signals on 
same graph (holding both graphs). 
b) Repeat the same program with value of a=1.3. 
%}

clc;
clear;
close all;

n = 0: 0.3: 10;
% a)
amp1 = 0.7;
sig1 = amp1 * exp(i * n);

%plotting real discrete complex signal
figure(1);
subplot(2,1,1);
stem(n, real(sig1), 'filled');
title('Signal discrete');
xlabel('time');
ylabel('signal1 amplitude')
grid

%plotting continuous complex signal
subplot(2,1,2);
plot(n, real(sig1), 'g');
title('Signal-1 continuous');
xlabel('Time');
ylabel('signal-1 amplitude')
grid

% b)
amp2 = 1.3;
sig2 = amp2 * exp(i * n);

%plotting real discrete complex signal
figure(2);
subplot(2,1,1);
stem(n, real(sig2), 'filled');
title('Signa-2 discrete');
xlabel('time');
ylabel('signal1 amplitude')
grid

%plotting continuous complex signal
subplot(2,1,2);
plot(n, real(sig2), 'r');
title('Signal-2 continuous');
xlabel('Time');
ylabel('signal1 amplitude')
grid