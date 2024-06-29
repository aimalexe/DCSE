//Module to convert the binary data of runs and ball count to feed as individual digits to the display
`timescale 1ns / 1ps
module binary_to_BCD(
    input [7:0] binaryRuns, ball_count,
    output reg [3:0] ones1, tens1, hundreds1,ones2, tens2);
    
    //In this version of code,we do not have space to display the hundreds place of ball count
    reg [3:0] hundreds2;
	 
	reg [7:0] data1, data2; //Temporay registers for calculations
	always@ (binaryRuns, ball_count)	
	begin 
		data1 = binaryRuns; 
			hundreds1 <= data1 / 100; 
		data1 = data1 % 100; 
			tens1 <= data1 / 10; 
			ones1 <= data1 % 10;	
		data2 = ball_count; 
			hundreds2 <= data2 / 100; 
		data2 = data2 % 100; 
			tens2 <= data2 / 10; 
			ones2 <= data2 % 10;	
	end
endmodule