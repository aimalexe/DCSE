module Buffer(
	output O,
	input I
);
	// behaviour level modeling: `assign O = A & B;`
	// gate level modeling: `and a1(O, A, B);`

	buf b1(O, I); // assign O = I;

endmodule

module test_Buffer();
	reg in;
	wire out;

	Buffer b1(out, in); // implicit association
	
	initial
	begin
		in = 0; #10
		in = 1; 
		$stop;
	end

	initial 
		$monitor("Input=%b, Output=%b", in, out);
endmodule 