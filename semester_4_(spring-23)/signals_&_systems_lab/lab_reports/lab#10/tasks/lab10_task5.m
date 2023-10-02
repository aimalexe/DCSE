clc;
clear all;
close all;

T = 1; % Period of the square wave
N = 1000; % Number of samples
t = linspace(0, T, N); % Time vector

% Generate the original square wave
x_original = square(2*pi*t);

% Reconstruction using Fourier series
M = [10, 20, 100]; % Number of terms

figure;

for i = 1:length(M)
    m = M(i);

    % Fourier series coefficients
    a = zeros(1, m);
    b = zeros(1, m);

    % Calculate Fourier series coefficients
    for k = 1:m
        a(k) = (2/T) * trapz(t, x_original .* cos(2*pi*k*t/T));
        b(k) = (2/T) * trapz(t, x_original .* sin(2*pi*k*t/T));
    end

    % Reconstruct the square wave using Fourier series
    x_reconstructed = zeros(1, N);
    for k = 1:m
        x_reconstructed = x_reconstructed + a(k)*cos(2*pi*k*t/T) + b(k)*sin(2*pi*k*t/T);
    end

    % Plot the reconstructed square wave
    subplot(length(M), 1, i);
    plot(t, x_reconstructed, 'b', 'LineWidth', 1.5);
    hold on;
    plot(t, x_original, 'r--', 'LineWidth', 1.5);
    hold off;
    xlabel('t');
    ylabel('Amplitude');
    title(['Reconstructed Square Wave with M = ', num2str(m), ' terms']);
    legend('Reconstructed', 'Original');
end