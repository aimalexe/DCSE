
module T_flipflop_tb();
    reg T;
    reg clk;
    wire Q;
    wire Qbar;

    T_flipflop flipflop(T, clk, Q, Qbar);

    initial begin
        $display( "clk  T  Q  Qbar ");

        clk =0;
        T = 0;
        #10
        $display("%b  %b  %b  %b ", clk , T,  Q, Qbar);
        
        clk =1;
        T = 0;
        #10
        $display("%b  %b  %b  %b ", clk , T,  Q, Qbar);

        clk =1;
        T = 1;
        #10
        $display("%b  %b  %b  %b", clk , T,  Q, Qbar);
    end
endmodule

