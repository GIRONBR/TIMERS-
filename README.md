# TIMERS- CON TARJETA NUCLEO 

Este código es para un microcontrolador STM32 y está diseñado para controlar tres LEDs conectados a los pines PA5, PA6 y PA7. Los LEDs se encienden y apagan a diferentes frecuencias utilizando tres temporizadores (TIM2, TIM6 y TIM21).

Aquí está una descripción detallada de las partes clave del código:

Inclusión de bibliotecas y declaración de funciones: Las primeras líneas incluyen las bibliotecas necesarias y declaran las funciones que se definirán más adelante en el código.
Configuración de GPIO: En la función main(), se habilita el reloj para el puerto GPIOA y se configuran los pines PA5, PA6 y PA7 como salidas.
Configuración del sistema: Se llama a la función SystemClock_Config() para configurar el reloj del sistema a 16 MHz. Luego, se inicializan los tres temporizadores con las funciones TIM2_Init(), TIM6_Init() y TIM21_Init().
Bucle principal: En el bucle while(1), se comprueba continuamente el registro de estado (SR) de cada temporizador. Si el bit de actualización (bit 0) está establecido, se limpia el bit y se cambia el estado del LED correspondiente.
Funciones de inicialización del temporizador: Las funciones TIM2_Init(), TIM6_Init() y TIM21_Init() configuran los temporizadores TIM2, TIM6 y TIM21, respectivamente. Establecen los valores de los registros de prescaler (PSC) y auto-reload (ARR) para determinar la frecuencia de las interrupciones del temporizador.


el video de demostracion se muestra aqui https://youtu.be/vWePHX4b15w
