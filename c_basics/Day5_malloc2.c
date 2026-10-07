#include <stdio.h>
#include <stdlib.h>

//malloc的基本语法：指针变量 = (指针类型 *)malloc(要分配的字节数);
int main(){

int *arr = (int *)malloc(5 * sizeof(int)); // 申请 5 个 int 的空间
    if (arr == NULL) {
    printf("Memory allocation failed!\n");
    return 1; // 直接退出程序
}
// 赋值：arr[0] = 10; arr[1] = 20; ...
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    arr[4] = 4;
// 打印
    for(int i=0 ; i<5 ;i++){
    printf("Array[%d] = %d\n",i,arr[i]);
 }
 

// 最后 free(arr);
    free(arr);
    arr = NULL;
    return 0 ;

}