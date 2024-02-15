% Two-tone message signal
t = 0:1/8000:0.1;
s = 10*sin(2*pi*300*t)+10*sin(2*pi*600*t);
figure;
subplot(2,2,1);
plot(t,s);
title('Two-Tone Message Signal');
xlabel('Time (s)');
ylabel('Amplitude (V)');

% Carrier signal
m = 0.5;
fc = 10000;
fs = 80000;
t = (0:1/fs:0.01)';
c = 10/m*sin(2*pi*fc*t);
subplot(2,2,2);
plot(t,c);
title('Carrier Signal');
xlabel('Time (s)');
ylabel('Amplitude (V)');

% Modulated signal
y = ammod(s, fc, fs, 0, 10/m);
subplot(2,2,3);
plot(t,y);
title('Modulated Signal');
xlabel('Time (s)');
ylabel('Amplitude (V)');

% Demodulated signal
z = amdemod(y, fc, fs, 0, 10/m);
subplot(2,2,4);
plot(t,z);
title('Demodulated Signal');
xlabel('Time (s)');
ylabel('Amplitude (V)');

% Frequency domain plots
figure;
subplot(2,2,1);
plot(abs(fft(s)));
title('Frequency Domain Plot of Two-Tone Message Signal');
xlabel('Frequency (Hz)');
ylabel('Magnitude');

subplot(2,2,2);
plot(abs(fft(c)));
title('Frequency Domain Plot of Carrier Signal');
xlabel('Frequency (Hz)');
ylabel('Magnitude');

subplot(2,2,3);
plot(abs(fft(y)));
title('Frequency Domain Plot of Modulated Signal');
xlabel('Frequency (Hz)');
ylabel('Magnitude');

subplot(2,2,4);
plot(abs(fft(z)));
title('Frequency Domain Plot of Demodulated Signal');
xlabel('Frequency (Hz)');
ylabel('Magnitude');
