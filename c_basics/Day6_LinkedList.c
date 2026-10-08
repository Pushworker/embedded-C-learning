#include <stdio.h>
#include <stdlib.h>

// 1. 定义节点（车厢）结构体
// 注意：在 typedef 里面自引用必须用 struct Node *
typedef struct Node {
    int data;            // 数据（货物）
    struct Node *next;   // 指针（铁钩），指向下一个节点
} Node;

int main() {
    printf("--- Linked List Manual Connect ---\n");

    // 2. 手动造两节车厢
    // TODO 1: 用 malloc 造出第一个节点 A，把它的 data 设为 10，next 设为 NULL。
    // 提示：Node *A = (Node *)malloc(sizeof(Node));
    Node *A  = (Node*)malloc(sizeof(Node));
    A->data = 10;
    A->next = NULL;

    // TODO 2: 用 malloc 造出第二个节点 B，把它的 data 设为 20，next 设为 NULL。
    Node *B  = (Node*)malloc(sizeof(Node));
    B->data = 20;
    B->next = NULL;

    // 3. 检查内存是否申请成功
    // TODO 3: 一定要加上 if (A == NULL || B == NULL) 的处理，防止段错误。

    if (A == NULL || B == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }
    

    // 4. 关键一步：挂钩！
    // TODO 4: 让 A 的 next 指针，指向 B 的地址。
     A->next = B;

     
    // 提示：A->next = B;
    
    // 5. 顺着火车头 A，把整列火车打印出来
    printf("A's data: %d\n", A->data);
    
    printf("Size of Node: %zu bytes\n", sizeof(Node));
    // TODO 5: 不要直接写 B->data，而是用 A->next->data 来打印。
    // 这样你就通过指针，从 A 找到了 B。
    printf("A->next->data: %d\n", A->next->data); // 改掉这行

    // 6. 释放内存（必须先释放 A 的钩子，再 free A，最后 free B）
    // 但今天先不管这个，我们先跑通。你如果写了 free，不要忘了把指针置空。
    Node *temp = A->next; 
    
    // 2. 释放 A
    free(A);
    A = NULL;
    
    // 3. 释放 B（也就是刚才保存的临时变量）
    free(temp);
    temp = NULL;
    
    printf("--- Memory freed ---\n");
    
    return 0;
}