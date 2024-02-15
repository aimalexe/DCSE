module test_Decoder_3x8;

reg [2:0] select;
reg enable;
wire [7:0] out;

// Instantiate the 3x8 Decoder
Decoder_3x8 dut (
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
    select = 3'b000;
    enable = 1;
    #10 $display("Input: select=%b, enable=%b, Output=%b", select, enable, out);
    
    // Test case 2
    select = 3'b001;
    enable = 1;
    #10 $display("Input: select=%b, enable=%b, Output=%b", select, enable, out);
    
    // Test case 3
    select = 3'b010;
    enable = 1;
    #10 $display("Input: select=%b, enable=%b, Output=%b", select, enable, out);
    
    // Test case 4
    select = 3'b011;
    enable = 1;
    #10 $display("Input: select=%b, enable=%b, Output=%b", select, enable, out);

    // Test case 5
    select = 3'b100;
    enable = 1;
    #10 $display("Input: select=%b, enable=%b, Output=%b", select, enable, out);
    
    // Test case 6
    select = 3'b101;
    enable = 1;
    #10 $display("Input: select=%b, enable=%b, Output=%b", select, enable, out);
    
    // Test case 7
    select = 3'b110;
    enable = 1;
    #10 $display("Input: select=%b, enable=%b, Output=%b", select, enable, out);
    
    // Test case 8
    select = 3'b111;
    enable = 1;
    #10 $display("Input: select=%b, enable=%b, Output=%b", select, enable, out);
end

endmodule

