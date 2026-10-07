#include <stdio.h>

// 1. 定义节点（车厢）
typedef struct Node {
    int data;
    struct Node *next; // 指向下一个节点的指针
} Node;

int main() {
    // 2. 在栈上创建两个节点（直接在内存里摆两节车厢）
    Node n1, n2;  
    // 3. 放入货物
    n1.data = 10;
    n2.data = 20;

    // 4. 核心魔法：连接它们！
    // 把 n2 的地址（&n2），放到 n1 的钩子（next）里
    n1.next = &n2; 
    
    // 把 n2 的钩子设为 NULL（表示火车到头了，后面没车厢了）
    n2.next = NULL;

    // 5. 见证奇迹：只通过 n1，找到 n2 的数据
    printf("n1 data: %d\n", n1.data);
    
    // 这一步稍微有点绕：n1.next 是 n2 的地址。
    // 所以 n1.next->data 就等于 n2.data
    printf("n2 data (via n1.next): %d\n", n1.next->data);

    return 0;
}