module test_T_Controlled_Async_Counter_4_bit();
reg clk;      
reg rst;      
reg enable;   
wire [3:0] count; 

// Instantiate the controlled asynchronous up-counter module
T_Controlled_Async_Counter_4_bit uut (
    .clock(clk),
    .reset(rst),
    .enable(enable),
    .count(count)
);

// Clock generation
always begin
    #5 clk = ~clk; // Toggle the clock every 5 time units
end

// Testbench initialization
initial begin
    clk = 0;
    rst = 0;
    enable = 1; // Enable the counter

    // Reset the counter initially
    rst = 1;
    #10 rst = 0;

    // Wait for some clock cycles and observe the counter
    #20;
    
    // Test the counter for several clock cycles
    $display("Time = 0, Count = %b", count);
    #10;
    $display("Time = 10, Count = %b", count);
    #10;
    $display("Time = 20, Count = %b", count);
    #10;
    $display("Time = 30, Count = %b", count);
    
    // Finish simulation
    $finish;
end

endmodule