%{


%}

clc;
clear;
close all;

time = -10 : 10;
% Impulse function I[n]
impulse = [zeros(1, 10) 1 zeros(1, 10)];
% unit function u[n]
unit = [zeros(1, 10) ones(1, 11)];
%Shifted unit function u[n-1];
unitShifted = [zeros(1,11) ones(1, 10)];
%Impulse derived from unit functions equations
impulseDerived = unit - unitShifted;



figure(1);
subplot(3, 1, 1);
stem(time, impulse,'filled');
xlabel('time --sec--');
ylabel('amplitude');
title('Impluse Function');
axis([-10 10 -1 1]);

subplot(3, 1, 2);
stem(time, unit,'filled');
xlabel('time --sec--');
ylabel('amplitude');
title('Unit Function');
axis([-10 10 -1 1]);

subplot(3, 1, 3);
stem(time, impulseDerived,'filled');
xlabel('time --sec--');
ylabel('amplitude');
title('Impluse derived from Unit Function');
axis([-10 10 -1 1]);