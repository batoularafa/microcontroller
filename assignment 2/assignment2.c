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
	wave = 0;
}	

}

void duty(){
P1 =0xFF;
	if(P1==0x25&&SW_OUT==0){
		while(SW_OFF==1&&P1==0x25){
		wave=1;
		delay();
		wave=0;
		delay();
		delay();
		delay();
	}
}
	else if(P1==0x50&&SW_OUT==0){
		while(SW_OFF==1 &&P1==0x50){
		wave=1;
		delay();
		delay();
		wave=0;
		delay();
		delay();
	}
}
	else if(P1==0x75&&SW_OUT==0){
		while(SW_OFF==1&&P1==0x75){
		wave=1;
		delay();
		delay();
		delay();
		wave=0;
		delay();
	}
}
}
	
	void delay(){
unsigned char i , j, k;
	for( k=250 ; k>0; k--){
	for( i=250 ; i>0; i--);
	for( j=250 ; j>0; j--);
	}
}