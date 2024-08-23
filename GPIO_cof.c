#include "GPIO_cof.h"

//List adress GPIO base
uint32_t ADD[3]={GPIOA_BASE, GPIOB_BASE, GPIOC_BASE};


void init_GPIO_CR(unsigned short port,unsigned short pin,unsigned short dir, unsigned short opt){
	uint32_t *CR;
	//Enable clock at PortX
	RCC_APB2_ENR |= (1U << (port+1)); // 1: A, 2: B, 3: C
	//CR address and Pin
	if (pin <= 7){
        CR = (uint32_t *)((ADD[port-1])+ 0x00); // Address register CRL
    }else{
        CR = (uint32_t *)((ADD[port-1]) + 0x04); // Address register CRH
        pin -= 8; // Pin for CRH
    }
	//Set direction and option 
	*CR &= ~(uint32_t)(0xF << (pin * 4)); 
  *CR |= (uint32_t)((dir << (pin * 4)) | (opt << (pin * 4 + 2)));
}
void D_Output(unsigned short port,unsigned short pin, unsigned short value){ 
	uint32_t *ODR;
	//Adress GPIOX_ODR
	ODR = (uint32_t *)(ADD[port-1]+0x0C);
	//Get value of GPIOX_ODR
	uint32_t ODR_value = *ODR;
	//Set or Reset Pin 
	if (value) {
        ODR_value |= (1 << pin);
    } else {
        ODR_value &= ~(1 << pin);
    }
	*ODR = ODR_value;
}

uint8_t D_Input(unsigned short port, unsigned short pin){
	uint32_t *IDR;
	//Adress GPIOX_IDR
	IDR = (uint32_t *)(ADD[port-1]+0x08);
	uint32_t IDR_value = *IDR;
	return (IDR_value >> pin) & 0x01;
}

void delay(uint32_t ms){
	uint32_t delay_count = (CLOCK_FREQ / 1000) / 5; 
  while (ms--){
			for (uint32_t i = 0; i < delay_count; i++){
			}
    }
}
