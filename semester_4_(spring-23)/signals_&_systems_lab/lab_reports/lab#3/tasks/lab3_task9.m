%{
Consider the following script file. Fill in the lines of the following table with the values
that would be displayed immediately after the while statement if you ran the script file. Write in the
values the variables have each time the while statement is executed. You might need more or fewer lines in the
table. Then type in the file, and run it to check your answers. 
%}
clc;
clear;

k = 1;
b = -2;
x = -1;
y = -2; 

while k <= 5
    fprintf('k: %d, b: %d, x: %d, y: %d\n', k, b, x, y );
    y = x^2 - 3;
    if y < b
        b = y;
    end
    x = x + 1;
    k = k + 1;
end
