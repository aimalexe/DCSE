module task2(out,dp,A,B,en);
	output [6:0]out;
	output dp;
	input [3:0]A;
	input [3:0]B;
	input en;
	wire [3:0] sum;
	assign sum=A+B;
	assign dp=en;
	assign out=(sum == 4'b0000) ? 7'b1000000: 
		(sum == 4'b0001) ? 7'b1111001: 
		(sum == 4'b0010) ? 7'b0100100: 
		(sum == 4'b0011) ? 7'b0110000:
		(sum == 4'b0100) ? 7'b0011001: 
		(sum == 4'b0101) ? 7'b0010010:
		(sum == 4'b0110) ? 7'b0000010: 
		(sum == 4'b0111) ? 7'b1111000:
		(sum == 4'b1000) ? 7'b0000000: 
		(sum == 4'b1001) ? 7'b0010000: 7'hff;
endmodule