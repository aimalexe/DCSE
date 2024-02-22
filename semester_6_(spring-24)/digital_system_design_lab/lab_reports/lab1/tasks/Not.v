module Not(
	output O,
	input I
);
	not n(O, I); // assign O = ~I;
endmodule

module test_Not();
	reg in;
	wire out;

	Not n(.I(in), .O(out)); // implicit association

	initial begin
		$display("I, O");
		in = 0;
		#10 $display("%b, %b", in, out);
		in = 1;
		#10 $display("%b, %b", in, out);
		$stop
	end
endmodule
