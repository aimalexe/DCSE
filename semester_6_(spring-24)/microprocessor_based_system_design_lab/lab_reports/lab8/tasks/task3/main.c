#include<reg51.h>

unsigned int i, j;
int l, u;

void delay(unsigned int milliSecond){
	for(i = 0; i < milliSecond; i++)
		for(j = 0; j < 1225; j++);
}

int main(){
	while(1){
		for(i = 0; i < 256; i++){
	//		for(j = 0; j <= 9; j++){
	//			P2 = (i << 4) | j;
	//			delay(30);
	//		}
			l = i & 0x0f;
			u = i & 0xf0;
			
			if(l == 0x09)
				l = 0x00;
			if(u == 0x90)
				u = 0x00;
			
			P2 = (u << 4) | l;
			delay(30);
		}
		

	}
}