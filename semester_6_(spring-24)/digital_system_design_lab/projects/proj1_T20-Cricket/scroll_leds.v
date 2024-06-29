//Module to scroll leds for celebration after game is over
`timescale 1ns / 1ps

module scroll_leds(
    input clk_fpga,
    input game_over,
    output reg [15:0] led);
	 
	 wire clk_10Hz; //10Hz signal from slow clock
	 
	 //Shift an led every rising edge 
	 always @ (posedge clk_10Hz)	
	 begin 
	 if (~game_over)
	     led <= 16'd0;
	 else
		 if (led == 16'hffff)
			led <= 16'hfffe; //Reset to 8'b1111 1110 
		 else
			led <= {led[15:0], 1'b1}; //Shift the rightmost unlit led in 8'hfe to the left 
	 end
	 
	 //Slowing 100MHz master clock to 10Hz output clock
	 slowClock_10Hz c0 (clk_fpga, clk_10Hz);
endmodule