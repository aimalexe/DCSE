module atm_tb;

  reg clk;
  reg reset;
  reg [3:0] pin;
  reg withdraw;
  reg deposit;
  reg balance_disp;
  reg mini_stmt;
  reg face_recog;
  wire account_locked;
  wire [15:0] balance;
  wire [15:0] new_balance;
  wire [15:0] recent_transactions;
  
  // Additional variables for testing
  reg [15:0] withdrawal_amount;
  reg [15:0] deposit_amount;

  atm dut (
    .clk(clk),
    .reset(reset),
    .pin(pin),
    .withdraw(withdraw),
    .deposit(deposit),
    .balance_disp(balance_disp),
    .mini_stmt(mini_stmt),
    .face_recog(face_recog),
    .account_locked(account_locked),
    .balance(balance),
    .new_balance(new_balance),
    .recent_transactions(recent_transactions)
  );

  // Clock generation
  always begin
    clk = 0;
    #5;
    clk = 1;
    #5;
  end

  // Testcase 1: Invalid PIN entry
  initial begin
    reset = 1;
    #10;
    reset = 0;

    pin = 4'b0001; // Incorrect PIN
    #10;
    pin = 4'b0010; // Incorrect PIN
    #10;
    pin = 4'b0100; // Incorrect PIN
    #10;
    pin = 4'b0000; // Correct PIN
    #10;

    // Verify the expected outputs
    $display("Testcase 1 - Invalid PIN entry");
    $display("Account locked: %b, Balance: %d, New Balance: %d, Recent Transactions: %d", account_locked, balance, new_balance, recent_transactions);

    // End simulation
    $finish;
  end

  // Testcase 2: Withdraw more than 10000 INR
  initial begin
    reset = 1;
    #10;
    reset = 0;

    pin = 4'b0000; // Enter correct PIN
    #10;
    withdraw = 1;
    withdrawal_amount = 15000; // Withdraw more than 10000 INR
    #10;
    face_recog = 1; // Simulate face recognition pass
    #10;
    face_recog = 0;
    #10;
    withdraw = 0;

    // Verify the expected outputs
    $display("Testcase 2 - Withdraw more than 10000 INR");
    $display("Account locked: %b, Balance: %d, New Balance: %d, Recent Transactions: %d", account_locked, balance, new_balance, recent_transactions);

    // End simulation
    $finish;
  end

  // Testcase 3: Withdraw within limit
  initial begin
    reset = 1;
    #10;
    reset = 0;

    pin = 4'b0000; // Enter correct PIN
    #10;
    withdraw = 1;
    withdrawal_amount = 5000; // Withdraw within limit
    #10;
    withdraw = 0;

    // Verify the expected outputs
    $display("Testcase 3 - Withdraw within limit");
    $display("Account locked: %b, Balance: %d, New Balance: %d, Recent Transactions: %d", account_locked, balance, new_balance, recent_transactions);

    // End simulation
    $finish;
  end

  // Testcase 4: Deposit
  initial begin
    reset = 1;
    #10;
    reset = 0;

    pin = 4'b0000; // Enter correct PIN
    #10;
    deposit = 1;
    deposit_amount = 2000; // Deposit amount
    #10;
    deposit = 0;

    // Verify the expected outputs
    $display("Testcase 4 - Deposit");
    $display("Account locked: %b, Balance: %d, New Balance: %d, Recent Transactions: %d", account_locked, balance, new_balance, recent_transactions);

    // End simulation
    $finish;
  end

  // Testcase 5: Balance display
  initial begin
    reset = 1;
    #10;
    reset = 0;

    pin = 4'b0000; // Enter correct PIN
    #10;
    balance_disp = 1;
    #10;
    balance_disp = 0;

    // Verify the expected outputs
    $display("Testcase 5 - Balance display");
    $display("Account locked: %b, Balance: %d, New Balance: %d, Recent Transactions: %d", account_locked, balance, new_balance, recent_transactions);

    // End simulation
    $finish;
  end

  // Testcase 6: Mini statement generation
  initial begin
    reset = 1;
    #10;
    reset = 0;

    pin = 4'b0000; // Enter correct PIN
    #10;
    mini_stmt = 1;
    #10;
    mini_stmt = 0;

    // Verify the expected outputs
    $display("Testcase 6 - Mini statement generation");
    $display("Account locked: %b, Balance: %d, New Balance: %d, Recent Transactions: %d", account_locked, balance, new_balance, recent_transactions);

    // End simulation
    $finish;
  end

endmodule

