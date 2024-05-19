#include  <reg51.h>
 sbit SW_OUT = P3^2;
 sbit SW_OFF = P3^3;
 sbit wave = P3^7;
 void delay();
 void duty();
	
void main()
{ while (SW_OUT==0){
	//wave = 1;
	duty();
}	
 while (SW_OUT==1){
	P0 = 0;
}	
}


void duty(){
unsigned char i, x, y,j;
P1 =0xFF;
	x = P1/10;
	y = P1%10;
	j = (x*10)+y;
	if(SW_OUT==0){
		while(SW_OFF == 1){
		for( i=j; i>0; i--){
			P0=1;
			delay();
	}
		for( i=(100-j); i>0; i--){
			P0=0;
			delay();
}
}
}	
}
	
	void delay(){
unsigned char i , j;
	for( j=140 ; j>0; j--);
	for( j=140 ; j>0; j--);
	}
