#include <stdio.h>
#include "uart.h"

int uart_send(const char *hello) {
    // 模拟发送过程
    printf("[UART] 正在发送: %s\n",hello );
    return 0; // 返回0表示成功
}