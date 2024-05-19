#include <stdint.h>
#include "stm32l053xx.h"
#include "core_cm0plus.h"
void SystemClock_Config(void);
void TIM2_Init(void);
void TIM6_Int(void);
void TIM21_Init(void);


int main(void)
{
    // HABILITAR RCC DEL LOS PERIFERICOS GPIOA
    RCC->IOPENR |= RCC_IOPENR_GPIOAEN;

    // Configurar PA5, PA6 y PA7 como salida
    GPIOA->MODER &= ~(GPIO_MODER_MODE5 | GPIO_MODER_MODE6 | GPIO_MODER_MODE7);
    GPIOA->MODER |= (GPIO_MODER_MODE5_0 | GPIO_MODER_MODE6_0 | GPIO_MODER_MODE7_0);





    // CONFIGURACION GENERAL DEL SISTEMA
    // RELOJ DE 16 MHZ
    SystemClock_Config();
    // CADA TIMER QUE UTILIZAREMOS
    TIM2_Init();
    TIM6_Init();
    TIM21_Init();








    while(1)
    { //EMPIEZA BUCLE WHILE
        //PARA TIMER 2
        if (TIM2->SR & 0x00000001) {
            TIM2->SR &= ~0x00000001; // LIMPIA LA BANDERA
            GPIOA->ODR ^= (1 << 5);  // LED PA5
        }


        // PARA TIMER 6
               if (TIM6->SR & 0x00000001) {
                   TIM6->SR &= ~0x00000001; // LIMPIA LA BANDERA
                   GPIOA->ODR ^= (1<<6); // LED PA6
               }

        //  PARA TIMER 21
        if (TIM21->SR & 0x00000001) {
            TIM21->SR &= ~0x00000001; // LIMPIA LA BANDERA
            GPIOA->ODR ^= (1 << 7);  // LED PA7
        }
    } //TERMINA BUCLE WHILE
}

void SystemClock_Config(void)
{
    // ACTIVAR EL HSI
    RCC->CR |= RCC_CR_HSION;
    while (!(RCC->CR & RCC_CR_HSIRDY));

    // SELECCIONAR HSI
    RCC->CFGR |= RCC_CFGR_SW_HSI;
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI);
}


void TIM2_Init(void)
{
	// TIMER PARA
    // ACTIVA EL TIMER
    TIM2->CR1 |= (1 << 0);
    // HABILITA EL RELOJ PARA EL TIMER 2
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    // CONFIGURACION DEL TIMER
    TIM2->PSC = 1600 - 1;
    TIM2->ARR = 10000;
}
void TIM6_Init(void)

{
	// TIMER PARA 0.5 SEGUNDOS
	// ACTIVA EL TIMER
	   TIM6->CR1 |= (1 << 0);
	 // HABILITA EL RELOJ
	  RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;

	    // CONFIGURACON DEL TIMER
	  TIM6->PSC = 1600 - 1;
	  TIM6->ARR = 5000;

}




void TIM21_Init(void)
{
	//ACTIVA EL TIMER
	// 0.25 SEGUNDOS
	TIM21->CR1 |= (1 << 0);
    // HABILITA EL RELOJ DEL TIMER 21
    RCC->APB2ENR |= RCC_APB2ENR_TIM21EN;

    // CONGIGURACION DEL TIMER 21
    TIM21->PSC = 1600 - 1;
    TIM21->ARR = 2499;
}
