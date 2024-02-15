module Decoder_3x8_using_2x4 ( select, enable, out);

input wire[2:0] select;
input wire enable;
output wire[7:0] out;

wire [3:0] decoder1_out;
wire [3:0] decoder2_out;

Decoder_2x4 decoder1 (
    .select(select[1:0]),
    .enable(enable),
    .out(decoder1_out)
);

Decoder_2x4 decoder2 (
    .select(select[2:1]),
    .enable(enable),
    .out(decoder2_out)
);

assign out = {decoder2_out, decoder1_out};

endmodule

