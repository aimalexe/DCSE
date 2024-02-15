module T_Controlled_Async_Counter_4_bit(
    input wire clock,     
    input wire reset,     
    input wire enable,  
    output reg [3:0] count
);

    reg [3:0] t_signals;

    always @(posedge clock or posedge reset) begin
        if (reset) begin
            t_signals <= 4'b0000; // Reset T signals to 0 when reset is high
        end else if (enable) begin
            t_signals <= t_signals + 1; // Increment T signals on each clock cycle when enable is high
        end
    end

    T_Flip_Flop tff0 (.T(t_signals[0]), .clock(clock), .Q(count[0]));
    T_Flip_Flop tff1 (.T(t_signals[1]), .clock(clock), .Q(count[1]));
    T_Flip_Flop tff2 (.T(t_signals[2]), .clock(clock), .Q(count[2]));
    T_Flip_Flop tff3 (.T(t_signals[3]), .clock(clock), .Q(count[3]));

endmodule
