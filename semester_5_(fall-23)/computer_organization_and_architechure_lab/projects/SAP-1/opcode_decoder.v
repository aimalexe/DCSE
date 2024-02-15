module opcode_decoder(op_code, lda, add, sub, out, LOW_HALT);
    input [3:0] op_code;
    output lda, add, sub, out, LOW_HALT;

    assign lda = ~(op_code[0] | op_code[1] | op_code[2] | op_code[3]);    //0000(Load to accumulator)
    assign add = ~(~op_code[0] | op_code[1] | op_code[2] | op_code[3]);    //0001(Addition)
    assign sub = ~(op_code[0] | ~op_code[1] | op_code[2] | op_code[3]);     //0010(subtraction)
    assign out = (~op_code[0] & op_code[1] & op_code[2] & op_code[3]);        //1110(Output)
    assign LOW_HALT = ~(op_code[0] & op_code[1] & op_code[2] & op_code[3]);  //1111(halt)
endmodule 