#include <stdio.h>
#include "uart.h"

int main() {
    printf("--- Setup System ---\n");
    int result = uart_send("Hello Luckfox!");
    printf("Send info: %d\n", result);
    return 0;
}