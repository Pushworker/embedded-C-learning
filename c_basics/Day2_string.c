
#include <stdio.h>

// 任务 1：手写 my_strlen
// 功能：计算字符串长度（不包含 '\0'）
// 提示：用指针遍历，直到遇到 '\0' 停止，每次循环计数器 +1
int my_strlen(const char *str) {
   int count = 0;
    while ( *str != '\0' ) {   // 提示：只要 *str 不等于 '\0' 就继续
        count++;
        str++;        // 指针向后移动一位
    }
    return count;
    return 0;
}

// 任务 2：手写 my_strcpy
// 功能：把 src 指向的字符串，复制到 dest 指向的内存里
// 提示：用一个 while 循环，把 *src 赋值给 *dest，然后两个指针同时 ++，直到 *src 为 '\0'
void my_strcpy(char *dest, const char *src) {
    
    while (*src != '\0') {
        *dest = *src; // 把 src 当前字符，赋值给 dest 当前内存
        dest++;       // dest 指针往后挪
        src++;        // src 指针往后挪
    }
    
    // 2. 极其重要！！！手动在 dest 结尾补上 '\0'
    *dest = '\0'; 

}

int main() {
    char *message = "Hello, Embedded!";
    
    // 测试 strlen
    int len = my_strlen(message);
    printf("String length: %d\n", len); // 应该输出 16

    // 测试 strcpy
    char buffer[50]; // 声明一个足够大的数组来接收拷贝
    my_strcpy(buffer, message);
    printf("Copied string: %s\n", buffer); // 应该输出 Hello, Embedded!

    return 0;
}


/*int my_strlen(char *str ){
    int count = 0;
    while(*str != '\0')
    {
        *str++;
        count++;
    }
    return count;
}*/