%{
6.7 Write the MATLAB code to convert the given transfer function to 
the state-space representation.

          s^2 + 7s + 2
F(s) = ---------------------
        s^3 + 9s^2 + 26s + 24

%}

% Define the numerator and denominator of the transfer function
numerator = [1 7 2];
denominator = [1 9 26 24];

% Create the transfer function model
F = tf(numerator, denominator);

% Display the transfer function
disp('Transfer function representation:');
F

% Convert the transfer function to state-space representation
[A, B, C, D] = tf2ss(numerator, denominator);

% Display the state-space matrices
disp('State-space representation:');
disp('Matrix A:');
disp(A);
disp('Matrix B:');
disp(B);
disp('Matrix C:');
disp(C);
disp('Matrix D:');
disp(D);
