/*====================================================================================================*/
/*====================================================================================================*/
/*===============================      Name    : MahmoudAzmy       ===================================*/
/*===============================      Date    : 14/10/2024        ===================================*/
/*===============================      SWC     : EXTI              ===================================*/
/*===============================      Version : 1.0               ===================================*/
/*====================================================================================================*/
/*====================================================================================================*/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

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
}EXTI_LineNum;


typedef enum
{

	FALLING_TRIG,
	RISING_TRIG,
	FALLING_RISING_TRIG

}EXTI_TrigSrc_t;

typedef enum
{

	ENABLED,
	DISABLED

}EXTI_InitState_t;

typedef struct
{
	EXTI_LineNum PinNum;
	EXTI_TrigSrc_t TrigSrc;
	EXTI_InitState_t InitState;
	void (*CallBackFunc)(void);

}EXTI_config_t;


uint8_t EXTI_u8Init(EXTI_config_t *Copy_Config);

uint8_t EXTI_u8SetTrigSrc(EXTI_TrigSrc_t Copy_TrigSrc,EXTI_LineNum Copy_PinNum);

void EXTI_voidEnableInt(EXTI_LineNum Copy_lineNum);

void EXTI_voidDisableInt(EXTI_LineNum Copy_lineNum);

void EXTI_voidClearPendingFlag(EXTI_LineNum Copy_line);

uint8_t EXTI_u8GetPendingFlag(EXTI_LineNum Copy_line, uint8_t *Copy_FlagStatus );

#endif









