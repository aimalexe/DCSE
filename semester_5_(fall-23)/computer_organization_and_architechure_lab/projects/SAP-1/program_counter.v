
module program_counter(
    input inc, clk, PE, clr,
    output tri [3:0] out
);
    reg [3:0] count;
    assign not_PE= ~PE;
    tristatebuff_4bit tbuf(.in(count), .out(out), .low_en(not_PE));
    always @(posedge clk or clr)
    begin
        if(clr)
            count <= 4'b0000;
        else if(inc)
            count <= count + 1;
    end
endmodule
