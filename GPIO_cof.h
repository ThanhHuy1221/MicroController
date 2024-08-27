#ifndef _MYLIB_H_
#define _MYLIB_H_

#include <stdint.h>

//Clock 8MHz
#define CLOCK_FREQ 8000000  

#define RCC_BASE            0x40021000  // Base address for RCC
#define RCC_APB1ENR        (*(volatile uint32_t*)(RCC_BASE + 0x1C))
#define RCC_APB2_ENR       (*(volatile uint32_t*)(RCC_BASE + 0x18))

#define GPIOA_BASE         (uint32_t)0x40010800
#define GPIOB_BASE         (uint32_t)0x40010C00
#define GPIOC_BASE         (uint32_t)0x40011000

#define TIM2_BASE           0x40000000 
#define TIM2_CR1           (*(volatile unsigned int *)(TIM2_BASE + 0x00))
#define TIM2_CNT           (*(volatile unsigned int *)(TIM2_BASE + 0x24))
#define TIM2_PSC           (*(volatile unsigned int *)(TIM2_BASE + 0x28))
#define TIM2_ARR           (*(volatile unsigned int *)(TIM2_BASE + 0x2C))

#define TIM1_BASE      0x40012C00
#define TIM1_CR1       *(volatile unsigned int*)(TIM1_BASE + 0x00)
#define TIM1_PSC       *(volatile unsigned int*)(TIM1_BASE + 0x28)
#define TIM1_ARR       *(volatile unsigned int*)(TIM1_BASE + 0x2C)

#define RCC_APB1ENR_TIM2EN 0x00000001  // Bit mask to enable TIM2 clock
#define TIM_CR1_CEN        0x0001      // Bit mask to enable TIM2 counter
	
extern uint32_t ADD[3];

//function
extern void init_GPIO_CR (unsigned short port,unsigned short pin,unsigned short dir, unsigned short opt);
extern void D_Output(unsigned short port, unsigned short pin, unsigned short value); 
extern void D_Output_toggle(unsigned short port, unsigned short pin);
extern uint8_t D_Input(unsigned short port, unsigned short pin);
extern void Delay2(uint32_t ms);
extern void Delay(uint32_t ms);
#endif
