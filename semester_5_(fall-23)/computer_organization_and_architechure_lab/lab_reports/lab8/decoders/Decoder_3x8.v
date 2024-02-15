module Decoder_3x8 ( select, enable, out);

input wire[2:0] select;
input wire enable;
output wire[7:0] out;

assign out[0] = (enable & ~select[0] & ~select[1] & ~select[2]);
assign out[1] = (enable & ~select[0] & ~select[1] & select[2]);
assign out[2] = (enable & ~select[0] & select[1] & ~select[2]);
assign out[3] = (enable & ~select[0] & select[1] & select[2]);
assign out[4] = (enable & select[0] & ~select[1] & ~select[2]);
assign out[5] = (enable & select[0] & ~select[1] & select[2]);
assign out[6] = (enable & select[0] & select[1] & ~select[2]);
assign out[7] = (enable & select[0] & select[1] & select[2]);

endmodule
