%{
6.2 Use MATLAB to convert the state space representation to the transfer function for the following:

x_dot = A * x + B * u(t)
y = C * x

A = [-4 -1.5;
      4   0]

B = [2;
     0]

C = [1.5 0.625]

%}

% Define matrix A
A = [-4 -1.5;
      4   0];

% Define matrix B
B = [2;
     0];

% Define matrix C
C = [1.5 0.625];

% Define matrix D (for LTI systems, D is typically zero if not specified)
D = 0;

% Create the state-space model
sys = ss(A, B, C, D);

% Display the state-space model
disp('State-space model representation:');
sys

% Convert the state-space model to a transfer function
sys_tf = tf(sys);

% Pretty print the transfer function
disp('Transfer function representation:');
sys_tf
