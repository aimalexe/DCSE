module HalfAdder(input1, input2, sum, carry);

input input1, input2;
output sum, carry;

xor xorGate(sum, input1, input2);
and andGate(carry, input1, input2);

endmodule;
