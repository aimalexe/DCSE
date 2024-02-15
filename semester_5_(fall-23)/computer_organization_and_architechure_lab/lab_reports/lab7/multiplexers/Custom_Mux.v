module Custom_Mux (
  input A,
  input B,
  input [1:0] Sel,
  output Y
);

  wire Y_AB, Y_A_minus_B;

  // MUX for A and B selection
  assign Y_AB = (Sel == 2'b00) ? A : B;

  // Calculate A - B
  assign Y_A_minus_B = A - B;

  // Output selection based on Sel
  assign Y = (Sel == 2'b00) ? A : 
            (Sel == 2'b01) ? B :
            (Sel == 2'b10) ? Y_AB :
            (Sel == 2'b11) ? Y_A_minus_B : 0; // Default to 0 if Sel is invalid

endmodule
