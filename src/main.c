#include "main.h"
#include "stm32f1xx_hal.h"
#include <string.h>

extern UART_HandleTypeDef huart2;  // لازم تكون مفعل USART2 من CubeMX

int main(void)
{
  HAL_Init();
  SystemClock_Config(); // مهيئة تلقائي من STM32Cube
  MX_USART2_UART_Init(); // دالة تهيئة USART2 من STM32Cube

  char msg[] = "STM32 is alive!\r\n";

  while (1)
  {
    HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
    HAL_Delay(1000); // تأخير ثانية
  }
}
