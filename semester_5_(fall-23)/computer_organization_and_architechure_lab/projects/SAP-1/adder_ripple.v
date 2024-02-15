module ripple_adder(X, Y, S, Co);
 input [7:0] X, Y;// Two 8-bit inputs
 output [7:0] S;
 output Co;
 wire w0, w1, w2,w3,w4,w5,w6;
 // instantiating 8 1-bit full adders in Verilog
fulladder u1(X[0], Y[0], 1'b0, S[0], w0);
fulladder u2(X[1], Y[1], w0, S[1], w1);
fulladder u3(X[2], Y[2], w1, S[2], w2);
fulladder u4(X[3], Y[3], w2, S[3], w3);
fulladder u5(X[4], Y[4], w3, S[4], w4);
fulladder u6(X[5], Y[5], w4, S[5], w5);
fulladder u7(X[6], Y[6], w5, S[6], w6);
fulladder u8(X[7], Y[7], w6, S[7], Co);
endmodule
