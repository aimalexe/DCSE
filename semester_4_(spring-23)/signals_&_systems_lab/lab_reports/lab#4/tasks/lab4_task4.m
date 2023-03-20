%{
Plot the two curves y1 = 2x .^2 and y2 = 4x .^3 on the same graph using different plot styles.
a) Use x as a 31 entries sequence from -15:15. 
b) Use x as a 101 entries sequence from -50:50. 
(Hint: use plot(x,y1,'b--o',x,y2,'c*') or same with subplots or same with multiple stems) .
%}

clc;
clear;
% a)
x1 = -15: 15;
y1 = 2*x1 .^ 2;
y2 = 4*x1 .^ 3;
figure(1)
subplot(2,2, 1)
plot(x1,y1,'b--o',x1,y2,'c*')
% b)
x2 = -50 : 50;
y3 = 2*x2 .^ 2;
y4 = 4*x2 .^ 3;
subplot(2,2,2)
plot(x2,y3,'g--o',x2,y4,'c*')