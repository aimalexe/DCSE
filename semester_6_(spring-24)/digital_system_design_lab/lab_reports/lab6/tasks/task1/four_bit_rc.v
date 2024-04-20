`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:32:42 03/27/2024 
// Design Name: 
// Module Name:    four_bit_rc 
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
output [3:0]count;
reg [3:0]count;
always @(posedge clk)
	begin 
		if(rst)
			count <= 4'b1000;
		else 
			begin 
				count <= count << 1;
				count[0] <= count[3];
			end
		end 
endmodule

