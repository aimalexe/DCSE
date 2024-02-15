module Mux_4to1_using_Mux2x1 (I, Sel, Out);

  input [3:0] I;     // 4-bit input bus
  input [1:0] Sel;   // 2-bit select input
  output Out;        // Output

  wire [1:0] MuxOut; // Output from each 2-to-1 MUX

  Mux_2x1 mux0 (
    .I({I[0], I[1]}), // Select inputs {I[0], I[1]}
    .Sel(Sel[1]),     // Select bit Sel[1]
    .Out(MuxOut[0])   // Output of the first MUX
  );

  Mux_2x1 mux1 (
    .I({I[2], I[3]}), // Select inputs {I[2], I[3]}
    .Sel(Sel[1]),     // Select bit Sel[1]
    .Out(MuxOut[1])   // Output of the second MUX
  );

  Mux_2x1 mux2 (
    .I({MuxOut[0], MuxOut[1]}), // Select inputs {MuxOut[0], MuxOut[1]}
    .Sel(Sel[0]),               // Select bit Sel[0]
    .Out(Out)                   // Final output
  );

endmodule
