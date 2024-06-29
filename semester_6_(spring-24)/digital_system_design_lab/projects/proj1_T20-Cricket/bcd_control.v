//Top module to control the seven-segment display
`timescale 1ns / 1ps

module bcd_control(
input clk_fpga, rst,ball_sw, team_sw,inning_over,game_over,winner,
input [7:0] binaryRuns,
input [3:0] wickets,
input [7:0] ball_count,
output [6:0] seg, //Cathodes
output [7:0] AN,  //Anodes 
output dp         //Decimal point
);

     wire clk_1kHz;               
	 wire [3:0] mux_out;
	 wire [2:0] counter_out;
	 wire [3:0] ones1, tens1, hundreds1,ones2, tens2;
	 
     //Converting the binary data of runs and ball count to feed as individual digits to the display
	 binary_to_BCD b1 (binaryRuns, ball_count, ones1, tens1, hundreds1,ones2, tens2);
	 //Generating a 1kHz slow clock from the 100MHz master clock 
	 slowClock_1kHz b2 (clk_fpga, clk_1kHz);
	 //Generating a 3-bit counter to be used as a selector
	 three_bit_counter b3 (clk_1kHz, counter_out);
	 //Turning on one anode and turn off the others on each 100Hz tick of the 3-bit counter 
	 decoder3to8 b4 (counter_out, dp, AN);
	 //Selecting a bcd digit to display on the anode that is turned on 
	 mux8to1 b5 (rst, ball_sw, team_sw,inning_over, game_over, winner, counter_out, wickets, ones1, tens1, hundreds1,ones2, tens2, mux_out);
	 //Displaying the selected digit by using an equivalent 7-bit constant to drive the seven-segment cathodes 
	 bcd_to_7_seg b6 (mux_out, seg);
endmodule

