`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:59:11 03/27/2024 
// Design Name: 
// Module Name:    eight_bit_rc_BCD 
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
module four_bit_rc(clk,rst,count);
input clk,rst;
output [7:0]count;
reg [7:0]count;
always @(posedge clk)
	begin 
		if(rst)
			count <= 8'b10000000;
		else 
			begin 
				count <= count << 1;
				count[0] <= count[7];
			end
		end 
endmodule


module BCD(count,seg);
input [7:0]count;
output [10:0]seg;
reg [10:0]seg;
always @(*)
	begin
		case(count)
			8'b00000001: seg = 11'b10011110011;
			8'b00000010: seg = 11'b00100100011;
			8'b00000100: seg = 11'b00001100011;
			8'b00001000: seg = 11'b10011000011;
			8'b00010000: seg = 11'b01001000011;
			8'b00100000: seg = 11'b01000000011;
			8'b01000000: seg = 11'b00011110011;
			default:     seg = 11'b00000000011;
		endcase
	end
endmodule

module top(clk,rst,seg);
input clk,rst;
output [10:0] seg;
wire [7:0] count;
four_bit_rc t1(clk,rst,count);
BCD b1(count,seg);
endmodule
