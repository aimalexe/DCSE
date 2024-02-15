module T_Flip_Flop(
    input wire T,
    input wire clock,
    output reg Q
);

    always @(posedge clock) begin
        if (T)
            Q <= ~Q; // Toggle Q if T is high
    end
endmodule