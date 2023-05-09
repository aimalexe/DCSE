%{


%}

clc;
clear;
close all;

time = -10 : 10;

impulse1 = [zeros(1, 10) 1 zeros(1, 10)];
sig1 = 2 * impulse1;

impulse2 = [zeros(1, 9) 1 zeros(1, 11)];
sig2 = 5 * impulse2;

impulse3 = [zeros(1, 8) 1 zeros(1, 12)];
sig3 = 8 * impulse3;

impulse4 = [zeros(1, 7) 1 zeros(1, 13)];
sig4 = 4 * impulse4;

impulse5 = [zeros(1, 6) 1 zeros(1, 14)];
sig5 = 3 * impulse5;

sig = sig1 + sig2 + sig3 + sig4 + sig5;
flipedSig = -sig;

figure(1);
subplot(2, 1, 1);
stem(time, sig,'filled');
xlabel('time --sec--');
ylabel('amplitude');
title('Orignal Signal');

subplot(2, 1, 2);
stem(time, flipedSig,'filled');
xlabel('time --sec--');
ylabel('amplitude');
title('fliped Signal');