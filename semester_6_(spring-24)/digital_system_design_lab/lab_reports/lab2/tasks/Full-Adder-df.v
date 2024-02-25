module FullAdderDataFlow(
    output S,
    output CyOut,
    input A,
    input B,
    input CyIn
);
    assign S = A ^ B ^ CyIn;
    assign CyOut = (A&B) | (B&CyIn) | (A&CyIn);
endmodule 