`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:36:03 04/26/2024 
// Design Name: 
// Module Name:    ThreebitUPCount 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////

module Clock_Divider(clock_in,clock_out);
	input clock_in;
	output reg clock_out;
	reg [27:0] counter = 28'd0;
	parameter DIVISOR = 28'd100000000;
	

	always @(posedge clock_in)
	begin
		counter <= counter + 28'd1;
		if(counter>=(DIVISOR-1))
			counter <=28'd0;
		clock_out <= (counter>DIVISOR/2)?1'b1:1'b0;
	end
endmodule

module ThreebitUPCount(clock_in,Rst,COUNT);
	
	input clock_in,Rst;
	output reg [2:0] COUNT;
	wire clock_out;
	
	Clock_Divider c(clock_in,clock_out);
	
	always @(posedge clock_out)
	begin
			if(Rst)
					COUNT <= 3'b000;
			else
					COUNT <= COUNT + 1;
	end


endmodule

module BCD7_seg(OUT,COUNT);

	input [2:0] COUNT;
	output reg [11:0] OUT;
	
	always @(*)
	
			case({1'b0,COUNT})
					4'b0000 : OUT = 11'b 11111001011;
					4'b0001 : OUT = 11'b 10100100011;
					4'b0010 : OUT = 11'b 10100100011;
					4'b0011 : OUT = 11'b 10100100011;
					4'b0100 : OUT = 11'b 10110000011;
					4'b0101 : OUT = 11'b 10011001011;
					4'b0110 : OUT = 11'b 10010010011;
					4'b0111 : OUT = 11'b 10000010011;
					default : OUT = 11'b 11111111111;
					endcase
endmodule

module Top_Module(clock,Rst,Seg);

	input clock,Rst;
	output [10:0] Seg;
	
	wire [2:0] count;
	
	ThreebitUPCount u1(clock,Rst,count);
	BCD7_seg s1(Seg,count);
	
endmodule

