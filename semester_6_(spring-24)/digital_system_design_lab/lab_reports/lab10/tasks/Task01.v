//Clock Divider
module Clock_Divider(clock_in,clock_out);
input clock_in;
output reg clock_out;
reg[27:0] counter = 28'd0;

parameter divisor = 28'd1000000;

always @ (posedge clock_in)
begin 
	counter <= counter + 28'd1;
		if(counter >= (divisor -1))
			counter <= 28'd0;

			clock_out <= (counter<divisor/2)?1'b1:1'b0;
		end
	endmodule


//D Flip Flop
module D_FlipFlop(Q,D,clk,rst);
input D; // Data input 
input clk; // clock input 
input rst;
output reg Q; // output Q 
always @(posedge clk or negedge clk) 
begin
if(rst)
	Q = 1'b0;
else
	Q = D; 
end 
endmodule


// synchronizer
module synchronizer(clk, btn,rst, synch_btn);
	input clk;
	input btn;
	input rst;
	output synch_btn;
	 
	wire Q1;
	
	D_FlipFlop df1(Q1, btn, clk, rst);
	D_FlipFlop df2(synch_btn, Q1, clk, rst);
	
endmodule

// level to pulse converter
module level_to_pulse(clk, synch_input, rst, pulse);
	input synch_input;
	input clk;
	input rst;
	output pulse;
	 wire Q;
	 
	 D_FlipFlop df(Q, synch_input, clk, rst);
	 and a(pulse ,~Q, synch_input);
endmodule

module Top(clk,btn,rst,pulse);
	
	input clk,btn,rst;
	output pulse;
	wire synch_btn;
	synchronizer s1(clk, btn,rst, synch_btn);
	level_to_pulse l1(clk, synch_btn, rst, pulse);
endmodule
	
	

//Smart Lock

module Lock(button0, button1, clk, rst, openLock, display);
    input button0, button1, clk, rst;
    output reg openLock;
    output [2:0] display;
    
    parameter S0 = 0, S1 = 1, S2 = 2, S3 = 3, S4 = 4, S5 = 5;
    reg [2:0] state, next_state;
    wire slowclock;
    wire pulse0, pulse1;
    
    Top t1(clk, button0, rst, pulse0);
    Top t2(clk, button1, rst, pulse1);
	 
    
    always @(posedge clk) begin
        if (rst) begin
            openLock <= 0;
            state <= S0;
        end else begin
            state <= next_state;
            case(state)
                S0: begin
						  openLock <= 0;
                    if (pulse0)
                        next_state = S1;
                    else if (pulse1)
                        next_state = S0;
                end
                S1: begin
						  openLock <= 0;
                    if (pulse1)
                        next_state = S2;
                    else if (pulse0)
                        next_state = S1;
                end
                S2: begin
						  openLock <= 0;
                    if (pulse0)
                        next_state = S3;
                    else if (pulse1)
                        next_state = S0;
                end
                S3: begin
							openLock <= 0;
                    if (pulse1)
                        next_state = S4;
                    else if (pulse0)
                        next_state = S1;
                end
                S4: begin
							openLock <= 1;	
                    if (pulse1)
                        next_state = S5;
                    else if (pulse0)
                        next_state = S3;
                end
                S5: begin
							openLock <= 0;
                    if (pulse1)
                        next_state = S0;
                    else if (pulse0)
                        next_state = S1;
                end
            endcase
        end
    end
    
    assign display = state;
    
endmodule


module BCD7_seg(COUNT,OUT);

	input [2:0] COUNT;
	output reg [7:0] OUT;
	
	always @(*)
	
			case({1'b0,COUNT})
					4'b0000 : OUT = 8'b10000001;//0
					4'b0001 : OUT = 8'b11110011;//1
					4'b0010 : OUT = 8'b01001001;//2
					4'b0011 : OUT = 8'b01100001;//3
					4'b0100 : OUT = 8'b00110011;//4
					4'b0101 : OUT = 8'b00100101;//5
					4'b0110 : OUT = 8'b00000101;//6
					default : OUT = 8'b11111111;//default
					endcase
endmodule

module Task01(clk,rst,btn0,btn1,out,seg);
		input clk,rst,btn0,btn1;
		output out;
		output [7:0] seg;
		
		wire slow_clock;
		wire [2:0] display;
		
		Clock_Divider c1(clk,slow_clock);
		Lock l1(btn0, btn1, slow_clock, rst, out,display);
		BCD7_seg b1(display,seg);
endmodule
