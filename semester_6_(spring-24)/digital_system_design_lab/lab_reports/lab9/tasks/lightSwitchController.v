//clock_divider
module clock_divider(
 input clk_in, 
 output reg clk_out
);
 reg [27:0] counter = 28'd0;
parameter divisor = 28'd1000000; 
always @(posedge clk_in) begin
counter <= counter + 28'd1;
 
if (counter >= (divisor - 1)) 
 counter <= 28'd0;
clk_out <=(counter < divisor/2)?1'b1:1'b0; 
end
endmodule 



// Synchronizer
module synchronizer(input clk, input btn, input rst, output synch_btn);
 wire Q1;
 D_FF df1(Q1, btn, clk, rst);
 D_FF df2(synch_btn, Q1, clk, rst);
endmodule




// D_FlipFlop
module D_FF(Q, D, clk, rst);
 input D; // Data input
 input clk; // Clock input
 input rst;
 output reg Q; // Output Q
 always @(posedge clk or negedge clk) begin
 if (rst)
 Q = 1'b0;
 else
 Q = D;
 end
endmodule




module fsm(input btn0,
 input clk,
 input RST_BTN,
 output reg led);
 reg [2:0] presentState, nextState;
 parameter s0 = 3'b0, s1 = 3'b1;
 always @(posedge clk)
 presentState <= nextState;
 always @(nextState or btn1 or RST_BTN) begin
 if (RST_BTN)
 nextState <= s0;
 else
 case (presentState)
 s0: nextState <= btn0 ? s1 : s0;
 s1: nextState <= btn0 ? s0 : s1;
 endcase
 end
 assign led = (presentState == s1);
endmodule
module level_to_pulse(
input synch_input,
input clk,
input rst,
output pulse
 );
wire Q;
 D_FF df(Q, synch_input, clk, rst);
and a(pulse ,~Q, synch_input);
endmodule





module btn_module(
input btn,
input CLK,
input RST,
output pulse
 );
wire synch_btn;
synchronizer s1(CLK, btn, RST, synch_btn);
level_to_pulse lp1(synch_btn, CLK, RST, pulse);
endmodule
module Top( CLK, RST, RST_BTN, , BTN, LED, SEVENSEG);
input CLK, RST, BTN, RST_BTN;
output LED;
wire SLOW_CLOCK;
wire pulse0, pulse1, RST_Pulse;
wire [3:0]bcd;
clock_divider divider(CLK, SLOW_CLOCK);
fsm my_fsm( pulse1, SLOW_CLOCK, RST_Pulse, LED, bcd);
btn_module b0(BTN, SLOW_CLOCK, RST, pulse1);
btn_module b2(RST_BTN, SLOW_CLOCK, RST, RST_Pulse);
endmodule
