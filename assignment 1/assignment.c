#include  <reg51.h>
 sbit SW_inc = P3^2;
 sbit SW_dec = P3^3;

unsigned char CC_PATTERNS[]={ ~0x3F, ~0x06, ~0x5B, ~0x4F, ~0x66, ~0x6D, ~0x7D, ~0x07, ~0x7F, ~0x6F, ~0x00  };
	
void delay();
	
	
void main()
{
	 
	 unsigned char index = 0;
	
	 SW_inc = 1;
	 SW_dec=1;
	 while(1)
	 { 
		 while(SW_inc == 0)
		 {
			 if(index<10){
			 P2 = CC_PATTERNS[index];
				 index++;
				 delay();
				 
		 }
		 else if(index==10){
			 index=0;
			 P2 = CC_PATTERNS[index];
			 delay();
		 }
	 }
		 
		 index--;
		 
			 while(SW_dec == 0)
		 {  
			 if(index>0){
			 P2 = CC_PATTERNS[index];
				 index--;
				 delay();
				 
			 }
	
			 else if(index==0){
				 P2 = CC_PATTERNS[index];
				 index=9;
				 delay();
				 
			 }
		 }
		 index++;
		 
	 
	 }
 }
void delay()
{
	unsigned char i, j, k;
		for( i = 2; i > 0; i--)
			for( j = 255; j > 0; j--)
				for( k = 255; k > 0; k--);
}

	



