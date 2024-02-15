module JK_flipflop(J, K, clk, Q, Qbar);
    input J;
    input K;
    input clk;
    output Q;
    output Qbar;


    wire nan1;
    wire nan2;

    assign nan1 = ~(J & clk & Qbar);
    assign nan2 = ~(K & clk & Q);

    assign Q = ~(nan1 & Qbar);
    assign Qbar = ~(nan2 & Q);

endmodule

