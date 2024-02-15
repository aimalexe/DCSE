module FourBitAdder(A0, B0, A1, B1, A2, B2, A3, B3, Cin, S0, S1, S2, S3, Cout);

input A0, B0, A1, B1, A2, B2, A3, B3, Cin;
output S0, S1, S2, S3, Cout;

wire C0, C1, C2;

FullAdder faA(A0, B0, Cin, S0, C0);
FullAdder faB(A1, B1, C0, S1, C1);
FullAdder faC(A2, B2, C1, S2, C2);
FullAdder faD(A3, B3, C2, S3, Cout);

endmodule;