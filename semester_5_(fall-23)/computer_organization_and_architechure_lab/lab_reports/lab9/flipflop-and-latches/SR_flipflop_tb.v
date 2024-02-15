module SR_flipflop_tb();
    reg S;
    reg R;
    reg clk;
    wire Q;
    wire Qbar;

    SR_flipflop flipflop(S, R, clk, Q, Qbar);

    initial begin
        clk =1;
        S = 0;
        R = 1;
        #10
        $display("%b  %b  %b  %b  %b", S, R, clk, Q, Qbar);
        
        clk =1;
        S = 1;
        R = 1;
        #10
        $display("%b  %b  %b  %b  %b", S, R, clk, Q, Qbar);

        clk =1;
        S = 1;
        R = 0;
        #10
        $display("%b  %b  %b  %b  %b", S, R, clk, Q, Qbar);

        clk =1;
        S = 1;
        R = 1;
        #10
        $display("%b  %b  %b  %b  %b", S, R, clk, Q, Qbar);
    end
endmodule

