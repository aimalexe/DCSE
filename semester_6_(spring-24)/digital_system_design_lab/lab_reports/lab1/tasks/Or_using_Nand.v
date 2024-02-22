module Or_using_Nand(
	output O,
	input A,
	input B
);
	wire wA, wB;

	nand n1(wA, A);
	nand n2(wb, B);
	nand n3(O, wA, wB);

endmodule

module test_Or_using_Nand();
	reg in1, in2;
	wire out;
	
	Or_using_Nand o(out, in1, in2);

	initial begin
		$display("I1, I2, O");

		in1 = 1; in2 = 1;
		#10 $display("%b, %b, %b", in1, in2, out);

		in1 = 0; in2 = 0;
		#10 $display("%b, %b, %b", in1, in2, out);

		in1 = 0; in2 = 1;
		#10 $display("%b, %b, %b", in1, in2, out);

		in1 = 1; in2 = 0;
		#10 $display("%b, %b, %b", in1, in2, out);
		$stop;
	end
endmodule
