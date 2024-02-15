
// Testbench for 16x8 RAM
module test_RAM_16x8;

  // Inputs
  reg clk;
  reg [3:0] addr;
  reg [7:0] data_in;
  reg write_enable;

  // Outputs
  wire [7:0] data_out;

  // Instantiate the RAM module
  ram_16x8 uut (
    .clk(clk),
    .addr(addr),
    .data_in(data_in),
    .write_enable(write_enable),
    .data_out(data_out)
  );

  // Clock generation
  always begin
    #5 clk = ~clk;
  end

  // Initial block
  initial begin
    // Initialize inputs
    clk = 0;
    addr = 4'b0000;
    data_in = 8'b0000_0000;
    write_enable = 0;

    // Apply write operation to store data
    addr = 4'b0001;
    data_in = 8'b1010_1010;
    write_enable = 1;
    #10 write_enable = 0;

    // Read from the RAM
    addr = 4'b0001;
    write_enable = 0;

    // Monitor signals
    $monitor("Time=%t, clk=%b, addr=%b, data_in=%b, write_enable=%b, data_out=%b", $time, clk, addr, data_in, write_enable, data_out);

    // Run simulation for 100 clock cycles
    #100 $finish;
  end

endmodule
