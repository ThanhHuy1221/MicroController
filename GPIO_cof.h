#ifndef _MYLIB_H_
#define _MYLIB_H_

#include <stdint.h>

//Clock 8MHz
#define CLOCK_FREQ 8000000  
//variable
#define RCC_APB2_ENR (*(volatile uint32_t*)(0x40021018))

#define GPIOA_BASE (uint32_t)0x40010800
#define GPIOB_BASE (uint32_t)0x40010C00
#define GPIOC_BASE (uint32_t)0x40011000

extern uint32_t ADD[3];

//function
extern void init_GPIO_CR (unsigned short port,unsigned short pin,unsigned short dir, unsigned short opt);
extern void D_Output(unsigned short port, unsigned short pin, unsigned short value); 
extern uint8_t D_Input(unsigned short port, unsigned short pin);
extern void delay(uint32_t ms);
#endif
