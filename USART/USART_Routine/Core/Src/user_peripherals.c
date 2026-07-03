#include "user.h"

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == UART4)
    {
        // Process the received data in uart4_rx_buffer
        HAL_UART_Transmit(&huart4, uart4_rx_buffer, 1, HAL_MAX_DELAY); // Echo back the received byte

        // Restart the UART receive interrupt for the next byte
        HAL_UART_Receive_IT(&huart4, (uint8_t *)uart4_rx_buffer, 1);
    }
}