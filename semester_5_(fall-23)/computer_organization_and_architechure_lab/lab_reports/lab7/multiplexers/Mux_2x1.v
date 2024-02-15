module Mux_2x1 (I, Sel, Out);

  input [1:0] I;  // 2-bit input bus
  input Sel;      // 1-bit select input
  output Out;     // Output

  reg Out;        // Output register

  always @(I, Sel)
    case(Sel)
      1'b0: Out = I[0];  // If Sel is 0, Out is I[0]
      1'b1: Out = I[1];  // If Sel is 1, Out is I[1]
    endcase

endmodule

