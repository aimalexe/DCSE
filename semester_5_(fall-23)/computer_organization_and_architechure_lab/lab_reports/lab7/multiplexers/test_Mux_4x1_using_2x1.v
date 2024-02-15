module test_Mux_4to1_using_Mux2x1();

  reg [3:0] I;
  reg [1:0] Sel;
  wire Out;

  Mux_4to1_using_Mux2x1 uut (I, Sel, Out);

  initial begin
    // Initialize signals
    I = 4'b0000;
    Sel = 2'b00;

    // Apply test case 1
    Sel = 2'b00;
    #10; // Wait for some time to stabilize
    $display("Test case 1: Sel = %b, I = %b, Out = %b", Sel, I, Out);

    // Apply test case 2
    Sel = 2'b01;
    #10; // Wait for some time to stabilize
    $display("Test case 2: Sel = %b, I = %b, Out = %b", Sel, I, Out);

    // Apply test case 3
    Sel = 2'b10;
    #10; // Wait for some time to stabilize
    $display("Test case 3: Sel = %b, I = %b, Out = %b", Sel, I, Out);

    // Apply test case 4
    Sel = 2'b11;
    #10; // Wait for some time to stabilize
    $display("Test case 4: Sel = %b, I = %b, Out = %b", Sel, I, Out);

  end

endmodule
