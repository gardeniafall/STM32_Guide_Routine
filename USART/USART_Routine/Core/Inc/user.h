#ifndef __USER_H
#define __USER_H

#include "main.h"
#include "usart.h"
#include "gpio.h"

extern uint8_t uart4_rx_buffer[1];

void user_init(void);
void user_loop(void);

#endif /* __USER_H */