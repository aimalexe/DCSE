module test_T_Uncontrolled_Async_Counter_4_bit();
    reg clk;
    reg rst;
    wire [3:0] count;

    T_Uncontrolled_Async_Counter_4_bit uut (
        .clock(clk),
        .reset(rst),
        .count(count)
    );

    always begin
        #5 clk = ~clk; 
    end

    // Testbench initialization
    initial begin
        clk = 0;
        rst = 0;

        // Reset the counter initially
        rst = 1;
        #10 rst = 0;

        // Wait for some clock cycles and observe the counter
        #20;
        
        $display("Time = 0, Count = %b", count);
        #10;
        $display("Time = 10, Count = %b", count);
        #10;
        $display("Time = 20, Count = %b", count);
        #10;
        $display("Time = 30, Count = %b", count);
    end
endmodule
