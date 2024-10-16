/*====================================================================================================*/
/*====================================================================================================*/
/*===============================      Name    : MahmoudAzmy       ===================================*/
/*===============================      Date    : 16/10/2024        ===================================*/
/*===============================      SWC     : SYSCFG            ===================================*/
/*===============================      Version : 1.0               ===================================*/
/*====================================================================================================*/
/*====================================================================================================*/
#ifndef SYSCFG_INTERFACE_H
#define SYSCFG_INTERFACE_H

typedef enum
{
	PORTA=0,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTH=7
}SYSCFG_Port_t;

typedef enum
{
	PIN0=0 ,
	PIN1   ,
	PIN2   ,
	PIN3   ,
	PIN4   ,
	PIN5   ,
	PIN6   ,
	PIN7   ,
	PIN8   ,
	PIN9   ,
	PIN10  ,
	PIN11  ,
	PIN12  ,
	PIN13  ,
	PIN14  ,
	PIN15
}SYSCFG_LineNum_t;

void SYSCFG_voidSetEXTIPort(SYSCFG_Port_t Copy_Port, SYSCFG_LineNum_t Copy_LineNum);

#endif
