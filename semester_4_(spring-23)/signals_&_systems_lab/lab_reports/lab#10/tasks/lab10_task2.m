N = 5; % Fundamental period
n = 0:N-1; % Time indices

% Given coefficients
a0 = 1;
a2 = exp(1i*pi/4);
a4 = conj(2*exp(1i*pi/3));

% Calculate x[n] using IDFT
x = (1/N) * (a0*exp(0) + a2*exp(1i*2*pi*n*2/N) + conj(a2)*exp(-1i*2*pi*n*2/N) + a4*exp(1i*2*pi*n*4/N) + conj(a4)*exp(-1i*2*pi*n*4/N));

% Display the result
disp(x);
