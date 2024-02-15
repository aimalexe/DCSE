module SR_latch(S, R, Q, Qbar);
    input S;
    input R;
    output Q;
    output Qbar;

    assign Q = ~(S & Qbar);
    assign Qbar = ~(R & Q);
endmodule
