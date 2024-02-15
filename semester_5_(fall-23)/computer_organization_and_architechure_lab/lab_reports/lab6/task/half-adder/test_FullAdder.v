module simulateFullAdder();
reg input1, input2, carryIn;

wire sum, carryOut;
FullAdder fa(input1, input2, carryIn, sum, carryOut);

initial
begin
$display("I1, I2, Cin, Sum, Cout");

input1 = 0;
input2 = 0;
carryIn = 0;
#10
$display("%b, %b, %b, %b, %b", input1, input2, carryIn, sum, carryOut);

input1 = 1;
input2 = 0;
carryIn = 0;
#10
$display("%b, %b, %b, %b, %b", input1, input2, carryIn, sum, carryOut);

input1 = 0;
input2 = 1;
carryIn = 0;
#10
$display("%b, %b, %b, %b, %b", input1, input2, carryIn, sum, carryOut);

input1 = 1;
input2 = 1;
carryIn = 0;
#10
$display("%b, %b, %b, %b, %b", input1, input2, carryIn, sum, carryOut);

input1 = 0;
input2 = 0;
carryIn = 1;
#10
$display("%b, %b, %b, %b, %b", input1, input2, carryIn, sum, carryOut);

input1 = 1;
input2 = 0;
carryIn = 1;
#10
$display("%b, %b, %b, %b, %b", input1, input2, carryIn, sum, carryOut);

input1 = 0;
input2 = 1;
carryIn = 1;
#10
$display("%b, %b, %b, %b, %b", input1, input2, carryIn, sum, carryOut);

input1 = 1;
input2 = 1;
carryIn = 1;
#10
$display("%b, %b, %b, %b, %b", input1, input2, carryIn, sum, carryOut);

end
endmodule
