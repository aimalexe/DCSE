module HalfAdderDataFlow(
    output S,
    output Cy,
    input A,
    input B
);
    assign S = A ^ B;
    assign Cy = A & B;
endmodule 
