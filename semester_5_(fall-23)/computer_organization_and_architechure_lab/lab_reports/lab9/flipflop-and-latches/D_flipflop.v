
module D_flipflop(D, clk, Q, Qbar);
    input D;
    input clk;
    output Q;
    output Qbar;


    wire nan1;
    wire nan2;
    wire nD;

    not n1(nD, D);

    assign nan1 = ~(D & clk);
    assign nan2 = ~(nD & clk);

    assign Q = ~(nan1 & Qbar);
    assign Qbar = ~(nan2 & Q);

endmodule
