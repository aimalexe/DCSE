%{


%}

clc;
clear;
close all;

time = 0 : 0.002 : 4;
sig = sin(2*pi*1*time);

figure(1);
subplot(2, 1, 1);
stem(time, sig,'filled');
xlabel('time --sec--');
ylabel('amplitude');
title('Orignal Signal');
axis([-1 6 -1 1]);

subplot(2, 1, 2);
stem(time + 1, sig,'filled');
xlabel('time --sec--');
ylabel('amplitude');
title('Shifted Signal');
axis([-1 6 -1 1]);
