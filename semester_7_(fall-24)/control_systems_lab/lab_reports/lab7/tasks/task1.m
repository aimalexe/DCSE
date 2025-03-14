%{
6.1 Use the MATLAB code to form an LTI state space representation from the transfer function. 
The matrix A, B, and C are shown below:

x_dot = A * x + B * r
y = C * x

A = [0  1  0;
     0  0  1;
    -24 -26 -9]

B = [0; 0; 1]

C = [2 7 1]

%}

% Define matrix A
A = [0  1  0;
     0  0  1;
    -24 -26 -9];

% Define matrix B
B = [0; 0; 1];

% Define matrix C
C = [2 7 1];

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
