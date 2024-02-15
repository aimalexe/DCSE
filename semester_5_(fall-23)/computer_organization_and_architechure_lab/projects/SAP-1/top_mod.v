`include "tristatebuff_8bit.v"
`include "tristatebuff_4bit.v"
`include "control_unit.v"
`include "opcode_decoder.v"
`include "program_counter.v"
`include "t_state_counter.v"
`include "dFlipflop.v"
`include "Seven_segment.v"
`include "mux.v"
`include "full_adder.v"
`include "demux.v"
`include "register_4bit.v"
`include "register_8bit.v"
`include "adder_ripple.v"
`include "ALU.v"
`include "memory.v"

module main( clk, out, clr,  LED1,LED2);
  
    output [6:0] LED1;
    output [6:0] LED2;
    output [7:0] out;
    input clk, clr;
    wire [7:0] bus;
    wire buf_clk;

    // Control unit
    wire inc, PE, LOW_MAR_LD, LOW_RAM_OE, LOW_IR_LD, LOW_IR_OUT, LOW_HALT;
    wire LOW_ACC_LD, ACC_OE, sub_add, subadd_out_en, LOW_B_LD, LOW_LD_OUT;
    wire [3:0] op_code;
    control_sequencer seq(
        .op_code(op_code),
        .clk(buf_clk),
        .clr(clr),
        .inc(inc),
        .PE(PE),
        .LOW_MAR_LD(LOW_MAR_LD),
        .LOW_ROM_OE(LOW_ROM_OE),
        .LOW_IR_LD(LOW_IR_LD),
        .LOW_IR_OUT(LOW_IR_OUT),
        .LOW_ACC_LD(LOW_ACC_LD),
        .ACC_OE(ACC_OE),
        .sub_add(sub_add),
        .subadd_out_en(subadd_out_en),
        .LOW_B_LD(LOW_B_LD),
        .LOW_LD_OUT(LOW_LD_OUT),
        .LOW_HALT(LOW_HALT)
    );

    // Clock buffer
    bufif1(buf_clk, clk, LOW_HALT);
     
    //program counter
    program_counter pc(
        .inc(inc), .clk(buf_clk), .PE(PE), .clr(clr), .out(bus[3:0])
    );
    //memory address register:
    wire [3:0] mar_out;
    wire MAR_LD;
    assign MAR_LD = ~LOW_MAR_LD;
    reg_4bit  mar(
        .in(bus[3:0]), .out(mar_out), .i_en(MAR_LD), .clr(clr), .clk(buf_clk)
    );
    
    //RomModule
    rom mem(
        .addr(mar_out), .ROM_LOW_OE(LOW_ROM_OE), .data(bus)
    );
    //Instruction register
    wire [7:0] ir_out;
    wire LD_IR;
    assign LD_IR= ~ LOW_IR_LD;
    reg_8bit  ir(
        .in(bus), .out(ir_out), .i_en(LD_IR), .clr(clr), .clk(buf_clk)
    );

    tristatebuff_4bit buf0(.in(ir_out[3:0]), .out(bus[3:0]), .low_en(LOW_IR_OUT));
    assign op_code = ir_out[7:4]; 
    
    //Accumulator
    wire [7:0] acc_out;
    wire ACC_LD;
    assign ACC_LD=~LOW_ACC_LD;
    reg_8bit  acc(
        .in(bus), .out(acc_out), .i_en(ACC_LD), .clr(clr), .clk(buf_clk)
    );
    wire LOW_ACC_OE;
    assign LOW_ACC_OE = ~ACC_OE;
    tristatebuff_8bit buf1(.in(acc_out), .out(bus), .low_en(LOW_ACC_OE));
    
    //B register
    wire [7:0] b_reg_out;
    wire LD_B;
    assign LD_B= ~LOW_B_LD;
    reg_8bit  b_reg(
        .in(bus), .out(b_reg_out), .i_en(LD_B), .clr(clr), .clk(buf_clk)
    );

    //ALU
    alu  asub(.A(acc_out), .B(b_reg_out), .sub(sub_add), .cout(), .out(bus), .out_en(subadd_out_en));
 
    //Output register 
    wire LD_OUT;
    assign LD_OUT=~LOW_LD_OUT;
    reg_8bit out_reg(
        .in(bus), .out(out), .i_en(LD_OUT), .clr(clr), .clk(buf_clk)
    );
    
    //7 segment display of address and output
    sevenseg seg0(.bcd(out[3:0]), .seg(LED1));
    sevenseg seg1(.bcd(out[7:4]), .seg(LED2));
endmodule       
    

