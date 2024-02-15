module RAM_16x8 (clk, addr, data_in, write_enable, data_out);
  input wire clk;
  input wire [3:0] addr;
  input wire [7:0] data_in;
  input wire write_enable;
  output wire [7:0] data_out;

  reg [7:0] memory [0:15]; // 16 words by 8 bits

  // Read operation
  assign data_out = (write_enable) ? 8'bzzzz_zzzz : memory[addr];

  // Write operation
  always @(posedge clk) begin
    if (write_enable)
      memory[addr] <= data_in;
  end

endmodule 