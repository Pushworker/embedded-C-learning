#include <stdio.h>
#include <stdlib.h> // malloc 和 free 的头文件

// 1. 定义一个结构体，代表我们的“动态数组”
typedef struct {
    int *data;      // 指向堆内存的指针
    int size;       // 当前存了多少个元素
    int capacity;   // 总共能装多少个元素
} DynamicArray;

// 2. 初始化：先分配 2 个 int 的空间
void init_array(DynamicArray *arr) {
    arr->capacity = 2;
    arr->size = 0;
    // malloc 分配内存。sizeof(int) 是 4 字节，乘 2 就是 8 字节
    arr->data = (int *)malloc(sizeof(int) * arr->capacity); 
    
    if (arr->data == NULL) {
        printf("内存分配失败！\n");
        exit(1);
    }
}

// 3. 添加元素：如果满了，就扩容
void push_back(DynamicArray *arr, int value) {
    // 如果容量满了，翻倍扩容
    if (arr->size >= arr->capacity) {
        arr->capacity *= 2;
        // realloc 重新分配内存，并把旧数据拷贝过去
        arr->data = (int *)realloc(arr->data, sizeof(int) * arr->capacity);
        if (arr->data == NULL) {
            printf("扩容失败！\n");
            exit(1);
        }
        printf("[系统] 触发扩容，新容量: %d\n", arr->capacity);
    }
    // 写入数据，并增加 size
    arr->data[arr->size] = value;
    arr->size++;
}

// 4. 释放内存：绝对别忘了！
void free_array(DynamicArray *arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

int main() {
    DynamicArray arr;
    init_array(&arr);

    // 疯狂塞数据，观察扩容过程
    for (int i = 1; i <= 10; i++) {
        push_back(&arr, i * 100);
        printf("插入元素: %d, 当前 size: %d, 当前 capacity: %d\n", i * 100, arr.size, arr.capacity);
    }

    // 打印最终结果
    printf("\n最终数组内容: ");
    for (int i = 0; i < arr.size; i++) {
        printf("%d ", arr.data[i]);
    }
    printf("\n");

    free_array(&arr);
    return 0;
}