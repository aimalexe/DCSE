module SumGL(
    output S,
    input A,
    input B
);
    xor (S, A, B);
endmodule

module CarryGL(
    output Cy,
    input A,
    input B
);
    and (Cy, A, B);
endmodule 

module HalfAdderGL(
    output S,
    output Cy,
    input A,
    input B
);
    SumGL s(S, A, B);
    CarryGL c(Cy, A, B);
endmodule 