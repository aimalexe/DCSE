%{
Matlab stores numeric data as double?precision floating-point by default. To store data 
as an 8? bit integer, int8 (a conversion function) can be used. Type the sample code in 
MatLab command window:
>> x = 26 
>> whos 
>> y = int8(x) 
>> whos 
What difference do you see? State your findings. (Also try uint16, uint32, uint64)
b. Take your name in the command window e.g. name = ‘Ali’. Convert it into 8?bit integer 
format using the int8 function.
c. Use the formatting commands present in MatLab to convert the system Clock to whole 
numbers rather than floating points.
%}

clc;
clear;

% a.
x = 5;
whos;

y = int8(x);
whos;

% b.
name = input('Who are you? ');
nameInInt8 = int8(name);
display(nameInInt8);

% c.
clock;
fix(clock)
