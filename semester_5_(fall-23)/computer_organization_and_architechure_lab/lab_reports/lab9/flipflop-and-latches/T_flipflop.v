
module T_flipflop(T, clk, Q, Qbar);
    input T;
    input clk;
    output Q;
    output Qbar;
    wire D;
    wire Q;
    xor x1(D, T, Q);
    D_flipflop d1(D, clk, Q, Qbar);
endmodule
