
module tristatebuff_8bit(in, out, low_en);
    input [7:0] in; 
    input low_en; 
    output tri [7:0] out; 
    assign out = low_en ? 8'bzzzzzzzz : in;  //pass the output when enable is 0
endmodule 