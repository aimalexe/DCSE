`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:24:48 05/22/2024 
// Design Name: 
// Module Name:    traffic_light 
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
module Traffic_lights(clk,rst,v,out_farm,out_highway);
	input clk,rst,v;
	output reg [2:0] out_farm, out_highway;
	reg [1:0] PS,NS;
	parameter [1:0] FR_HG = 2'd0, FY_HR = 2'd1, FG_HR = 2'd2, FR_HY = 2'd3;
	parameter [2:0] red = 3'b100, yellow = 3'b010, green = 3'b001;
	wire out_clk;
	
	clk_divider d1(clk,out_clk,rst);
	
	always @(posedge out_clk)
		if(rst==0)
		begin
			PS = FR_HG;
		end
		else
			PS = NS;
			
	always @(PS or v or rst)
		case(PS)
			FR_HG:
			begin
				NS = v?FY_HR: FR_HG;
				out_highway = v?red:green;
				out_farm = v?yellow:red;
			end
			FY_HR:
			begin
				NS = FG_HR;
				out_highway = red;
				out_farm = green;
			end
			FG_HR:
			begin
				NS = FR_HY;
				out_highway = yellow;
				out_farm = red;
			end
			FR_HY:
			begin
				NS = FR_HG;
				out_highway = green;
				out_farm = red;
			end
				
		endcase
endmodule

module clk_divider(input in_clk,output reg out_clk, input rst);
	reg [100:0] count;
	always @(posedge in_clk)
		if(rst==0)
		begin
			out_clk = 0;
			count = 0;
		end	
		else
		begin
			count = count+1;
			if(count==3*100000000)
			begin
				out_clk = ~out_clk;
				count = 0;
			end
		end
endmodule
