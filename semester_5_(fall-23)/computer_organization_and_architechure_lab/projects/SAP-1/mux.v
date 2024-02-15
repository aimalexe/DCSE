module mux(
    input [7:0] in0,
    input [7:0] in1,
    input sel,
    output reg [7:0] out
);
    always @( in0 or in1 or sel )
    begin
        case(sel)
            1'b0: out = in0;
            1'b1: out = in1;
            default: out = 8'bxxxxxxxx;
        endcase
    end
endmodule