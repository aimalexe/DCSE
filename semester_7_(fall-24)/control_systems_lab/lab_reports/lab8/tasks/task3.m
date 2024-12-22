% task 2
% unstable system example
num = [1 3];
denum = [2 -7 37];

[z, p, k] = tf2zp(num, denum)

zplane(z, p);

poly(p) %