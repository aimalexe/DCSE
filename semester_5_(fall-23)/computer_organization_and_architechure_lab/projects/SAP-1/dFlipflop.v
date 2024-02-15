//Postive edge triggered flipflops
module dFlipflop(
    clk,
    clr,
    i_en,
    d,
    q
);

    input d;
    input i_en, clr, clk;
    output reg q;

    always @(posedge clk or clr)
    begin
        if(clr)
            q <= 0;
        else
            if(i_en)
                q <= d;
    end

endmodule 