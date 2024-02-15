module rom(
    input [3:0] addr,
    input ROM_LOW_OE,
    output reg [7:0] data //tri reg
);
    always @(addr or ROM_LOW_OE)
    begin
        if(ROM_LOW_OE)
        begin
            data = 8'bzzzzzzzz;
        end
        else
        begin
            case(addr)
            // 0 to 7 is alloted for program memory and 8 to f is alloted for data
	    // lets implement 16 + 20 + 24 - 32.
                4'h0: data = 8'b0000_1001; // LDA 9h
                4'h1: data = 8'b0001_1010; // ADD Ah
                4'h2: data = 8'b0001_1011; // ADD Bh
                4'h3: data = 8'b0010_1100; // SUB Ch
                4'h4: data = 8'b1110_0000; // OUT
                4'h5: data = 8'b0010_1101; // SUB Dh
                4'h6: data = 8'b1110_0000; // OUT  
                4'h7: data = 8'b1111_0000; // HLT
                4'h8: data = 8'b0000_0000; 
                4'h9: data = 8'b0001_0000; // 16
                4'ha: data = 8'b0001_0100; // 20
                4'hb: data = 8'b0001_1000; // 24
                4'hc: data = 8'b0010_0000; // 32
                4'hd: data = 8'b0000_1000; // 8
                4'he: data = 8'b0000_0000;
                4'hf: data = 8'b0000_0000;
            endcase
        end
    end
endmodule