module SR_flipflop(S, R, clk, Q, Qbar);
    input S;
    input R;
    input clk;
    output Q;
    output Qbar;


    wire nan1;
    wire nan2;

    assign nan1 = ~(S & clk);
    assign nan2 = ~(R & clk);

    assign Q = ~(nan1 & Qbar);
    assign Qbar = ~(nan2 & Q);

endmodule

