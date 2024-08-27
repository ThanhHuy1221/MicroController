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

void D_Output_toggle(unsigned short port, unsigned short pin) {
    uint32_t *ODR;
    // Adress GPIOX_ODR
    ODR = (uint32_t *)(ADD[port-1] + 0x0C);
    // Toggle Pin
    *ODR ^= (1 << pin);
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
	//return IDR_value;
}


void Delay2(uint32_t ms) {
		volatile int timer2_initialized = 0; 
    if (!timer2_initialized) {
        // Enable clock for TIM2
        RCC_APB1ENR |= RCC_APB1ENR_TIM2EN;

        // Cofig for TIM2 iterupt 1ms
        TIM2_PSC = (CLOCK_FREQ / 1000) - 1;  // 8MHz
        TIM2_ARR = 10;                      // Auto reload value
        TIM2_CNT = 0;                      // Reset counter
        TIM2_CR1 |= TIM_CR1_CEN;           // Active TIM2, DIR = 0, OPM = 0
        timer2_initialized = 1;  
    }
    while (ms > 0) {
        TIM2_CNT = 0;  // Reset counter
        while (TIM2_CNT < 10);  
        ms-=1;
    }
}

void Delay(uint32_t ms){
	volatile int timer2_initialized = 0; 
	if (!timer2_initialized) {
		// Enable clock for TIM1
    RCC_APB2_ENR |= (1 << 11);
		// Cofig for TIM1 iterupt 1ms
		TIM1_PSC = 8000-1;  // Prescaler = 
		TIM1_ARR = 1000-1;  // Auto-reload value = 
		TIM1_CR1 |= (1 << 3); //OPM
	}
  if(ms > 0){
		ms--;  
    TIM1_CR1 |= (1 << 0);
		while (TIM1_CR1 & (1 << 0));
  }
}

