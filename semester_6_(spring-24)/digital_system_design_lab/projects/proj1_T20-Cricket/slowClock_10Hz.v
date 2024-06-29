//Module to slow 100MHz master clock to 10Hz output clock
`timescale 1ns / 1ps

module slowClock_10Hz(
    input clk_fpga,	// 100MHz master clock 
    output reg clk_10Hz	// 10Hz output clock
    );
	 
	 reg [22:0] period_count = 0;	// 2^23 is greater than 5,000,000 

	 // divide the 100MHz clock to 10Hz 
	 always @ (posedge clk_fpga)
	 begin
	 period_count <= period_count + 1'b1;
	 if (period_count == 5_000_000)
		begin 
		period_count <= 0;	    // count reset itself to zero
		clk_10Hz <= ~clk_10Hz;	// inverts the clock
		end 
	 end
endmodule