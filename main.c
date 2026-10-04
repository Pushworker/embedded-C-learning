#include <stdio.h>
#include "uart.h"

int main() {
    printf("--- 系统启动 ---\n");
    int result = uart_send("Hello Luckfox!");
    printf("发送结果: %d\n", result);
    return 0;
}