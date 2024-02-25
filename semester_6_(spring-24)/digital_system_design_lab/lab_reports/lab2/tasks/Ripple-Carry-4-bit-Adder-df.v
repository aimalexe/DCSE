
module RippleCarry4BitAdderDataFlow(
    output [3:0] sum,
    output carryOut,
    input [3:0] a,
    input [3:0] b,
    input carryIn
);
    wire [2:0] carryWire;

    FullAdderDataFlow FA0(.S(sum[0]), .CyOut(carryWire[0]), .A(a[0]), .B(b[0]), .CyIn(carryIn));
    FullAdderDataFlow FA1(.S(sum[1]), .CyOut(carryWire[1]), .A(a[1]), .B(b[1]), .CyIn(carryWire[0]));
    FullAdderDataFlow FA2(.S(sum[2]), .CyOut(carryWire[2]), .A(a[2]), .B(b[2]), .CyIn(carryWire[1]));
    FullAdderDataFlow FA3(.S(sum[3]), .CyOut(carryOut), .A(a[3]), .B(b[3]), .CyIn(carryWire[2]));
endmodule

module test_RippleCarry4BitAdderDataFlow;
    wire [3:0] sum;
    wire cyOut;

    reg [3:0] a, b; 
    reg cyIn;

    RippleCarry4BitAdderDataFlow DUT_RCA(sum, cyOut, a, b, cyIn);

    initial begin
        a=4'b0001; b=4'b0110; cyIn=1'b1; #10
        a=4'b1100; b=4'b1010; cyIn=1'b0; #10
        a=4'b0100; b=4'b0001; cyIn=1'b1; #10
        a=4'b0110; b=4'b1100; cyIn=1'b1; #10
        a=4'b1110; b=4'b0100; cyIn=1'b0; #10
        a=4'b1001; b=4'b1100; cyIn=1'b0; #10
        a=4'b1111; b=4'b001; cyIn=1'b1;
	$stop;
    end

    initial 
        $monitor("A:%b=%d, B:%b=%d, CyIn:%b ---> Sum:%b=%d, CyOut:%b", a, a, b, b, cyIn, sum, sum, cyOut);
endmodule 