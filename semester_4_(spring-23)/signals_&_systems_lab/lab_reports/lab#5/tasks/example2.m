clc;
clear;

n = 0: 1/10: 10;
k = 5;
a = pi / 2;
x = k * exp(a * n * i);

subplot(2,1,1);
stem(n, real(x), 'filled');
title('Real part of complex exp');
xlabel('sample #');
ylabel('signal amplitude')
grid

subplot(2,1,2);
stem(n, imag(x), 'filled');
title('Imaginary part of complex exp');
xlabel('sample #');
ylabel('signal amplitude')
grid