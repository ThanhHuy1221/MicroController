#include "GPIO_cof.h"

int main(void){
	unsigned short n = 0;
	//init_GPIO_CR(1,0,0,2); // Set pulse PortA, Pin PA0, Input, Input_Push-Pull
	/*
	init_GPIO_CR(2,0,1,0);
	while(1){
		Delay(1000);
		D_Output_toggle(2,0);
	}
	*/
	
	for(unsigned short i=0;i<=8;i++){
		init_GPIO_CR(2,i,1,0);
	}
	while(1){
		D_Output_toggle(2,n);
		Delay2(10);
		n++;
		if(n>8) n=0;
	}
}
