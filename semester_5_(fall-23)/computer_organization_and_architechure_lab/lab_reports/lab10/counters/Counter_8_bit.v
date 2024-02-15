module Counter_8_bit(
    input wire clock,
    input wire reset,
    output reg [7:0] count
);

    always @(posedge clock or posedge reset)
    begin
        if(reset)
            count <= 8'b00000000;
        else
            count <= count +1;
    end
endmodule 