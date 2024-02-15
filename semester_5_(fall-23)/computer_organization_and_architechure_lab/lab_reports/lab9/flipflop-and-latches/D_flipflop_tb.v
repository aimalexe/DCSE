
module D_flipflop_tb();
    reg D;
    reg clk;
    wire Q;
    wire Qbar;

    D_flipflop flipflop(D, clk, Q, Qbar);

    initial begin
        clk =0;
        D = 0;
        #10
        $display("%b  %b  %b  %b ", D, clk, Q, Qbar);
        
        clk =1;
        D = 0;
        #10
        $display("%b  %b  %b  %b ", D, clk, Q, Qbar);

        clk =1;
        D = 1;
        #10
        $display("%b  %b  %b  %b", D, clk, Q, Qbar);
    end
endmodule
