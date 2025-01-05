%% Initialization
% Clear the workspace, command window, and close all figures
clear; clc; close all;

% System parameters
J = 3.2; % Moment of inertia
b = 3.5; % Damping coefficient
k = 0.0274; % Motor constant
R = 4; % Resistance
L = 2.75; % Inductance

% State-space matrices based on the given equations
A = [0, 1, 0; 0, -b/J, k/J; 0, -k/L, -R/L];
B = [0; 0; 1/L];
C = [1, 0, 0];
D = 0;

disp('State-space matrices initialized.');
A, B, C, D

%% Stability Check

% Method 1: Eigenvalues
% Mathematical Formula: det(lambda*I - A) = 0
% The system is stable if all eigenvalues have negative real parts.
disp('Eigenvalues of the system:');
eigen_values = eig(A);
disp(eigen_values);
if all(real(eigen_values) < 0)
    disp('The system is stable (based on eigenvalues).');
else
    disp('The system is unstable (based on eigenvalues).');
end

% Method 2: Poles of the system
% Mathematical Formula: Roots of denominator = 0.
% The system is stable if all poles (roots) lie in the left half of the complex plane.
disp('Poles of the system:');
sys = ss(A, B, C, D); % State-space representation
poles = pole(sys);
disp(poles);
if all(real(poles) < 0)
    disp('The system is stable (based on poles).');
else
    disp('The system is unstable (based on poles).');
end

% Method 3: Pole-Zero Map
% Visualizes poles (roots of the denominator) and zeros (roots of the numerator) in the complex plane.
% Stability requires all poles to be in the left half-plane (real part < 0).
figure;
subplot(2, 2, 1);
pzmap(sys);
title('Pole-Zero Map');
grid on;

% Method 4: Root Locus
% Shows trajectories of system poles as the feedback gain (K) varies.
% For stability, the trajectories should remain in the left half-plane.
subplot(2, 2, [3 4]);
rlocus(sys);
title('Root Locus');
grid on;

% Method 5: Step Response
% Evaluates time-domain behavior of the system for a unit step input.
subplot(2, 2, 2);
step(sys);
title('Step Response');
grid on;

% Method 6: Routh-Hurwitz Table
% Constructs a table from the characteristic polynomial coefficients.
% The system is stable if all entries in the first column of the table are positive.
disp('Routh-Hurwitz Stability Analysis:');
coeffs = poly(A); % Characteristic polynomial coefficients
rh_table = routh_table(coeffs);
disp(rh_table);
if all(rh_table(:, 1) > 0)
    disp('The system is stable (based on Routh-Hurwitz).');
else
    disp('The system is unstable (based on Routh-Hurwitz).');
end

%% Simulate the Unstable System
% Plot the step response of the unstable system
figure;
step(sys); % Step response uses the transfer function G(s) = C*(sI - A)^(-1)*B + D
title('Step Response of the Unstable System');
xlabel('Time (s)');
ylabel('Output');
disp('Step response plotted for the unstable system.');

%% Controllability Check
% Compute the controllability matrix
% Controllability matrix P = [B AB A^2B ... A^(n-1)B]
P = ctrb(A, B);
rank_P = rank(P);

if rank_P == size(A, 1)
    disp('The system is controllable.');
else
    error('The system is not controllable. Cannot proceed further.');
end

% Adjusting desired controller eigenvalues to match the rank(B) constraint
% Desired eigenvalues must not exceed the rank of B
rank_B = rank(B);
if rank_B < size(A, 1)
    disp('Adjusting desired eigenvalues for state feedback to match the rank of B.');
    desired_controller_eigenvalues = [-14, -33, -33.1]; % Adjusted to match rank(B)
else
    desired_controller_eigenvalues = [-14, -33, -33]; % Give eignvalues
end

% Compute state feedback gain matrix
try
    K = place(A, B, desired_controller_eigenvalues);
    disp('State feedback gain matrix (K):');
    disp(K);
catch ME
    disp('Error in pole placement:');
    disp(ME.message);
    disp('Reducing the number of desired eigenvalues to match system constraints.');
    desired_controller_eigenvalues = desired_controller_eigenvalues(1:rank_B);
    K = place(A, B, desired_controller_eigenvalues);
    disp('Adjusted state feedback gain matrix (K):');
    disp(K);
end

%% Observability Check
% Compute the observability matrix
% Observability matrix Q = [C; CA; CA^2; ...; CA^(n-1)]
Q = obsv(A, C);
rank_Q = rank(Q);

if rank_Q == size(A, 1)
    disp('The system is observable.');
else
    error('The system is not observable.');
end

% Desired observer eigenvalues (ensuring faster dynamics than controller)
desired_observer_eigenvalues = [-50, -60, -70]; % Adjusted to match rank(C')

% Compute observer gain matrix
try
    L = place(A', C', desired_observer_eigenvalues)';
    disp('Observer gain matrix (L):');
    disp(L);
catch ME
    disp('Error in observer gain placement:');
    disp(ME.message);
end

%% Observer-Based Controller Design
% Define augmented observer-based controller system
% Observer estimates states, and controller uses estimated states
A_cl = [(A - B*K), (B*K); zeros(size(A)), (A - L*C)];
B_cl = [B; zeros(size(B))];
C_cl = [C, zeros(size(C))];
D_cl = 0;

% Simulate the observer-based closed-loop system
figure;
step(ss(A_cl, B_cl, C_cl, D_cl));
title('Step Response of the Observer-Based Controller System');
xlabel('Time (s)');
ylabel('Output');
disp('Step response plotted for the observer-based controller system.');

%% PID Controller Design
% Use MATLAB's pidtool to design a PID controller manually or
% programmatically use pidtune
pid_controller = pidtune(ss(A, B, C, D), 'PID');
disp('PID controller designed.');

% Simulate the system with the PID controller
pid_system = feedback(pid_controller * sys, 1);
figure;
step(pid_system);
% Feedback transfer function G_pid(s) = G(s) / (1 + G(s)*PID(s))
title('Step Response with PID Controller');
xlabel('Time (s)');
ylabel('Output');

%% Steady-State Error Calculation
% Calculate the steady-state error before and after the controller
% Steady-state error for step input: ess = 1 - DC gain
ess_before = 1 - dcgain(sys);
ess_after = 1 - dcgain(pid_system);

% Handle infinite steady-state error case
if isinf(ess_before)
    ess_before = NaN; % Set to NaN to indicate instability
    disp('Steady-state error before controller is infinite (unstable system).');
else
    disp('Steady-state error before controller:');
    disp(ess_before);
end

disp('Steady-state error after controller:');
disp(ess_after);

%% Combined Subplot
% Create a 2x2 subplot for all results
figure;

% Plot unstable system response
subplot(2, 2, 1);
step(ss(A, B, C, D));
title('Unstable System');
xlabel('Time (s)');
ylabel('Output');

% Plot observer-based system response
subplot(2, 2, 2);
step(ss(A_cl, B_cl, C_cl, D_cl));
title('Observer-Based System');
xlabel('Time (s)');
ylabel('Output');

% Plot PID-controlled system response
subplot(2, 2, 3);
step(pid_system);
title('PID Controller');
xlabel('Time (s)');
ylabel('Output');

% Plot steady-state errors
subplot(2, 2, 4);
bar([ess_before, ess_after]);
title('Steady-State Errors');
xticks([1 2]);
xticklabels({'Before', 'After'});
ylabel('Error');

% Annotate if NaN exists in errors
if isnan(ess_before)
    text(1, 0, 'Inf', 'HorizontalAlignment', 'center', 'VerticalAlignment', 'bottom');
end
