#include <stdio.h>
#include <stdlib.h>


//malloc的基本语法：指针变量 = (指针类型 *)malloc(要分配的字节数);
int main(){
    // 1. 申请：向系统申请 1 个 int 大小的内存（4字节）
    // malloc 返回的是一个地址（指针）
    int *p = (int *)malloc(sizeof(int));

    // 2. 检查：万一大仓库没地了怎么办？
    // 只要用了 malloc，必须立刻检查 p 是不是 NULL！
    if(p == NULL){
        printf("memory allocation failed\n");
        return 1;
    }
    // 3. 使用：现在 p 指向了一块属于我们的内存，可以随便写
    *p = 100;
    printf("Value: %d\n",*p);

    // 4. 释放：用完了，必须还给系统！
    free(p);
    p = NULL;

    
    return 0;

}