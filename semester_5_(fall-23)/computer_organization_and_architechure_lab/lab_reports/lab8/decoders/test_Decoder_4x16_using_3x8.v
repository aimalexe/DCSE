module test_Decoder_4x16_using_3x8;

reg [3:0] select;
reg enable;
wire [15:0] out;

// Instantiate the 4x16 Decoder
Decoder_4x16_using_3x8 dut (
    .select(select),
    .enable(enable),
    .out(out)
);

// Clock generation (not used in this example)
reg clk = 0;
always #5 clk = ~clk;

// Testbench stimulus
initial begin
    // Test case 1
    select = 4'b0000;
    enable = 1;
    #10 $display("Input: select=%b, enable=%b, Output=%b", select, enable, out);
    
    // Test case 2
    select = 4'b0001;
    enable = 1;
    #10 $display("Input: select=%b, enable=%b, Output=%b", select, enable, out);
    
    // Test case 3
    select = 4'b0010;
    enable = 1;
    #10 $display("Input: select=%b, enable=%b, Output=%b", select, enable, out);
    
    // Test case 16
    select = 4'b1111;
    enable = 1;
    #10 $display("Input: select=%b, enable=%b, Output=%b", select, enable, out);
end

endmodule

