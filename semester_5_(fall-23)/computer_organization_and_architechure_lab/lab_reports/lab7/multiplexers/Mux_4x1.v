module Mux_4x1 (I, Sel, Out);

  input [3:0] I;     // 4-bit input bus
  input [1:0] Sel;   // 2-bit select input
  output Out;        // Output

  reg Out;           // Output register

  always @(I, Sel)
    case(Sel)
      2'b00: Out = I[0];
      2'b01: Out = I[1];
      2'b10: Out = I[2];
      2'b11: Out = I[3];
    endcase

endmodule

