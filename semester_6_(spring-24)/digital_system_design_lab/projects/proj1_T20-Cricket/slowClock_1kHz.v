//Module to slow 100MHz master clock to 1kHz output clock.
`timescale 1ns / 1ps

module slowClock_1kHz(
	input clk_fpga,     // 100MHz master clock 
	output reg clk_1kHz // 1kHz output clock
    );
	 
	 reg [15:0] period_count = 0;	// 2^16 is greater than 50,000
	 
	 // divide the 100MHz clock to 1kHz 
	 always @ (posedge clk_fpga)
	 begin
	 period_count <= period_count + 1'b1;
	 if (period_count == 50_000)
		begin 
		period_count <= 0;	    // count reset itself to zero
		clk_1kHz <= ~clk_1kHz;	// inverts the clock
		end 
	 end
endmodule