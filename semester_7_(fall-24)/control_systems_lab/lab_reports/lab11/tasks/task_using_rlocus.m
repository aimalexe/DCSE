% Define the transfer function for the system
num = [1 7 12]; % Numerator coefficients: k*(s+3)*(s+4)
den = [1 11 30]; % Denominator coefficients: (s+5)*(s+6)
G = tf(num, den);

% Question 1: Root locus of the original system
figure;
rlocus(G);
title('Root Locus of the Original System');

% Question 2: Add a pair of complex poles
poles = [-2+2j, -2-2j]; % Example complex poles
G2 = zpk([], poles, 1) * G; % New system with added poles
figure;
rlocus(G2);
title('Root Locus with Added Complex Poles');

% Question 3: Add a pair of complex zeros
zeros = [-1+1j, -1-1j]; % Example complex zeros
G3 = zpk(zeros, [], 1) * G; % New system with added zeros
figure;
rlocus(G3);
title('Root Locus with Added Complex Zeros');

% Question 4: Add a real zero
zero = -2; % Example real zero
G4 = zpk([zero], [], 1) * G; % New system with added real zero
figure;
rlocus(G4);
title('Root Locus with Added Real Zero');

% Question 5: Add a real pole
pole = -7; % Example real pole
G5 = zpk([], [pole], 1) * G; % New system with added real pole
figure;
rlocus(G5);
title('Root Locus with Added Real Pole');

% Stability analysis for all systems
fprintf('Stability Analysis:\n');
K_range = allmargin(G).GainMargin; % Range of k for stability (original system)
fprintf('Range of k for stability (original system): %.2f to %.2f\n', K_range(1), K_range(2));

% Question 6: Break-in/Breakout points (if any)
fprintf('Break-in/Breakout points (original system):\n');
rl_data = rlocus(G); % Get root locus data
disp(rl_data); % Analyze points for break-in/breakout manually or graphically

% Impulse and step responses
k2 = 2;
k3 = 3;
G_k2 = feedback(k2 * G, 1); % Closed-loop system for k=2
G_k3 = feedback(k3 * G, 1); % Closed-loop system for k=3

figure;
impulse(G_k2);
title('Impulse Response for k=2');

figure;
step(G_k3);
title('Step Response for k=3');

% Rise time and peak response for k=3
info = stepinfo(G_k3);
fprintf('Rise Time for k=3: %.2f seconds\n', info.RiseTime);
fprintf('Peak Response for k=3: %.2f\n', info.Peak);
