
%% Q 1
syms s;
f= ilaplace (3/(s*(s^2+2*s+5)));
pretty(f)
%% Q 2
syms s;
f= ilaplace (1/(s*(s+2)));
pretty(f);
%% Q 3
syms s;
f= ilaplace (1/s*s);
pretty(f);
%% Q 4
 syms s a;
f= ilaplace (1/(s-a)^2);
pretty(f);
%% Q 5
syms f t;
f= laplace (t);
pretty(f);
%% Q 6
syms a t ;
f = cos (a*t);
F = laplace(f);
pretty(F);

%% Q 7
syms t;
f= 1+2*exp(-t)+3*exp(-2*t);
F = laplace(f);
pretty(F);

%% Q 8
syms t;
f = 2*exp(-t) - 2*t*exp(-2*t) - 2*exp(-2*t);
F = laplace(f);
pretty(F);

%% Q 9 (partail fraction)
% (4s^2 + 4s + 4) / s^2(s^2 + 3s + 2)
numerator = [0 0 4 4 4];
denomerator = [1 3 2 0 0];
[r, p , k] = residue(numerator, denomerator)
%% Q10 

syms s V I1 I2 I3;
A=[(2*s+2), -(2*s+1), -1
   -(2*s+1), 9*s+1, -4*s
   -1, -4*s, (4*s + 1 + 1/s)];
%B = [I1; I2; I3];
C = [ V; 0; 0];
B = inv(A) * C;
pretty(B);



