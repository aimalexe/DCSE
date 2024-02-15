module Decoder_4x16_using_3x8 (select,enable,out);

input wire[3:0] select;
input wire enable;
output wire[15:0] out;

wire [7:0] decoder1_out;
wire [7:0] decoder2_out;

Decoder_3x8 decoder1 (
    .select(select[2:0]),
    .enable(enable),
    .out(decoder1_out)
);

Decoder_3x8 decoder2 (
    .select(select[3:1]),
    .enable(enable),
    .out(decoder2_out)
);

assign out = {decoder2_out, decoder1_out};

endmodule

