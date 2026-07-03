#include "user.h"

uint8_t uart4_rx_buffer[1] = {0};       // Buffer to store received data from UART4

/**
  * @brief initialize user-defined peripherals and settings.
  * @retval None
  */
void user_init(void)
{
 HAL_UART_Receive_IT(&huart4, (uint8_t *)uart4_rx_buffer, 1);
}
