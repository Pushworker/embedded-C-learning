#include <stdio.h>
#include "uart.h"

int uart_send(const char *hello) {
    // 模拟发送过程
    printf("[UART] sending: %s\n",hello );
    return 0; // 返回0表示成功
}