module test1_Decoder_2x4;

    reg A, B, E;
    wire [3:0] I;

    // Instantiate the Decoder_2x4 module
    Decoder_2x4 uut (
        .A(A),
        .B(B),
        .E(E),
        .I(I)
    );

    // Clock generation (not used in this example)
    reg clk = 0;
    always #5 clk = ~clk;

    // Testbench stimulus
    initial begin
        // Test case 1: Enable (E) is high, A=0, B=0
        A = 0;
        B = 0;
        E = 1;
        #10 $display("Input: A=%b, B=%b, E=%b, Output: I=%b", A, B, E, I);

        // Test case 2: Enable (E) is high, A=1, B=0
        A = 1;
        B = 0;
        #10 $display("Input: A=%b, B=%b, E=%b, Output: I=%b", A, B, E, I);

        // Test case 3: Enable (E) is high, A=0, B=1
        A = 0;
        B = 1;
        #10 $display("Input: A=%b, B=%b, E=%b, Output: I=%b", A, B, E, I);

        // Test case 4: Enable (E) is high, A=1, B=1
        A = 1;
        B = 1;
        #10 $display("Input: A=%b, B=%b, E=%b, Output: I=%b", A, B, E, I);
    end

endmodule

