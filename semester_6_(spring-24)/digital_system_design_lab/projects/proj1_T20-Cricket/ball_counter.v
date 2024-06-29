//Module to count the number of deliveries that are bowled (excluding no balls and wides)
`timescale 1ns / 1ps

module ball_counter(
input clk, rst, ball_sw, team_sw, 
input [3:0] lfsr_out,
input inning_over, game_over, winner,
output reg [7:0] ball_count,  //Output register sending data to score_comparator and bcd_control modules
output reg [7:0] t1_balls,    //Register to store Team 1 balls
output reg [7:0] t2_balls     //Register to store Team 2 balls
);

//Count every positive edge of debounced btnU
always @(posedge ball_sw) begin
    //Exclude count when button is pressed in combination with reset or team switch
    if(~inning_over && ~game_over && ~team_sw && ~rst) begin 
        case (lfsr_out)
            5,7:     t1_balls <= t1_balls;       //Do not count no balls and wides
            default: t1_balls <= t1_balls +1'd1;
        endcase
        ball_count <= t1_balls;
    end
    else if(inning_over && ~game_over && ~team_sw && ~rst) begin
        case (lfsr_out)
            5,7:     t2_balls <= t2_balls;       //Do not count no balls and wides
            default: t2_balls <= t2_balls +1'd1;
        endcase
        ball_count <= t2_balls;
    end
    
    //If game is over, display ball count of team which won
    if(game_over) begin
        if (~winner)
        ball_count <= t1_balls;
        else 
        ball_count <= t2_balls;
    end
    
    //Switching teams back and forth to check ball count by pressing btnD and btnU
    if (team_sw) begin
        if (~game_over) begin
            if (inning_over)
            ball_count <= t1_balls;
            else 
            ball_count <= t2_balls;
        end
        if(game_over) begin
            if (winner)
            ball_count <= t1_balls;
            else 
            ball_count <= t2_balls;
        end 
    end
    
    //Re-inititiallize ball counts if reset
    if(rst) begin
    ball_count <= 8'b0000000;
    t1_balls <= 8'd1;
    t2_balls <= 8'd1;
    end    
end
endmodule