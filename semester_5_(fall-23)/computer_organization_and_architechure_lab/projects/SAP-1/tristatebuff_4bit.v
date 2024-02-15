
module tristatebuff_4bit(in, out, low_en);
    input [3:0] in; 
    input low_en; 
    output tri [3:0] out; 
    assign out = low_en ? 4'bzzzz : in; //pass the output when enable is 0
endmodule 