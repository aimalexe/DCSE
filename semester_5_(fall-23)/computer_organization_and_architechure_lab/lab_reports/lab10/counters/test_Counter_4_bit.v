module test_Counter_4_bit();
    reg clk;
    reg rst;
    wire [3:0] count;

    Counter_4_bit counter(
        .clock(clk),
        .reset(rst),
        .count(count)
    );

    always begin
        #5
        clk = ~clk;
    end

    initial begin
        clk = 0;
        rst = 0;

        // Reset the counter initially
        rst = 1;
        #10 rst = 0;
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
