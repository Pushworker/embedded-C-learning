#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr; // p 指向数组的第一个元素
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("--- Using pointer to traverse array ---\n");

    for (int i = 0; i < length; i++) {
        // 1. 判断当前指针指向的值（*p）是不是偶数
        
        if (*p % 2 == 0) {
            //*p 取的是这个地址所对应的值
            //&p 取的是当前对应的地址
            *p = 0; // 修改指针指向的内存里的值，改成 0
        }
        
        // 2. 打印当前元素
        printf("Element %d: %d\n", i, *p);
        
        // 3. 指针向前移动一步（不管是不是偶数都要移动！）
        p++; 
    }

    

    return 0;
}