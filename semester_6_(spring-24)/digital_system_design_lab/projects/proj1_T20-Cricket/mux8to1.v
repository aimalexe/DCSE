//Module to select a bcd digit to display on the anode that is turned on 
`timescale 1ns / 1ps

module mux8to1(
     input rst,ball_sw,team_sw,inning_over,game_over,winner,
	 input [2:0] sel,         //Output from 3-bit counter is given as a selector
	 input [3:0] A,B,C,D,E,F, //Bcd digits of runs, wickets and ball count
	 output [3:0] Y
    );
    
//Register H will always code for 't', denoting team
//Register G will show either 1 or 2 to denote which team is batting
reg [3:0] G,H; 
    
always @(posedge ball_sw) begin
    //If inning is not over, always display 't1'
    if (~inning_over) begin
        G <= 4'd1;
        H <= 4'd15;//t1
    end
    else begin
        G <= 4'd2;
        H <= 4'd15;//t2
    end
    
    //If game is over, always display team number of winner
    if(game_over) begin
        if (~winner) begin
            G <= 4'd1;
            H <= 4'd15;//t1
        end
        else begin
            G <= 4'd2;
            H <= 4'd15;//t2
        end
    end
    
    //Switching teams back and forth by pressing btnD and btnU
    if(team_sw) begin
        if (~game_over) begin
            if (inning_over)begin
                G <= 4'd1;
                H <= 4'd15;//t1
            end
            else begin
                G <= 4'd2;
                H <= 4'd15;//t2
            end
        end
        if(game_over) begin
            if (winner)begin
                G <= 4'd1;
                H <= 4'd15;//t1
            end
            else begin
                G <= 4'd2;
                H <= 4'd15;//t2
            end
        end
    end
    
    //Re-inititiallize to Team 1, if reset is pressed
    if(rst) begin
        G <= 4'd1;
        H <= 4'd15;//t1
    end
end
    
//Selector switches decide what data at the input datalines go through to the output Y
assign Y = (sel==0)?A : (sel==1)?B : (sel==2)?C : (sel==3)?D : (sel==4)?E : (sel==5)?F : (sel==6)?G : H; 
endmodule