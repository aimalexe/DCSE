%{


%}

clc;
clear;
close all;

time = -2 : 1/1000 : 2;
sig = sin(2 * pi * 2 * time);
% downsampling sig by factor of 2;
downsampledSig = decimate(sig, 2);
% upsampling sig by factor of 2;
upsampledSig = interp(sig, 2);

figure(1);
subplot(3, 1, 1);
plot(sig, 'm');
xlabel('time --sec--');
ylabel('amplitude');
title('Original Signal');
%axis([-2.5 2.5 -1.5 1.5]);

subplot(3, 1, 2);
plot(downsampledSig, 'g');
xlabel('time --sec--');
ylabel('amplitude');
title('Decimated Signal');
%axis([-2.5 2.5 -2*1.5 2*1.5]);


subplot(3, 1, 3);
plot(upsampledSig, 'r');
xlabel('time --sec--');
ylabel('amplitude');
title('Interpolated Signal');
%axis([-2.5 2.5 -2*1.5 2*1.5]);
