clc;
clear all;
close all;

T = 2*pi; % Period of the signal
N = 1000; % Number of samples
t = linspace(-pi, pi, N); % Time vector

% Given coefficients
ak = zeros(1, N);
ak(2:2:end) = 1;
ak(1:2:end) = 2;

% Reconstructed signal for different number of terms
M = [10, 20, 50];

figure;

% Plotting Fourier series coefficients
subplot(length(M)+1, 1, 1);
stem(ak, 'k', 'LineWidth', 1.5);
axis([0 N -0.5 2.5]);
xlabel('k');
ylabel('ak');
title('Fourier Series Coefficients');

for i = 1:length(M)
    m = M(i);

    % Reconstruct the signal using Fourier series coefficients
    x_reconstructed = zeros(1, N);
    for k = 1:m
        x_reconstructed = x_reconstructed + ak(k)*exp(1i*k*t);
    end

    % Plot the reconstructed signal
    subplot(length(M)+1, 1, i+1);
    plot(t, real(x_reconstructed), 'b', 'LineWidth', 1.5);
    xlabel('t');
    ylabel('Amplitude');
    title(['Reconstructed Signal with M = ', num2str(m), ' terms']);
end
