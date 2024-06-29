
module Multiplier (
    input wire clk,
    input wire reset,
    input wire [7:0] multiplicand,
    input wire [7:0] multiplier,
    output reg [15:0] product,
    output reg done
);

    reg [7:0] counter;
    reg [7:0] addend;
    reg [15:0] accumulator;
    reg [2:0] state; // State register for FSM

    parameter IDLE = 3'b000, ADD = 3'b001, CHECK = 3'b010, FINISH = 3'b011;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            state <= IDLE;
            product <= 0;
            done <= 0;
        end
        else begin
            case (state)
                IDLE: begin
                    accumulator <= 0;
                    counter <= multiplier;
                    addend <= multiplicand;
                    if (multiplier != 0) // check if multiplier is zero
                        state <= ADD;
                    else
                        state <= FINISH;
                end
                ADD: begin
                    accumulator <= accumulator + addend;
                    counter <= counter - 1;
                    state <= CHECK;
                end
                CHECK: begin
                    if (counter != 0)
                        state <= ADD;
                    else
                        state <= FINISH;
                end
                FINISH: begin
                    product <= accumulator;
                    done <= 1;
                    state <= IDLE;
                end
            endcase
        end
    end

endmodule
