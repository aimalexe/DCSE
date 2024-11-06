%{
6.3 Write the MATLAB code for the conversion of a transfer function to the state space representation 
of the following system:

            8s + 10
G(s) = ---------------------
        s^4 + 5s^3 + s^2 + 5s + 13

%}

% Define the numerator and denominator of the transfer function
numerator = [8 10];
denominator = [1 5 1 5 13];

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
