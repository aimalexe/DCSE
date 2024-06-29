
module vending_machine(
    input clk,
    input rst, 
    input coinin,refund,
    input [2:0] coin, 
    input [3:0] choice,
    input monster_s,coke_s,fanta_s,sprite_s,dew_s,drpepper_s,
    input nickel_s,dime_s,quarter_s,half_dollar_s, nickels19,
    output reg [3:0] dispense,
    output reg [7:0] coin_count,
    output reg [4:0] nickel_out,dime_out,quarter_out,half_dollar_out,dollar_out,
    output reg [3:0] output_state,
    output reg [4:0] nickelct,dimect,quarterct,half_dollarct,dollarct
    
    );
reg [7:0] change;
//reg [4:0] nickelct,dimect,quarterct,half_dollarct,dollarct;
reg [3:0] present_state, next_state;

initial {dollarct,half_dollarct,quarterct,dimect,nickelct} = 5'b00000;
//wire coint;
initial coin_count=0;
//initial output_state=4'b0000;

    localparam nickel = 3'b001;
    localparam dime = 3'b010;
    localparam quarter = 3'b011;
    localparam half_dollar = 3'b100;
    localparam dollar = 3'b101;
    
    localparam coke = 3'b001;
    localparam fanta = 3'b010;
    localparam sprite= 3'b011;
    localparam dew = 3'b100;
    localparam drpepper = 3'b101;
    localparam monster = 3'b110;
    
    localparam idle_state = 4'b0000;
    localparam counting_state = 4'b0001;
    localparam start_state = 4'b0010;
    localparam dispense_state = 4'b0011;
    localparam change_state = 4'b0100;
    localparam stop_state = 4'b0101;
    localparam nodrink_state = 4'b0110;
    localparam notenough_state = 4'b0111;
    localparam refund_state = 4'b1000;
    
    initial present_state = idle_state;
    initial next_state = idle_state;
   // assign coint=coinin;
    always @ (posedge clk)
        begin
            case(present_state)
                idle_state:
                    begin
                         if (coinin)
                               next_state=counting_state;
                    end
                counting_state:
                    begin                 
                    if((coin_count)<245 && choice==0 && refund==0)
                        begin                            
                            case(coin)
                            nickel: 
                                begin
                                nickelct=nickelct+1'b1; 
                                coin_count=coin_count+5;
                                end                  
                            dime:
                                begin
                                dimect=dimect+1'b1;
                                coin_count=coin_count+10;
                                end                           
                            quarter:
                                begin
                                quarterct=quarterct+1'b1; 
                                coin_count=coin_count+25;
                                end            
                            half_dollar:
                                begin
                                half_dollarct=half_dollarct+1'b1;
                                coin_count=coin_count+50;
                                end
                            dollar:
                                begin
                                dollarct=dollarct+1'b1;
                                coin_count=coin_count+100;
                                end                                                   
                            endcase
                            //coin_count<=coin_count+(nickelct*5+dimect*10+quarterct*25+half_dollarct*50+dollarct*100);
                            //{dollarct,half_dollarct,quarterct,dimect,nickelct} = 5'b00000;
                        end
                        
                    else   
                        begin
                            //coin_count<=nickelct*5+dimect*10+quarterct*25+half_dollarct*50+dollarct*100;                     
                            next_state=start_state;
                        end                              
                   end
                                      
                start_state:
                begin
                    if(coin_count>=150 && refund==0)
                    begin
                        case(choice)
                            coke:if(coke_s)
                                    next_state=dispense_state;  
                                 else
                                    next_state=nodrink_state;                                                                                            
                            fanta:if(fanta_s)
                                    next_state=dispense_state;  
                                  else
                                    next_state=nodrink_state;                                      
                            sprite:if(sprite_s)
                                    next_state=dispense_state;
                                   else
                                    next_state=nodrink_state;                                        
                            dew:if(dew_s)
                                    next_state=dispense_state;
                                else
                                    next_state=nodrink_state;                                        
                            drpepper:if(drpepper_s)
                                        next_state=dispense_state;
                                     else
                                        next_state=nodrink_state;                                        
                            monster:if(monster_s)
                                        next_state=dispense_state;
                                    else
                                        next_state=nodrink_state;                                                                                                           
                        endcase 
                    end
                    else
                        next_state=refund_state; 
                 end
                        
                dispense_state:
                begin
                    if(nickels19)
                    next_state=change_state;
                    else
                    begin
                    {dollarct,half_dollarct,quarterct,dimect,nickelct} = 5'b00000;
                    next_state=stop_state;
                    end
                end  
                
                nodrink_state:
                begin
                    if (refund)
                        next_state=refund_state; 
                    else
                        next_state=start_state; 
                end
                
//                notenough_state:
//                begin
//                    if(refund)
//                        next_state=refund_state;
//                     else
//                        next_state=counting_state;
//                end
                
                refund_state:
                begin
                    dollar_out=dollarct;
                    half_dollar_out=half_dollarct;
                    quarter_out=quarterct;
                    dime_out=dimect;
                    nickel_out=nickelct;
                    dispense=0;
                    coin_count=0;
                    {dollarct,half_dollarct,quarterct,dimect,nickelct} = 5'b00000;
                    next_state=idle_state;
                end
                
                change_state:
                begin
                    {dollarct,half_dollarct,quarterct,dimect,nickelct} = 5'b00000;
                    change=coin_count-150;
                    while(change>0)
                        begin
                    if(change>=50 && half_dollar_s)
                            begin
                            half_dollarct=1;
                            change=change-50;
                            end
                    else if (change>=25 && quarter_s)
                            begin
                            quarterct=1;
                            change=change-25;
                            end
                    else if (change>=10 && dime_s)
                            begin
                            dimect=dimect+1;
                            change=change-10;
                            end
                    else if (change>=5 && nickel_s)
                            begin
                            nickelct=nickelct+1; 
                            change=change-5;    
                            end         
                        end 
                   next_state=stop_state;                   
                end 
                
                stop_state:
                    begin
                        half_dollar_out=half_dollarct;
                        quarter_out=quarterct;
                        dime_out=dimect;
                        nickel_out=nickelct;
                        dispense=choice;
                        coin_count=0;
                        {dollarct,half_dollarct,quarterct,dimect,nickelct} = 5'b00000;
                        next_state=idle_state;
                    end 
                                           
            endcase
        end
        
    always @ (posedge clk)
        begin
            if (rst == 1'b1) 
                begin
                    present_state = idle_state;
                    output_state = present_state;
                end
            else 
                begin
                    present_state = next_state;
                    output_state = present_state;                   
                end
        end
        
 //assign output_state = present_state;
endmodule   
