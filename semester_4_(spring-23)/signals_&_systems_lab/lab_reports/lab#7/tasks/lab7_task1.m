%{


%}

clc;
clear;
close all;

time = -10 : 10;
signum = [-1*ones(1,10) 0 ones(1,10)];

figure(1);
stem(time, signum,'filled');
xlabel('time --sec--');
ylabel('amplitude');
title('Signum Function');
axis([-10 10 -1 1]);
