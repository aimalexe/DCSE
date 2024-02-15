
module control_sequencer(
    input [3:0] op_code,
    input clk, clr,
    output inc,
    output PE,
    output LOW_MAR_LD,
    output LOW_ROM_OE,
    output LOW_IR_LD,
    output LOW_IR_OUT,
    output LOW_ACC_LD,
    output ACC_OE,
    output sub_add,
    output subadd_out_en,
    output LOW_B_LD,
    output LOW_LD_OUT,
    output LOW_HALT
);
    wire lda, add, sub, out;
    wire [5:0] t;

    opcode_decoder decoder(.op_code(op_code),.lda(lda),.add(add),.sub(sub),.out(out),.LOW_HALT(LOW_HALT));
    state_counter counter(.t(t), .clk(clk),.res(clr)); 

  //control signals for various T states

   assign inc = t[4];
    assign PE = t[5];
    assign LOW_MAR_LD = ~(t[5] | (t[2] & (add | lda | sub)));
    assign LOW_ROM_OE = ~(t[3] | (t[1] & (add | lda | sub)));
    assign LOW_IR_LD = ~t[3];
    assign LOW_IR_OUT = ~(t[2] & ((add | lda | sub)));
    assign LOW_ACC_LD = ~((t[1] & lda) | (t[0] & (add | sub)));
    assign ACC_OE = t[2] & out;
    assign sub_add = t[0] & sub;
    assign subadd_out_en = t[0] & (add | sub);
    assign LOW_B_LD = ~(t[1] & (add | sub));
    assign LOW_LD_OUT = ~(t[2] & out);
endmodule 