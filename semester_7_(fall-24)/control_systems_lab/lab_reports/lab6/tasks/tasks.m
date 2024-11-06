%{
Frequency Domain Modeling in MATLAB
This script calculates the inverse and direct Laplace transforms for various functions.
Each section corresponds to a specific question, and each question is labeled accordingly.
%}

%% Q1
% Question 1: Find the inverse Laplace transform of F(s) = 3 / (s * (s^2 + 2s + 5))
% This section defines the function and uses ilaplace to find its inverse transform.
syms s;
f = ilaplace(3 / (s * (s^2 + 2 * s + 5)));
pretty(f)

%% Q2
% Question 2: Find the inverse Laplace transform of F(s) = 1 / (s * (s + 2))
% Uses ilaplace to compute the inverse Laplace transform of the given function.
syms s;
f = ilaplace(1 / (s * (s + 2)));
pretty(f);

%% Q3
% Question 3: Find the inverse Laplace transform of F(s) = 1 / s^2
% Uses ilaplace to compute the inverse Laplace transform.
syms s;
f = ilaplace(1 / s^2);
pretty(f);

%% Q4
% Question 4: Find the inverse Laplace transform of F(s) = 1 / (s - a)^2
% Computes the inverse transform using the variable 'a'.
syms s a;
f = ilaplace(1 / (s - a)^2);
pretty(f);

%% Q5
% Question 5: Find the Laplace transform of f(t) = t
% Uses laplace to transform a simple linear function in time.
syms f t;
f = laplace(t);
pretty(f);

%% Q6
% Question 6: Find the Laplace transform of f(t) = cos(a * t)
% Computes the Laplace transform of a cosine function with frequency 'a'.
syms a t;
f = cos(a * t);
F = laplace(f);
pretty(F);

%% Q7
% Question 7: Find the Laplace transform of f(t) = 1 + 2e^(-t) + 3e^(-2t)
% Uses laplace to transform a sum of exponential functions.
syms t;
f = 1 + 2 * exp(-t) + 3 * exp(-2 * t);
F = laplace(f);
pretty(F);

%% Q8
% Question 8: Find the Laplace transform of f(t) = 2e^(-t) - 2t * e^(-2t) - 2e^(-2t)
% Computes the Laplace transform for a combination of exponential and linear-exponential terms.
syms t;
f = 2 * exp(-t) - 2 * t * exp(-2 * t) - 2 * exp(-2 * t);
F = laplace(f);
pretty(F);

%% Q9 (Partial Fraction Expansion)
% Question 9: Perform partial fraction expansion for F(s) = (4s^2 + 4s + 4) / (s^2 * (s^2 + 3s + 2))
% This section uses the residue function for partial fraction decomposition.
numerator = [0 0 4 4 4];
denominator = [1 3 2 0 0];
[r, p, k] = residue(numerator, denominator)

%% Q10
% Question 10: Solve a system of equations using symbolic variables and matrix inversion
% The system is set up and solved using symbolic operations for each current I1(s), I2(s), and I3(s).
syms s V I1 I2 I3;
A = [(2 * s + 2), -(2 * s + 1), -1;
     -(2 * s + 1), 9 * s + 1, -4 * s;
     -1, -4 * s, (4 * s + 1 + 1 / s)];
C = [V; 0; 0];
B = inv(A) * C;
pretty(B);
