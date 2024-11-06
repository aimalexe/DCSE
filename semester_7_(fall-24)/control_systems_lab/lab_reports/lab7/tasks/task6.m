%{
6.6 Write the MATLAB code for the conversion of state space representation to 
the transfer function for the following:

      [ 3  1  0  4 -2]
      [-3  5 -5  2 -1]
A =   [ 0  1 -1  2  8]
      [-7  6 -3 -4  0]
      [-6  0  4 -3  1]

B = [2; 7; 8; 5; 4]

C = [1 -2 -9 7 6]

D = 0
%}

% Define matrix A
A = [ 3  1  0  4 -2;
     -3  5 -5  2 -1;
      0  1 -1  2  8;
     -7  6 -3 -4  0;
     -6  0  4 -3  1];

% Define matrix B
B = [2; 7; 8; 5; 4];

% Define matrix C
C = [1 -2 -9 7 6];

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
