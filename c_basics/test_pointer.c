
#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    // 你原本的代码：完全没动
    for (int i = 0; i < 5; i++) {
        if (*(arr + i) % 2 == 0) {
            *(arr + i) = 0;
        }
    }

    // 新增：打印出来验证一下
    printf("change result: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(arr + i)); // 打印指针偏移出来的元素
    }
    printf("\n");

    return 0;
}