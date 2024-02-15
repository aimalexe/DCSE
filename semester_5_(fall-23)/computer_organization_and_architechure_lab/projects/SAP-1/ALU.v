module alu(
    input [7:0] A, B,
    input sub,
    input out_en,
    output cout,
    output [7:0] out
);

 wire [7:0] dmux0, dmux1, comp, B_in, add_sub_out;

demux demux1 (
        .in(B), .sel(sub), .out0(dmux0), .out1(dmux1)
    );

 //taking two's complement of B reg if the sub=1
assign comp = ~dmux1 +  8'b00000001;    

 mux mux1(
        .in0(dmux0), .in1(comp),
        .sel(sub), .out(B_in)
    );

 ripple_adder r1(
        .X(A), .Y(B_in),
        .S(add_sub_out), .Co(cout)
    );
wire add_sub_low_out_en = ~out_en;
//output of the adder is given to a tristate buffer before outputing to the bus
 tristatebuff_8bit tri8(
        .in(add_sub_out), .out(out),
        .low_en(add_sub_low_out_en));

endmodule        