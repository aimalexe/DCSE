module SR_latch_tb();
    reg S;
    reg R;
    wire Q;
    wire Qbar;

    SR_latch latch(S, R, Q, Qbar);

    initial begin
        S = 0;
        R = 1;
        #10
        $display("%b  %b  %b  %b", S, R, Q, Qbar);

        S = 1;
        R = 1;
        #10
        $display("%b  %b  %b  %b", S, R, Q, Qbar);

        S = 1;
        R = 0;
        #10
        $display("%b  %b  %b  %b", S, R, Q, Qbar);

        S = 1;
        R = 1;
        #10
        $display("%b  %b  %b  %b", S, R, Q, Qbar);
    end
endmodule

