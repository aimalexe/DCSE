clc;
clear all;
close all;

%% (a)	Run the MATLAB sound demo by typing xpsound at the MATLAB prompt. If you are unable to hear the sounds in the MATLAB demo then ask for help
xpsound

%% (b)	Now generate a tone (i.e., a sinusoid) in MATLAB and listen to it with the soundsc() command. 
fs = 11025;
dur = 1;
tt = 0:(1/fs):dur;
sound = sin(2*pi*2000*tt);
plot(sound);
soundsc(sound, fs);
