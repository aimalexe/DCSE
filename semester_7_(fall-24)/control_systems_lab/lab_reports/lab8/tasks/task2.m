% task 2
% stable system example
num = [1 1];
denum = [5 8 30];

[z, p, k] = tf2zp(num, denum)

zplane(z, p);

poly(p) %
