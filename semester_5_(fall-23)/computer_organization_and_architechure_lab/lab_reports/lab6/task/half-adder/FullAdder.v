module FullAdder(input1, input2, carryIn, sum, carryOut);
input input1, input2, carryIn;
output sum, carryOut;

wire sum1, carry1, carry2;

HalfAdder ha1(input1, input2, sum1, carry1);
HalfAdder ha2(carryIn, sum1, sum, carry2);

or orGate(carryOut, carry1, carry2);

endmodule;