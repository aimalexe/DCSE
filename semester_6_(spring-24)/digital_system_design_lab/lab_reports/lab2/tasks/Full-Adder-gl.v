module FullAdderGL(
    output S,
    output CyOut,
    input A,
    input B,
    input CyIn
);
    wire c1, c2, s1;
    HalfAdderGL h1(s1, c1, A, B);
    HalfAdderGL h2(S, c2, s1, CyIn);

    or (CyOut, c1, c2);
endmodule 