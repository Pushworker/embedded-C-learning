#include <stdio.h>
#include <string.h>

// 1. 定义一个极其简单的结构体
typedef struct {
    int id;
    char name[20];
    float value;
} Sensor;

// 2. 写一个函数，用指针来修改结构体的值
// 注意：参数是 Sensor* 指针
void update_sensor(Sensor *s, float new_val) {
    // 提示：s->value = new_val;
    // TODO: 补全这行代码
    s->value = new_val ;
    //&temp（结构体地址）和 &temp.id（第一个成员的地址）在内存里一模一样
    //依次偏移：id 占 4 个字节，所以 value 的地址就是结构体起始地址 + 4
    //你说得太对了，增加成员后，value 的地址偏移量确实变了。
    //但只要你还用 s->value，编译器就会根据最新的结构体定义，自动算出正确的偏移量，完全不需要你硬编码数字。
}

int main() {
    // 3. 在栈上创建一个结构体变量（不需要malloc）
    Sensor temp;
    temp.id = 101;
    temp.value = 25.0f;
    strcpy(temp.name,"Temperature");
    printf("Before: ID=%d, Value=%.1f\n", temp.id, temp.value);

    // 4. 调用函数，把变量的地址传进去（这就是指针的作用）
    update_sensor(&temp, 26.5f);

    printf("After:  ID=%d, Name=%s, Value=%.1f\n", temp.id,temp.name, temp.value);

    return 0;
}