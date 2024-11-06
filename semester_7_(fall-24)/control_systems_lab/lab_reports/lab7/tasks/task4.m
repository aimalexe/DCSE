%{
6.4 Write the MATLAB code for the conversion of a transfer function to the state space representation 
of the following system:

              s^4 + 2s^3 + 12s^2 + 7s + 6
G(s) = -----------------------------------------
          s^5 + 9s^4 + 13s^3 + 8s^2

%}

% Define the numerator and denominator of the transfer function
numerator = [1 2 12 7 6];
denominator = [1 9 13 8 0 0];  % Adding zeros to match the highest order of s^5

% Create the transfer function model
G = tf(numerator, denominator);

% Display the transfer function
disp('Transfer function representation:');
G

% Convert the transfer function to state-space representation
[sys_A, sys_B, sys_C, sys_D] = tf2ss(numerator, denominator);

% Display the state-space matrices
disp('State-space representation:');
disp('Matrix A:');
disp(sys_A);
disp('Matrix B:');
disp(sys_B);
disp('Matrix C:');
disp(sys_C);
disp('Matrix D:');
disp(sys_D);
