//Module to generate a 3-bit counter to be used as a selector
`timescale 1ns / 1ps

module three_bit_counter(
	 input clk,         // input clock 
	 output reg [2:0] Q // 3-bit register
    );
    
	 //On each positive edge of the input clock, count up from 0 to 7, and wrap around from 7 back to 0
	 always @ (posedge clk)	begin
	 Q <= Q + 1'b1; 
	 end 
endmodule