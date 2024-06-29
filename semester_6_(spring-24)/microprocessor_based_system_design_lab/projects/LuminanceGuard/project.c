#include<reg51.h>
sbit sensor1 = P1^0;
sbit sensor2 = P1^1;
sbit sensor3 = P1^2;

sbit load1 = P2^0;
sbit load2 = P2^1;
sbit load3 = P2^2;

sbit ldr = P1^7;
sbit ldrout = P2^3;


sbit trigpin = P2^6;
sbit echopin = P2^7;
sbit led1 = P1^5;
sbit led2 = P1^6;

void delay(unsigned int z);
unsigned int distance,i;

void main(){
	load1 = load2 = load3 = 0;
	sensor1 = sensor2 = sensor3 = 0;
	ldr = ldrout = 0;
	
			echopin=1;
      led1=0;
      led2=0;
      trigpin=0;
      echopin=1;

      for(i=0;i<20000;i++);

			TMOD=0x01;
      TH0=0x00;
      TL0=0x00;
	
	while(1){
		
		if(ldr == 0){ // No Light means Night time
			ldrout = 1; // during night time green led turns on just for indication
			
		if(sensor1 == 0 && sensor2 == 0 && sensor3 == 0){
			load1 = load2 = load3 = 0;
		}
		if(sensor1 == 1){
			load1 = 1;
		}
		
		if(sensor2 == 1){
			load2 = 1;
		}
		
		if(sensor3 == 1){
			load3 = 1;
		}
		if(sensor1 == 0){
			load1 = 0;
		}
		
		if(sensor2 == 0){
			load2 = 0;
		}
		
		if(sensor3 == 0){
			load3 = 0;
		}
		}
		else{  // there is a light 
			ldrout = 0;
			load1 = load2 = load3 = 0;
		}  


						trigpin=1;
            for(i=0;i<=10;i++);
            trigpin=0;
            while(echopin==0);
            TR0=1;
            while(echopin==1);
            TR0=0;

            distance=TH0<<8;
            distance=distance+TL0;
            distance=distance/5;
            TH0=0x00;
            TL0=0x00;


            for(i=0;i<=20000;i++);

            if(distance<25)
            {
                led1=1; // Consider this, Car is Nearby
            }
            else
            {
                led1=0;
            }

            if(distance>50)
            {
                led2=1; // Just Ignore
            }

            else
            {
                led2=0;
            }

							
}
}

void delay(unsigned int z)
{
    unsigned int p,q;
    for(p=0;p<z;p++)//repeat for 'z' times
    {
      for(q=0;q<1375;q++); //repeat for 1375 times
    }
}