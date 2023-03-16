%{
Design a function Fib(N) that takes N as an input and generates a Fibonacci sequence for N. Fibonacci
sequence is a tile of squares whose side lengths are successive or each number is the sum of the previous number. 
%}
function fib(n)
    first = 0;
    disp(first);
    second = 1;
    disp(second);
    for i=1 : n
       next = first + second;
       first = second;
       second = next;
       disp(second);
    end