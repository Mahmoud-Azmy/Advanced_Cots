/*====================================================================================================*/
/*====================================================================================================*/
/*===============================      Name    : MahmoudAzmy       ===================================*/
/*===============================      Date    : 14/10/2024        ===================================*/
/*===============================      SWC     : EXTI              ===================================*/
/*===============================      Version : 1.0               ===================================*/
/*====================================================================================================*/
/*====================================================================================================*/
#include <stdint.h>
#include "Stm32f401.h"
#include "Err_Type.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"

/*=============== Global Array of Pointer to function to hold CallBackFun =================*/
static void(*EXTI_CallBackFunc[EXTI_LINESNUM])(void)={NULL};

uint8_t EXTI_u8Init(EXTI_config_t *Copy_Config)
{
	uint8_t Local_u8ErrorState =OK;
	if (Copy_Config !=NULL)
	{
       /*=============== Setting Trigger Source Configuration =================*/
		switch(Copy_Config->TrigSrc)
		{
		case FALLING_TRIG        :EXTI->FTSR |= (1<<Copy_Config->PinNum);
								  EXTI->RTSR &=~(1<<Copy_Config->PinNum);break;

		case RISING_TRIG         :EXTI->RTSR |= (1<<Copy_Config->PinNum);
								  EXTI->FTSR &=~(1<<Copy_Config->PinNum);break;

		case FALLING_RISING_TRIG :EXTI->FTSR |= (1<<Copy_Config->PinNum);
		                          EXTI->RTSR |= (1<<Copy_Config->PinNum);break;

		default                  :Local_u8ErrorState=NOK                ;break;

		}
	  /*============ Set Interrupt Enable/Disable Initial State ==============*/
		switch (Copy_Config->InitState) {
			case ENABLED  :EXTI->IMR |= (1<<Copy_Config->PinNum) ;break;
			case DISABLED :EXTI->IMR &= ~(1<<Copy_Config->PinNum);break;
			default       :Local_u8ErrorState=NOK                ;break;
		}

	   /*=============== Setting CallBack Function Pointer =================*/
		if (Copy_Config->CallBackFunc != NULL){
			EXTI_CallBackFunc[Copy_Config->PinNum]=Copy_Config->CallBackFunc;
		}
		else{
			Local_u8ErrorState=NULL_PTR_ERR;
			}
		}


	else
	{
		Local_u8ErrorState=NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}

uint8_t EXTI_u8SetTrigSrc(EXTI_TrigSrc_t Copy_TrigSrc,EXTI_LineNum Copy_PinNum)
{
	uint8_t Local_u8ErrorState =OK;
	if (PinNum<16)
	{
		 /*=============== Setting Trigger Source Configuration =================*/
				switch(Copy_TrigSrc)
				{
				case FALLING_TRIG        :EXTI->FTSR |= (1<<Copy_PinNum);
										  EXTI->RTSR &=~(1<<Copy_PinNum);break;

				case RISING_TRIG         :EXTI->RTSR |= (1<<Copy_PinNum);
										  EXTI->FTSR &=~(1<<Copy_PinNum);break;

				case FALLING_RISING_TRIG :EXTI->FTSR |= (1<<Copy_PinNum);
				                          EXTI->RTSR |= (1<<Copy_PinNum);break;

				default                  :Local_u8ErrorState=NOK        ;break;

				}
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}

void EXTI_voidEnableInt(EXTI_LineNum Copy_lineNum)
{
	EXTI->IMR |= (1<<Copy_lineNum);
}

void EXTI_voidu8DisableInt(EXTI_LineNum Copy_lineNum)
{
	EXTI->IMR &= ~(1<<Copy_lineNum);
}

void EXTI_voidClearPendingFlag(EXTI_LineNum Copy_line)
{
	EXTI->PR= 1<<Copy_line;
}

uint8_t EXTI_u8GetPendingFlag(EXTI_LineNum Copy_line, uint8_t *Copy_FlagStatus )
{
	uint8_t Local_u8ErrorState =OK;
	if (Copy_FlagStatus != NULL){
		*Copy_FlagStatus= ((EXTI->PR >>Copy_line)&1);
	}

	return Local_u8ErrorState;
}





