module demux(
    input [7:0] in,
    input sel,
    output reg [7:0] out0,
    output reg [7:0] out1
);
    always @(in or sel)
    begin
        case(sel)
            1'b0:
                begin
                    out0 = in;
                    out1 = 8'bxxxxxxxx;
                end
            1'b1:
                begin
                    out0 = 8'bxxxxxxxx;
                    out1 = in;
                end
            default:
                begin
                    out0 = 8'bxxxxxxxx;
                    out1 = 8'bxxxxxxxx;
                end
        endcase
    end
endmodule