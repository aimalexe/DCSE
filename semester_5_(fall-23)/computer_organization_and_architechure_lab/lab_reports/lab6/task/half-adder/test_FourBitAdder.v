module simulateFourBitAdder();

reg A0, B0, A1, B1, A2, B2, A3, B3, Cin;
wire S0, S1, S2, S3, Cout;

FourBitAdder fba(A0, B0, A1, B1, A2, B2, A3, B3, Cin, S0, S1, S2, S3, Cout);

initial
begin
$display("A0, B0, A1, B1, A2, B2, A3, B3, Cin, S0, S1, S2, S3, Cout");

Cin = 0;
A0 = 0;
B0 = 0;
A1 = 0;
B1 = 0;
A2 = 0;
B2 = 0;
A3 = 0;
B3 = 0;
#10
$display("%b, %b, %b, %b, %b, %b, %b, %b, %b, %b, %b, %b, %b, %b", A0, B0, A1, B1, A2, B2, A3, B3, Cin, S0, S1, S2, S3, Cout);

Cin = 1;
A0 = 0;
B0 = 0;
A1 = 0;
B1 = 0;
A2 = 0;
B2 = 1;
A3 = 0;
B3 = 0;
#10
$display("%b, %b, %b, %b, %b, %b, %b, %b, %b, %b, %b, %b, %b, %b", A0, B0, A1, B1, A2, B2, A3, B3, Cin, S0, S1, S2, S3, Cout);

Cin = 1;
A0 = 1;
B0 = 0;
A1 = 1;
B1 = 0;
A2 = 1;
B2 = 0;
A3 = 1;
B3 = 0;
#10
$display("%b, %b, %b, %b, %b, %b, %b, %b, %b, %b, %b, %b, %b, %b", A0, B0, A1, B1, A2, B2, A3, B3, Cin, S0, S1, S2, S3, Cout);

Cin = 0;
A0 = 1;
B0 = 1;
A1 = 1;
B1 = 0;
A2 = 1;
B2 = 1;
A3 = 1;
B3 = 0;
#10
$display("%b, %b, %b, %b, %b, %b, %b, %b, %b, %b, %b, %b, %b, %b", A0, B0, A1, B1, A2, B2, A3, B3, Cin, S0, S1, S2, S3, Cout);

Cin = 0;
A0 = 0;
B0 = 0;
A1 = 1;
B1 = 1;
A2 = 1;
B2 = 0;
A3 = 1;
B3 = 1;
#10
$display("%b, %b, %b, %b, %b, %b, %b, %b, %b, %b, %b, %b, %b, %b", A0, B0, A1, B1, A2, B2, A3, B3, Cin, S0, S1, S2, S3, Cout);

end
endmodule;