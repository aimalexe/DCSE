`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:29:45 04/24/2024 
// Design Name: 
// Module Name:    mod10_counter 
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
module mod10_counter( CLOCK, CLR, Q  );


	input CLOCK, CLR; //Clock and Reset
	output [3:0] Q; //BCD output
	
	reg [3:0] Q;

	always @(negedge CLOCK)	
		if (CLR | Q==4'd9) //BCD or Mod-10 Counter
		
			Q <= 4'd0;
		else
			Q <= Q + 1;

endmodule


module three_BCD (CLOCK, CLR, BCDu, BCDt, BCDh);
	
	input CLOCK, CLR;
	output [3:0] BCDu, BCDt, BCDh; //u=UNITS, t=TENS, h=HUNDREDS
	
	mod10_counter bcdu (CLOCK, CLR, BCDu[3:0]);
	mod10_counter bcdt (BCDu[3], CLR, BCDt[3:0]);
	mod10_counter bcdh (BCDt[3], CLR, BCDh[3:0]);

endmodule


// fpga4student.com: FPGA projects, VHDL projects, Verilog projects
// Verilog project: Verilog code for clock divider on FPGA
// Top level Verilog code for clock divider on FPGA
module Clock_Divider(clock_in,clock_out);
	input clock_in; // input clock on FPGA
	output reg clock_out; // output clock after dividing the input clock by divisor
	reg[27:0] counter=28'd0;
	parameter DIVISOR = 28'd100000000;
// The frequency of the output clk_out
//  = The frequency of the input clk_in divided by DIVISOR
// For example: Fclk_in = 50Mhz, if you want to get 1Hz signal to blink LEDs
// You will modify the DIVISOR parameter value to 28'd50.000.000
// Then the frequency of the output clk_out = 50Mhz/50.000.000 = 1Hz
	always @(posedge clock_in)
	begin
		counter <= counter + 28'd1;
		if(counter>=(DIVISOR-1))
			counter <= 28'd0;
		clock_out <= (counter<DIVISOR/2)?1'b1:1'b0;
	end
endmodule


module Counter18bit(clk, rst, count);
	input clk,rst;
	output reg [17:0]count;
	
	always @(posedge clk)
    if (rst)
      count <= 18'b000000000000000000;
    else if(count == 18'b111111111111111111)
	   count <= 18'b000000000000000000;
	else
      count <= count + 1;

endmodule

module decoder2x4(in, out);
  input [1:0] in;
  output reg [3:0] out;
  
  always @(*) begin
    case (in)
      2'b00: out = 3'b110;
      2'b01: out = 3'b101;
      2'b10: out = 3'b011;
     default: out = 3'b111;
	  endcase
	 end
endmodule


module mux4x1 (
  input [7:0] bcd0,
  input [7:0] bcd1,
  input [7:0] bcd2,
  input [1:0] select,
  output reg [7:0] out
);

  always @(*) begin
    case (select)
      2'b00: out = bcd0;
      2'b01: out = bcd1;
      2'b10: out = bcd2;
      default: out = 8'b00000000;
    endcase
  end

endmodule

module BCD_to_7Seg (bcd, seg);
  input [3:0] bcd;
  output reg [7:0] seg;

  always @(*) begin
    case(bcd)
      4'b0000: seg = 8'b10000001; // 0
      4'b0001: seg = 8'b11110011; // 1
      4'b0010: seg = 8'b01001001; // 2
      4'b0011: seg = 8'b01100001; // 3
      4'b0100: seg = 8'b00110011; // 4
      4'b0101: seg = 8'b00100101; // 5
      4'b0110: seg = 8'b00000101; // 6
      4'b0111: seg = 8'b11110001; // 7
      4'b1000: seg = 8'b00000001; // 8
      4'b1001: seg = 8'b00100001; // 9
      default: seg = 8'b11111111; // Error or Blank 
    endcase
  end
endmodule


module TopMultiplex(
    input clk,
    input rst,
    output  [3:0] out_dec,
    output  [7:0] out_mux
);
    wire slow_clock;
    wire [17:0] counter_out;
    wire [3:0] BCDu, BCDt, BCDh;
    wire [7:0] bcd1, bcd2, bcd3;

    Counter18bit cnt(clk, rst, counter_out);
    Clock_Divider divider(clk, slow_clock);
	 

			three_BCD three_BCD_Counters(slow_clock, rst, BCDu, BCDt, BCDh);
			BCD_to_7Seg B1(BCDu, bcd1);
			BCD_to_7Seg B2(BCDt, bcd2);
			BCD_to_7Seg B3(BCDh, bcd3);

	
    mux4x1 MUX(bcd1, bcd2, bcd3, counter_out[17:16], out_mux);
    decoder2x4 d1(counter_out[17:16], out_dec);

endmodule

