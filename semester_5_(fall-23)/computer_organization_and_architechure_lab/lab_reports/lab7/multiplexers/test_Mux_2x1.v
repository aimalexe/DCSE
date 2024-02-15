module test_Mux_2x1 ();
reg [1:0] I;
reg Sel;

wire Out;

Mux_2x1 m2x1(I, Sel, Out);

initial
begin

#10
I[0] = 1;
I[1] = 1;
Sel = 0;

#10
I[0] = 1;
I[1] = 0;
Sel = 1;
end

initial
$monitor("%d %b %b %b %b", $time, I[0], I[1], Sel, Out);
endmodule
