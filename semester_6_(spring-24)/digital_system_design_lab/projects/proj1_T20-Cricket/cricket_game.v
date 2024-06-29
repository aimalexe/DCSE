//Top module of T20 Cricket Game 
//A total of 3 comments to toggle while running simulation with testbench
`timescale 1ns / 1ps

//Comment from Comment1_begin till Comment1_end while running simulation with testbench
 //Comment1_begin
module cricket_game(
input clk, rst, btnU, team_sw,
output inning_over,
output [15:0] LED,
output [6:0] seg,
output [7:0] AN,
output dp, red, grn, blu);
    wire ball_sw, game_over, winner;
    wire [3:0] lfsr_out;
    wire [7:0] runs;
    wire [3:0] wickets;
//Comment1_end

//Uncomment from Comment2_begin till Comment2_end while running simulation with testbench
/* //Comment2_begin
module cricket_game_sim(
input clk, rst, ball_sw, team_sw,
output inning_over, game_over, winner,
output [3:0] lfsr_out,
output [7:0] runs,
output [3:0] wickets);
//Comment2_end*/

    wire [11:0] t1_data;
    wire [11:0] t2_data;
    wire [7:0] t1_balls;
    wire [7:0] t2_balls;
    wire [7:0] ball_count;

    //Comment from Comment3_begin till Comment3_end while running simulation with testbench
     //Comment3_begin
    //Debouncing the ball switch button
    debounce d0(clk, btnU, ball_sw);
    //Comment3_end
    
    //Generating random numbers from 1 to 8 using lfsr module
    lfsr l1 (clk,rst, ball_sw, game_over, lfsr_out);
    //Generating individual team data consisting of runs and wickets
    score_and_wickets sc1 (clk,rst,ball_sw,team_sw,inning_over, lfsr_out, game_over,winner,runs, wickets, t1_data, t2_data); 
    //Deciding whether inning is over, if game is over and which team is the winner
    score_comparator sc2 (clk, rst, t1_data, t2_data, t1_balls, t2_balls, ball_count, inning_over, game_over, winner);
    //Countng the number of deliveries that are bowled (excluding no balls and wides)
    ball_counter bc1 (clk, rst, ball_sw, team_sw, lfsr_out,inning_over,game_over,winner,ball_count,t1_balls,t2_balls);
    //Controller of seven-segment display
    bcd_control disp1 (clk,rst,ball_sw,team_sw,inning_over,game_over,winner,runs,wickets,ball_count,seg,AN,dp);
    //Scrolling leds for celebration after game is over
    scroll_leds sl1 (clk, game_over, LED);
    //Producing rainbow effect with tri-state leds for celebration after game is over 
    rainbow_leds rl1 (clk,game_over,red,grn,blu);
endmodule