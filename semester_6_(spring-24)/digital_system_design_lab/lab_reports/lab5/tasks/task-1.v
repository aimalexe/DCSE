module task01(
	output [6:0] out,
	output dp,
	input [3:0] in,
	input en
);
	assign dp= en;
	assign out= (in== 4'b0000) ? 7'b1000000:
            (in== 4'b0001) ? 7'b1111001:
            (in== 4'b0010) ? 7'b0100100:
            (in== 4'b0011) ? 7'b0110000:
            (in== 4'b0100) ? 7'b0011001:
            (in== 4'b0101) ? 7'b0010010:
            (in== 4'b0110) ? 7'b0000010:
            (in== 4'b0111) ? 7'b1111000:
            (in== 4'b1000) ? 7'b0000000:
                            7'b0010000;
endmodule
