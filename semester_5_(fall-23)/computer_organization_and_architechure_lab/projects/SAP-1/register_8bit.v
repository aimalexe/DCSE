module reg_8bit(in, out, i_en, clr, clk);
    input [7:0] in; 
    input i_en; // active low
    input clr;
    input clk; 
    output [7:0] out;
   
   //instantiating 8 D-flipflops
    dFlipflop ff1(clk,clr,i_en,in[0],out[0]);
    dFlipflop ff2(clk,clr,i_en,in[1],out[1]);
    dFlipflop ff3(clk,clr,i_en,in[2],out[2]);
    dFlipflop ff4(clk,clr,i_en,in[3],out[3]);
    dFlipflop ff5(clk,clr,i_en,in[4],out[4]);
    dFlipflop ff6(clk,clr,i_en,in[5],out[5]);
    dFlipflop ff7(clk,clr,i_en,in[6],out[6]);
    dFlipflop ff8(clk,clr,i_en,in[7],out[7]);

    endmodule
