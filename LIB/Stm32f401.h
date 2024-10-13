/*====================================================================================================*/
/*====================================================================================================*/
/*===============================      Name    : Mahmoud Azmy      ===================================*/
/*===============================      Date    : 20/9/2024         ===================================*/
/*===============================      SWC     : STM32F401         ===================================*/
/*===============================      Version : 1.0               ===================================*/
/*====================================================================================================*/
/*====================================================================================================*/
#ifndef STM32F401_H
#define STM32F401_H

/*====================================================================================================*/
/*==============================   Various Memories Base Addresses   =================================*/
/*====================================================================================================*/

#define FLASH_BASE_ADDRESS              0x08000000UL
#define SRAM_BASE_ADDRESS               0x20000000UL
#define ROM_BASE_ADDRESS                0x1FFF0000UL 
 
/*====================================================================================================*/
/*===============================   AHB1 Peripheral Base Addresses   =================================*/
/*====================================================================================================*/

#define GPIOA_BASE_ADDRESS               0x40020000UL 
#define GPIOB_BASE_ADDRESS               0x40020400UL 
#define GPIOC_BASE_ADDRESS               0x40020800UL 
#define GPIOD_BASE_ADDRESS               0x40020C00UL 
#define GPIOE_BASE_ADDRESS               0x40021000UL 
#define GPIOH_BASE_ADDRESS               0x40021C00Ul

#define RCC_BASE_ADDRESS                 0x40023800Ul




/*====================================================================================================*/
/*==============================   AHB2 Peripheral Base Addresses   ==================================*/
/*====================================================================================================*/



/*====================================================================================================*/
/*==============================   AHB3 Peripheral Base Addresses   ==================================*/
/*====================================================================================================*/



/*====================================================================================================*/
/*==============================   APB1 Peripheral Base Addresses   ==================================*/
/*====================================================================================================*/




/*====================================================================================================*/
/*==============================   APB2 Peripheral Base Addresses   ==================================*/
/*====================================================================================================*/




/*====================================================================================================*/
/*===============================   GIPO Register Definition Structure  ==============================*/
/*====================================================================================================*/

typedef struct
{
	volatile uint32_t MODER   ;                              /*GPIO port mode register                */
	volatile uint32_t OTYPER  ;                              /*GPIO port output type register         */
	volatile uint32_t OSPEEDR ;                              /*GPIO port speed Register               */
	volatile uint32_t PUPDR   ;                              /*GPIO port pull-up/pull-down Register   */
	volatile uint32_t IDR     ;                              /*GPIO port input data Register          */
	volatile uint32_t ODR     ;                              /*GPIO port output data Register         */
	volatile uint32_t BSRR    ;                              /*GPIO port bit set/reset Register       */
	volatile uint32_t LCKR    ;                              /*GPIO port configuration lock Register  */
	volatile uint32_t AFR[2]  ;                              /*GPIO alternate function Register       */

}GPIO_RegDef_t;



/*=====================================================================================================*/
/*===============================   RCC Register Definition Structure  ================================*/
/*=====================================================================================================*/

typedef struct
{                                                                                                      
   volatile uint32_t CR           ;     /* RCC clock control register                                  */
   volatile uint32_t PLLCFGR      ;     /* RCC PLL configuration register                              */
   volatile uint32_t CFGR         ;     /* RCC clock configuration register                            */
   volatile uint32_t CIR          ;     /* RCC clock interrupt register                                */
   volatile uint32_t AHB1RSTR     ;     /* RCC AHB1 peripheral reset register                          */
   volatile uint32_t AHB2RSTR     ;     /* RCC AHB2 peripheral reset register                          */
   uint32_t          Reserved0[2] ;     /* Reserved => 0x18-0x1c                                       */
   volatile uint32_t APB1RSTR     ;     /* RCC APB1 peripheral reset register                          */
   volatile uint32_t APB2RSTR     ;     /* RCC APB2 peripheral reset register                          */
   uint32_t          Reserved1[2] ;     /* Reserved => 0x28-0x2c                                       */
   volatile uint32_t AHB1ENR      ;     /* RCC AHB1 peripheral clock enable register                   */
   volatile uint32_t AHB2ENR      ;     /* RCC AHB2 peripheral clock enable register		           */
   uint32_t          Reserved2[2] ;     /* Reserved => 0x38-0x3c              				           */
   volatile uint32_t APB1ENR      ;     /* RCC APB1 peripheral clock enable register                   */
   volatile uint32_t APB2ENR      ;     /* RCC APB2 peripheral clock enable register                   */
   uint32_t          Reserved3[2] ;     /* Reserved => 0x48-0x4c                                       */
   volatile uint32_t AHB1LPENR    ;     /* RCC AHB1 peripheral clock enable in low power mode register */
   volatile uint32_t AHB2LPENR    ;     /* RCC AHB2 peripheral clock enable in low power mode register */
   uint32_t          Reserved4[2] ;     /* Reserved => 0x58-0x5c                                       */
   volatile uint32_t APB1LPENR    ;     /* RCC APB1 peripheral clock enable in low power mode register */
   volatile uint32_t APB2LPENR    ;     /* RCC APB2 peripheral clock enable in low power mode register */
   uint32_t          Reserved5[2] ;     /* Reserved => 0x68-0x6c                                       */
   volatile uint32_t BDCR         ;     /* RCC Backup domain control register                          */
   volatile uint32_t CSR          ;     /* RCC clock control & status register                         */
   uint32_t          Reserved6[2] ;     /* Reserved => 0x78-0x7c                                       */
   volatile uint32_t SSCGR        ;     /* RCC spread spectrum clock generation register               */
   volatile uint32_t PLLI2SCFGR   ;     /* RCC PLLI2S configuration register                           */
   uint32_t          Reserved7    ;     /* Reserved => 0x88                                            */
   volatile uint32_t DCKCFGR      ;     /* RCC Dedicated Clocks Configuration Register                 */
   
}RCC_RegDef_t;



/*======================================================================================================*/
/*==================================   GIPO Peripheral Definition   ====================================*/
/*======================================================================================================*/

#define GPIOA                                  ((GPIO_RegDe_t *) GPIOA_BASE_ADDRESS )
#define GPIOB                                  ((GPIO_RegDe_t *) GPIOB_BASE_ADDRESS )
#define GPIOC                                  ((GPIO_RegDe_t *) GPIOC_BASE_ADDRESS )
#define GPIOD                                  ((GPIO_RegDe_t *) GPIOD_BASE_ADDRESS )
#define GPIOE                                  ((GPIO_RegDe_t *) GPIOE_BASE_ADDRESS )
#define GPIOH                                  ((GPIO_RegDe_t *) GPIOH_BASE_ADDRESS )


/*======================================================================================================*/
/*==================================   RCC Peripheral Definition   =====================================*/
/*======================================================================================================*/

#define RCC                                  ((RCC_RegDef_t *) RCC_BASE_ADDRESS )


#endif