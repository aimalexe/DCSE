module Counter_4_bit(
    input wire clock,
    input wire reset,
    output reg [3:0] count
);
    always @(posedge clock or posedge reset)
    begin
        if(reset) begin
            count <= 4'b0000;
        end else begin
            count <= count +1;
        end
    end
endmodule
