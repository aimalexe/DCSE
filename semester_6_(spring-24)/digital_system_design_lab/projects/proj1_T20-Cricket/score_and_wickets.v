//Module to generate individual team data consisting of runs and wickets
`timescale 1ns / 1ps

module score_and_wickets(
    input clk,reset,delivery, team_sw,inning_over,
    input [3:0] lfsr_out,
    input gameOver,
    input winner,
    output reg [7:0] runs,
    output reg [3:0] wickets,
    output reg [11:0] team1Data, //Stores and updates teaml's runs and wickets when inning_over is 0
    output reg [11:0] team2Data  //Stores and updates team2's runs and wickets when inning_over is 1 
    );
	 
	 localparam single = 16;
	 localparam double = 32;
	 localparam triple = 48;
	 localparam four = 64;
	 localparam six = 96;
	 
	 //Update score after each delivery(bowl) based on cricket rule.
	 always @ (posedge delivery)
	 begin
			   if(~inning_over && ~gameOver && ~team_sw && ~reset) //Increment score of team 1 
					begin
					case (lfsr_out) //Pseudorandom number from linear feedback shift register
						0:	    team1Data <= team1Data;           //Dot ball
						1,5:	team1Data <= team1Data + single;  //Single and wide ball
						2:	    team1Data <= team1Data + double;  //Two runs
						3:		team1Data <= team1Data + triple;  //Three runs
						4:		team1Data <= team1Data + four;    //Four runs
						6:		team1Data <= team1Data + six;     //Six runs
						7:	    team1Data <= team1Data;           //No ball
						8:		team1Data <= team1Data + 1;       //Wicket
					endcase          
					runs <= team1Data[11:4];   //First 8-bits store information of runs
					wickets <= team1Data[3:0]; //Last 4-bits store information of wickets
				end
				else if(inning_over && ~gameOver && ~team_sw && ~reset) //Increment score of team 2
					begin
					case (lfsr_out) //Pseudorandom number from linear feedback shift register
						0:	    team2Data <= team2Data;			  //Dot ball
						1,5:	team2Data <= team2Data + single;  //Single and wide ball
						2:	    team2Data <= team2Data + double;  //Two runs
						3:		team2Data <= team2Data + triple;  //Three runs
						4:		team2Data <= team2Data + four;    //Four runs
						6:		team2Data <= team2Data + six;     //Six runs
						7:	    team2Data <= team2Data;			  //No ball
						8:		team2Data <= team2Data + 1;		  //Wicket
					endcase
					runs <= team2Data[11:4];   //First 8-bits store information of runs
					wickets <= team2Data[3:0]; //Last 4-bits store information of wickets
				end
			
			//If game is over, display score of team which won		
			if (gameOver)
			begin
				case (winner)
				0: begin
					runs <= team1Data[11:4];
					wickets <= team1Data[3:0];
					end
				1: begin
					runs <= team2Data[11:4];
					wickets <= team2Data[3:0];
					end
				endcase
			end
			
			//Switching teams back and forth to check scores by pressing btnD and btnU
			if (team_sw) 
				begin
				if (~gameOver) begin
				case (inning_over)
				1: begin
					runs <= team1Data[11:4];
					wickets <= team1Data[3:0];
					end
				0: begin
					runs <= team2Data[11:4];
					wickets <= team2Data[3:0];
					end
				endcase
				end
				if (gameOver) begin
				case (winner)
				1: begin
					runs <= team1Data[11:4];
					wickets <= team1Data[3:0];
					end
				0: begin
					runs <= team2Data[11:4];
					wickets <= team2Data[3:0];
					end
				endcase
				end
			end

	        //Re-inititiallize scores if reset
	        if (reset)
			begin
			runs <= 0;
			wickets <= 0;
			team1Data <= 0;
			team2Data <= 0;
			end
	end
endmodule