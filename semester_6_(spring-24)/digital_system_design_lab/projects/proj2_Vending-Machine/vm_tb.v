
module vendingmachine_tb(
    );
    reg clk;
    reg rst; 
    reg coinin,refund;
    reg [2:0] coin; 
    reg [3:0] choice;
    reg monster_s,coke_s,fanta_s,sprite_s,dew_s,drpepper_s;
    reg nickel_s,dime_s,quarter_s,half_dollar_s, nickels19;
    wire [3:0] dispense;
    wire [7:0] coin_count;
    wire [4:0] nickel_out,dime_out,quarter_out,half_dollar_out,dollar_out;
    wire [3:0] output_state;
    wire [4:0] nickelct,dimect,quarterct,half_dollarct,dollarct;
    
    vending_machine UUT(clk,rst,coinin,refund,coin,choice,monster_s,coke_s,fanta_s,sprite_s,dew_s,drpepper_s,
                       nickel_s,dime_s,quarter_s,half_dollar_s, nickels19,dispense,coin_count,
                       nickel_out,dime_out,quarter_out,half_dollar_out,dollar_out,output_state,
                       nickelct,dimect,quarterct,half_dollarct,dollarct);
    initial begin 
            clk=1;
            rst=0;
            coinin=0; //initialize to 0
            refund=0; 
            choice=3'b000;
            {monster_s,coke_s,fanta_s,sprite_s,dew_s,drpepper_s}=6'b111111; //all drinks available
            {nickel_s,dime_s,quarter_s,half_dollar_s, nickels19}=5'b11111;  //atleast one coin avaiable
            coin=0;
        //////////////////////////
        #10 coinin=1;//coin in
            coin=3'b000;
        #10 coin=3'b100;//half_dollar
        #10 coin=3'b101;//dollar
        #10 coinin=0;
            coin=0;
        #10 choice=3'b001;//coke
        #50 choice=0;
        /////////////////////////max change
        #10 coinin=1;
            coin=3'b000;
        #10 coin=3'b101;//dollar
        #10 coin=3'b101;//dollar
        #10 coin=3'b011;//quarter
        #10 coin=3'b010;//dime
        #10 coin=3'b010;//dime
        #10 coinin=0;
            coin=0;
        #10 choice=3'b010;//fanta
        #50 choice=0;
        //////////////////////////////
        #10 monster_s=0; //monster not available
        #10 coinin=1;
            coin=3'b000;
        #10 coin=3'b001;//n
        #10 coin=3'b010;//d
        #10 coin=3'b011;//q
        #10 coin=3'b010;//d
        #10 coin=3'b010;//d
        #10 coin=3'b100;//hd
        #10 coin=3'b010;//d
        #10 coin=3'b011;//q
        #10 coin=3'b010;//d
        #10 coin=3'b010;//d 
        //total 6 dimes, 1 nickel,2 quarter, 1 hd inserted      
        #10 coinin=0;
            coin=0;
        #10 choice=3'b110;//monster
        #30 choice=0;
        #40 choice=3'b011;//sprite
        #50 choice=0;
           /////////////////exact change only for $1.55
//          #10 coinin=1;
//              coin=0; 
//          #10 nickels19=0;//the machine can't guarantee exact change
//              coin=3'b011;//quarter 
//          #10 coin=3'b011;//quarter
//          #10 coin=3'b011;//quarter
//          #10 coin=3'b100;//half-dollar  
//          #10 coin=3'b010;//dime
//          #10 coin=3'b010;//dime
//          #10 coin=3'b010;//dime  
//          #10 coinin=0;
//                coin=0;
//          #10 choice=3'b100;//dew
//          #50 choice=0;
        
        
        
         
        
    end
    
    always begin
    #5 clk=~clk;
    end
endmodule
