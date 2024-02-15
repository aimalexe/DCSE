module test_Counter_8_bit();
    reg clk;
    reg rst;
    wire [7:0] count;

    Counter_8_bit counter(
        clk, rst, count
    );

    always begin
        #5 clk = ~clk;
    end

    initial begin
        clk = 0;
        rst = 0;

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
        
        #10;
        $display("Time = 30, Count = %b", count);
        #10;
        $display("Time = 30, Count = %b", count);
        #10;
        $display("Time = 30, Count = %b", count);
        #10;
        $display("Time = 30, Count = %b", count);
    end
endmodule