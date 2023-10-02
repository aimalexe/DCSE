clc;
clear all;
close all;

T = 2*pi; % Period of the signal
N = 1000; % Number of samples
t = linspace(-pi, pi, N); % Time vector

% Given coefficients
ak = zeros(1, N);
k = -N/2:N/2-1;
ak(abs(k) < 3) = 1j*k(abs(k) < 3);

% Reconstruct the signal using Fourier series coefficients
M = 10; % Number of terms

x_reconstructed = zeros(1, N);
for i = 1:M
    x_reconstructed = x_reconstructed + ak(i) * exp(1j*k(i)*t);
end

% Plotting Fourier series coefficients
figure;
subplot(2, 1, 1);
stem(k, real(ak), 'k', 'LineWidth', 1.5);
xlabel('k');
ylabel('ak');
title('Fourier Series Coefficients');

% Plotting the reconstructed signal
subplot(2, 1, 2);
plot(t, real(x_reconstructed), 'b', 'LineWidth', 1.5);
xlabel('t');
ylabel('Amplitude');
title('Reconstructed Signal');
