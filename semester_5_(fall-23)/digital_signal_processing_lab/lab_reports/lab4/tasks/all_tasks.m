% Sinusoidal Signals

clc
clear
close all

time = 0 : 0.001 : 1;
frequency_a = 10;
frequency_b = 20;
frequency_c = 30;
frequency_d = 40;
frequency_e = 50;
frequency_f = 60;

%% Time Domain Signals of given Frequencies
% Q1) 1.	Will generate the signal of different frequencies say , 10,20,30,40,50,60 Hz (one second duration) using Matlab as shown in figure 1 and transform the same signal in frequency domain using Fourier transform and will compare the frequencies with the time domain signal as shown in figure 2

% for frequency  = 10:
signal_a = sin(2*pi*frequency_a*time);
subplot(3, 2, 1)
plot(time, signal_a);
xlabel('Time (s)');
ylabel('Amplitude');
title('Sinusoidal Signal of 10 Hz');
axis([0, 1, -1.5, 1.5]);
grid on;

% for frequency  = 20:
signal_b = sin(2*pi*frequency_b*time);
subplot(3, 2, 2)
plot(time, signal_b);
xlabel('Time (s)');
ylabel('Amplitude');
title('Sinusoidal Signal of 20 Hz');
axis([0, 1, -1.5, 1.5]);
grid on;

% for frequency  = 30:
signal_c = sin(2*pi*frequency_c*time);
subplot(3, 2, 3)
plot(time, signal_c);
xlabel('Time (s)');
ylabel('Amplitude');
title('Sinusoidal Signal of 30 Hz');
axis([0, 1, -1.5, 1.5]);
grid on;

% for frequency  = 40:
signal_d = sin(2*pi*frequency_d*time);
subplot(3, 2, 4)
plot(time, signal_d);
xlabel('Time (s)');
ylabel('Amplitude');
title('Sinusoidal Signal of 40 Hz');
axis([0, 1, -1.5, 1.5]);
grid on;

% for frequency  = 50:
signal_e = sin(2*pi*frequency_e*time);
subplot(3, 2, 5)
plot(time, signal_e);
xlabel('Time (s)');
ylabel('Amplitude');
title('Sinusoidal Signal of 50 Hz');
axis([0, 1, -1.5, 1.5]);
grid on;

% for frequency  = 60:
signal_f = sin(2*pi*frequency_f*time);
subplot(3, 2, 6)
plot(time, signal_f);
xlabel('Time (s)');
ylabel('Amplitude');
title('Sinusoidal Signal of 60 Hz');
axis([0, 1, -1.5, 1.5]);
grid on;

%% Frequency Domain Signals of Certain Frequencies

% fourier transform for frequency = 10:
N = length(signal_a);
fourierTransform_a = fft(signal_a);
freq_a = (0:N-1)*(frequency_a/N);

subplot(3, 2, 1)
plot(freq_a, abs(fourierTransform_a));
xlabel('X-axis');
ylabel('Amplitude');
title('Fourier transform of f = 10')
axis([-1, 11, -1.5, 700]);
grid on;

% fourier transform for frequency = 20:
N = length(signal_b);
fourierTransform_b = fft(signal_b);
freq_b = (0:N-1)*(frequency_b/N);

subplot(3, 2, 2)
plot(freq_b, abs(fourierTransform_b));
xlabel('X-axis');
ylabel('Amplitude');
title('Fourier transform of f = 20')
axis([-1, 21, -1.5, 700]);
grid on;

% fourier transform for frequency = 30:
N = length(signal_c);
fourierTransform_c = fft(signal_c);
freq_c = (0:N-1)*(frequency_c/N);

subplot(3, 2, 3)
plot(freq_c, abs(fourierTransform_c));
xlabel('X-axis');
ylabel('Amplitude');
title('Fourier transform of f = 30')
axis([-1, 31, -1.5, 700]);
grid on;

% fourier transform for frequency = 40:
N = length(signal_d);
fourierTransform_d = fft(signal_d);
freq_d = (0:N-1)*(frequency_d/N);

subplot(3, 2, 4)
plot(freq_d, abs(fourierTransform_d));
xlabel('X-axis');
ylabel('Amplitude');
title('Fourier transform f = 40')
axis([-1, 41, -1.5, 700]);
grid on;

% fourier transform for frequency = 50:
N = length(signal_e);
fourierTransform_e = fft(signal_e);
freq_e = (0:N-1)*(frequency_e/N);

subplot(3, 2, 5)
plot(freq_e, abs(fourierTransform_e));
xlabel('X-axis');
ylabel('Amplitude');
title('Fourier transform of f = 50')
axis([-1, 51, -1.5, 700]);
grid on;

% fourier transform for frequency = 60:
N = length(signal_f);
fourierTransform_F = fft(signal_f);
freq_f = (0:N-1)*(frequency_f/N);

subplot(3, 2, 6)
plot(freq_f, abs(fourierTransform_F));
xlabel('X-axis');
ylabel('Amplitude');
title('Fourier transform f = 60')
axis([-1, 61, -1.5, 700]);
grid on;

%% Seperate sum of time and frequency domain signals
subplot(2, 1, 1);
sum_of_time_signals = signal_a + signal_b + signal_c + signal_d + signal_e + signal_f;
plot(time, sum_of_time_signals);
xlabel('Time (s)');
ylabel('Amplitude');
title('Sum of time domain signals');

subplot(2, 1, 2);
sum_of_frequency_signals = fourierTransform_a + fourierTransform_b + fourierTransform_c + fourierTransform_d + fourierTransform_e + fourierTransform_F;
plot(abs(sum_of_frequency_signals));
xlabel('X-axis');
ylabel('Amplitude');
title('Sum of frequency domain signals');

%% Noise Signal

% create a noise signal
noise_frequency_1 = 100;
noise_amp_1 = 0.7;
noise_1 = noise_amp_1 * sin(2*pi*noise_frequency_1*time);
subplot(4, 1, 1);
plot(time, noise_1);
xlabel('Time (s)');
ylabel('Amplitude');
title('Noise Signal of f = 100 Hz and amp = 0.7')
grid on;

noise_frequency_2 = 80;
noise_amp_1 = 0.5;
noise_2 = noise_amp_1 * sin(2*pi*noise_frequency_1*time);
subplot(4, 1, 2);
plot(time, noise_2);
xlabel('Time (s)');
ylabel('Amplitude');
title('Noise Signal of f = 80 Hz and amp = 0.5');
grid on;

% put noise in time domain signals sum
subplot(4, 1, 3);
add_noise_to_time_signals = sum_of_time_signals + noise_1 + noise_2;
plot(time, add_noise_to_time_signals);
xlabel('Time (s)');
ylabel('Amplitude');
title('Noise + Time Signals')

% put noise in frequency domain signals sum
N = length(noise_1);
fft_noise_1 = fft(noise_1);
freq_noise_1 = (0:N-1)*(noise_frequency_1/N);

fft_noise_2 = fft(noise_2);

add_noise_to_frequency_signals = sum_of_frequency_signals + fft_noise_1 + fft_noise_2;
subplot(4, 1, 4)
plot(freq_noise_1, abs(add_noise_to_frequency_signals));
xlabel('X - axis');
ylabel('Amplitude');
title('Noise + Frequency Signals')
axis([-6 1, 61, -1.5, 700]);
grid on;
