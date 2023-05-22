%{
Analyze the effect of Adding 1st to 17th harmonics and the effect of Adding 1st to 27th 
harmonics in above example.
%}

clc;
clear all;
close all;

time=0:0.001:5;
fundamentalFrequency=0.5;
y = (4/pi)*sin(2*pi*fundamentalFrequency*time);
subplot(2, 7, 1);
plot(time, y, 'g');
xlabel('time, t');
ylabel('Amplitude, A');
i = 2;
for k = 3:2:54;
    harmonicFrequency=k*fundamentalFrequency;
    x = (4/(k*pi))*sin(2*pi*harmonicFrequency*time); 
    y=y+x;
    
    subplot(2, 7, i);
    plot(time, y, 'm');
    xlabel('time, t');
    ylabel('Amplitude, A');
    i= i +1;
end
subplot(2, 7, 14);
plot(time, y, 'k');
xlabel('time, t');
ylabel('Amplitude, A');