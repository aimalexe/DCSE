module Task_4(
	output z,
	input [4:0] x
);
	wire y1, y2, w;
	
	and a0(y1, x[0], x[1]);
	and a1(y2, x[2], x[3], x[4]);
	or (w, y1, y2);
	not (z, w);
endmodule

module test_Task_4();
	reg [4:0] in;
	wire out;

	Task_4 DUT(out, in);

	initial begin
		$monitor("x1=%b, x2=%b, x3=%b, x4=%b, x5=%b, z=%b", in[0], in[1], in[2], in[3], in[4], out);

		in = 5'b00000; #10
		in = 5'b01010; #10
		in = 5'b10100; #10
		in = 5'b01110; #10
		in = 5'b10001; #10
		in = 5'b11111; #10
		$stop;
	end
endmodule
