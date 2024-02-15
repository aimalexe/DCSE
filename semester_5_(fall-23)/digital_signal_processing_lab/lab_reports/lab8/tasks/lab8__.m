m = 0.5;
fc = 2000; 
fs = 8000; 
t = (0:1/fs:0.01)'; 
s = 8*cos(2*pi*800*t)+8*cos(2*pi*1600*t);
c = (10*m)*cos(2*pi*fc*t);

modulated_signal = ammod(s, fc, fs, 0, 10*m);
demodulated_signal = amdemod(modulated_signal, fc, fs, 0, 10*m);
figure(1)
subplot(2,3,1);

plot(t, s);
xlabel('Time (s)');
ylabel('Amlitude');
legend('Original Signal');

subplot(2,3,2);
plot(t, c);
legend('Carier Signal');
xlabel('Time (s)');
ylabel('Amlitude');

subplot(2,3,3);
plot(t, modulated_signal);
legend('Amplitude Modulated Signal');
xlabel('Time (s)');
ylabel('Amlitude');


subplot(2,3,4);
plot(t, demodulated_signal);
legend('Amplitude DeModulated Signal');
xlabel('Time (s)');
ylabel('Amlitude');

subplot(2, 3, 5);
hold on;
plot(t, s, 'k--', 'LineWidth', 2);
plot(t, demodulated_signal, 'b');
hold off;
legend('Orignal Signal', 'Amplitude Modulated Signal');
xlabel('Time (s)');
ylabel('Amlitude');

 
N = length(t);
fca = (-N/2:N/2-1/N);
length(t)
length(fca)
figure(2)
title('Frequency Domain')
subplot(2,2,1);
plot(fca, abs(fft(s)), 'LineWidth', 2);
xlabel('Frequency (Hz)');
ylabel('Amlitude');
legend('Original sognal');

subplot(2,2, 2);
plot(fca, abs(fft(c)), 'LineWidth', 2);
xlabel('Frequency (Hz)');
ylabel('Amlitude');
legend('Carier signal');

subplot(2,2,3);
plot(fca, abs(fft(modulated_signal)), 'LineWidth', 2);
xlabel('Frequency (Hz)');
ylabel('Amlitude');
legend('Modulated signal');

title('Frequency Domain')
subplot(2,2,4);
plot(fca, abs(fft(demodulated_signal)), 'LineWidth', 2);
xlabel('Frequency (Hz)');
ylabel('Amlitude');
legend('Demodulated sognal');