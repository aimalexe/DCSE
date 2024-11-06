%{
6.5 Write the MATLAB code for the conversion of state space representation to 
the transfer function for the following:

      [0  1  5  0]
      [0  0  1  0]
A =   [0  0  0  1]
      [-7 -9 -2 -3]

B = [0; 5; 8; 2]

C = [1  3  6  6]

D = 0
%}

% Define matrix A
A = [0  1  5  0;
     0  0  1  0;
     0  0  0  1;
    -7 -9 -2 -3];

% Define matrix B
B = [0; 5; 8; 2];

% Define matrix C
C = [1 3 6 6];

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
