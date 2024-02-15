module JK_flipflop_tb();
    reg J;
    reg K;
    reg clk;
    wire Q;
    wire Qbar;

    JK_flipflop flipflop(J, K, clk, Q, Qbar);

    initial begin
        clk =1;
        J = 0;
        K = 1;
        #10
        $display("%b  %b  %b  %b  %b", J, K, clk, Q, Qbar);
        
        clk =1;
        J = 1;
        K = 1;
        #10
        $display("%b  %b  %b  %b  %b", J, K, clk, Q, Qbar);

        clk =1;
        J = 1;
        K = 0;
        #10
        $display("%b  %b  %b  %b  %b", J, K, clk, Q, Qbar);

        clk =1;
        J = 1;
        K = 1;
        #10
        $display("%b  %b  %b  %b  %b", J, K, clk, Q, Qbar);
    end
endmodule

