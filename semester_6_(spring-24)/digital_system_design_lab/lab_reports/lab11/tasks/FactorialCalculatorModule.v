
module FactorialCalculator(
    input wire clk,
    input wire reset,
    input wire start,
    input wire [7:0] n,
    output reg [31:0] factorial,
    output reg done
);

    reg [7:0] counter;
    reg [31:0] acc;
    reg [2:0] state, next_state;

    // FSM state definitions
    parameter IDLE = 3'b000, LOAD = 3'b001, MULTIPLY = 3'b010, DECREMENT = 3'b011, CHECK = 3'b100, DONE = 3'b101;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            state <= IDLE;
            factorial <= 0;
            done <= 0;
        end else begin
            state <= next_state;
        end
    end

    always @(*) begin
        case (state)
            IDLE: begin
                if (start) next_state = LOAD;
                else next_state = IDLE;
            end
            LOAD: begin
                acc = 1;
                counter = n;
                next_state = CHECK;
            end
            MULTIPLY: begin
                acc = acc * counter;
                next_state = DECREMENT;
            end
            DECREMENT: begin
                counter = counter - 1;
                next_state = CHECK;
            end
            CHECK: begin
                if (counter > 1) next_state = MULTIPLY;
                else next_state = DONE;
            end
            DONE: begin
                factorial = acc;
                done = 1;
                next_state = IDLE;
            end
            default: next_state = IDLE;
        endcase
    end

endmodule
