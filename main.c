#include "GPIO_cof.h"

int main(void){
	init_GPIO_CR(1,1,0,2); // Set pulse PortA, Pin PA1, Output, Output_Push-Pull
	init_GPIO_CR(2,0,1,0);
	while(1){
		D_Output(2,10,1);
		delay(500);
		D_Output(2,10,0);
	}
}
