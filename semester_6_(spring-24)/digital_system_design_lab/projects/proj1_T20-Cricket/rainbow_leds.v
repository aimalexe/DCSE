//Module to produce rainbow effect with tri-state leds for celebration after game is over 
`timescale 1ns / 1ps

module rainbow_leds(
	input clk, game_over,
	output red, grn, blu);

	reg [26:0] counter;
	wire [11:0] t;
	wire [11:0] cmp;
	assign t[11:0] = counter[11:0];
	assign cmp[11:0] = counter[23:12];
	wire [2:0] step;
	assign step[2:0] = counter[26:24];

	reg [2:0] amask;
	reg [2:0] bmask;
	wire [2:0] mask;
	assign mask = (t > cmp) ? amask : bmask;

	assign red = mask[0];
	assign grn = mask[1];
	assign blu = mask[2];
	
	always @(*) begin
	if(game_over)
		case (step)
			0: amask <= 3'b100;
			1: amask <= 3'b110;
			2: amask <= 3'b010;
			3: amask <= 3'b011;
			4: amask <= 3'b001;
			5: amask <= 3'b101;
			default: amask <= 3'b000;
		endcase
	end

	always @(*) begin
	if(game_over)
		case (step)
			0: bmask <= 3'b110;
			1: bmask <= 3'b010;
			2: bmask <= 3'b011;
			3: bmask <= 3'b001;
			4: bmask <= 3'b101;
			5: bmask <= 3'b100;
			default: bmask <= 3'b111;
		endcase
	end

	always @(posedge clk) begin
	if(game_over)
		counter <= (step > 5) ? 0 : (counter + 1);
	end
endmodule


