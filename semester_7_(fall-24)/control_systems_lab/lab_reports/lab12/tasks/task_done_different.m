% Given design parameters
zeta = 0.4; % Damping ratio > 0.2
wn = 5; % Natural frequency (arbitrarily chosen for reasonable speed of response)

% Transfer function of the second-order system
num = wn^2; % Numerator
den = [1, 2*zeta*wn, wn^2]; % Denominator
G = tf(num, den);

% Display the transfer function
fprintf('Transfer Function:\n');
disp(G);

% Analyze the system characteristics
info = stepinfo(G); % Step response information
[wn_calc, zeta_calc] = damp(G); % Natural frequency and damping ratio

% Verify percentage overshoot
PO = exp(-pi*zeta/sqrt(1-zeta^2)) * 100;

% Display results
fprintf('Damping Ratio: %.2f\n', zeta_calc(1));
fprintf('Natural Frequency: %.2f rad/s\n', wn_calc(1));
fprintf('Percentage Overshoot: %.2f%%\n', PO);

% Step response plot
figure;
step(G);
title('Step Response of the Designed System');
grid on;

% Root locus to show stability for K < 2
figure;
rlocus(G);
title('Root Locus of the Designed System');
