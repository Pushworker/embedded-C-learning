#include<stdio.h>

void SwapFunction(int *arg1 ,int *arg2){
    int p ;
    printf("Original arg1 = %d , arg2 = %d\n",*arg1,*arg2);
    p = *arg1;
    *arg1 = *arg2 ;
    *arg2 = p;
    printf("After swap arg1 = %d , arg2 = %d\n",*arg1,*arg2);
}
int main(){
    int a = 10;
    int b = 20;
    SwapFunction(&a ,&b);
    return 0;

}