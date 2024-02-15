module test_Custom_Mux();

  reg A;
  reg B;
  reg [1:0] Sel;
  wire Y;

  Custom_Mux uut (
    .A(A),
    .B(B),
    .Sel(Sel),
    .Y(Y)
  );

  initial begin
    // Initialize signals
    A = 1;
    B = 2;
    Sel = 2'b00;

    // Apply test case 1: Sel = '00' (output A)
    #10; // Wait for some time to stabilize
    $display("Test case 1: Sel = %b, A = %b, B = %b, Y = %b", Sel, A, B, Y);

    // Apply test case 2: Sel = '01' (output B)
    Sel = 2'b01;
    #10; // Wait for some time to stabilize
    $display("Test case 2: Sel = %b, A = %b, B = %b, Y = %b", Sel, A, B, Y);

    // Apply test case 3: Sel = '10' (output A + B)
    Sel = 2'b10;
    #10; // Wait for some time to stabilize
    $display("Test case 3: Sel = %b, A = %b, B = %b, Y = %b", Sel, A, B, Y);

    // Apply test case 4: Sel = '11' (output A - B)
    Sel = 2'b11;
    #10; // Wait for some time to stabilize
    $display("Test case 4: Sel = %b, A = %b, B = %b, Y = %b", Sel, A, B, Y);

  end

endmodule
