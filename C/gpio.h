//Version 4.0

#ifndef GPIO_H
#define GPIO_H

#define uint32_t unsigned int
#define uint16_t unsigned short
#define uint8_t unsigned char

void set_up_DIL( void );
char read_DIL( void );
int read_DIL_single( int bit );

#define B_E				0x40
#define B_SELECT		4
#define B_RW			2
#define B_RS			1

typedef struct {
	uint32_t Moder;
	uint16_t oTyper; // +0x4
	uint16_t otReserved;
	uint32_t oSpeedr; // +0x8
	uint32_t PuPdr; // +0xc
	uint8_t idrLow; // +0x10
	uint8_t idrHigh; // +0x11
	uint16_t idrReserved;
	uint8_t odrLow; // +0x14
	uint8_t odrHigh; // +0x15
	uint16_t odrReserved;
} GPIO;


#define GPIO_D (*((volatile GPIO*) 0x40020c00))
#define GPIO_E (*((volatile GPIO*) 0x40021000))

typedef struct {
	uint16_t memrp;
	uint16_t memrpReserved;
	uint16_t pmcReservedBefore;
	uint8_t	pmc;
	uint8_t pmcReservedAfter;
	uint32_t extiCr1;
	//uint16_t exticr1Reserved;
	uint32_t extiCr2;
	//uint16_t extiCr2Reserved;
	uint32_t extiCr3;
	//uint16_t extiCr3Reserved;
	uint32_t extiCr4;
	//uint16_t extiCr4Reserved;
	uint32_t cmpCr;
} SYSCFG_STRUCT;

#define SYSCFG (*((volatile SYSCFG_STRUCT*) 0x40013800))

typedef struct {
	uint32_t ctrl;
	uint32_t load;
	uint32_t val;
} STK_STRUCT;

#define STK_CTRL_ADDR 0xe000e010
#define STK (*((volatile STK_STRUCT*) STK_CTRL_ADDR))

typedef struct {
	uint32_t imr;
	uint32_t emr;
	uint32_t rtsr;
	uint32_t ftsr;
	uint32_t swier;
	uint32_t pr;
} EXTI_STRUCT;

#define EXTI (*((volatile EXTI_STRUCT*) 0x40013c00))

typedef struct {
	uint32_t iser0;
	uint32_t iser1;
	uint16_t iser2;
	uint16_t iser2Reserved;

	uint32_t cer0;
	uint32_t cer1;
	uint16_t cer2;
	uint16_t cer2Reserved;

	uint32_t ispr0;
	uint32_t ispr1;
	uint16_t ispr2;
	uint16_t ispr2Reserved;

	uint32_t icpr0;
	uint32_t icpr1;
	uint16_t icpr2;
	uint16_t icpr2Reserved;

	uint32_t iabr0;
	uint32_t iabr1;
	uint16_t iabr2;
	uint16_t iabr2Reserved;
	
	uint32_t ipr0;
	uint8_t ipr20;
} NVIC_STRUCT;

#define NVIC (*((volatile NVIC_STRUCT*) 0xe000e100))


#define EXTI_3_IRQVEC *((void (**) (void) ) 0x2001c064)
#define EXTI_2_IRQVEC *((void (**) (void) ) 0x2001c060)
#define EXTI_1_IRQVEC *((void (**) (void) ) 0x2001c05c)
#define EXTI_0_IRQVEC *((void (**) (void) ) 0x2001c058)

#define NVIC_EXTI3_IRQ_BPOS (1<<9)
#define NVIC_EXTI2_IRQ_BPOS (1<<8)
#define NVIC_EXTI1_IRQ_BPOS (1<<7)
#define NVIC_EXTI0_IRQ_BPOS (1<<6)
#define EXTI3_IRQ_BPOS (1<<3)
#define EXTI2_IRQ_BPOS (1<<2)
#define EXTI1_IRQ_BPOS (1<<1)
#define EXTI0_IRQ_BPOS (1<<0)


 
#endif