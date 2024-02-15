module simulateHalfAdder();
reg input1, input2;
wire sum, carry;

HalfAdder ha(input1, input2, sum, carry);

initial
begin 
$display("I1, I2, Sum, Carry");

input1 = 0;
input2 = 0;
#10
$display("%b, %b, %b, %b", input1, input2, sum, carry);

input1 = 0;
input2 = 1;
#10
$display("%b, %b, %b, %b", input1, input2, sum, carry);

input1 = 1;
input2 = 0;
#10
$display("%b, %b, %b, %b", input1, input2, sum, carry);

input1 = 1;
input2 = 1;
#10
$display("%b, %b, %b, %b", input1, input2, sum, carry);

end
endmodule;
