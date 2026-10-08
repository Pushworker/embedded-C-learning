#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

// 结构体定义
typedef  struct{
    int data ;
    struct Node* next;
}Node ;

void print_list(Node *head);
void free_list(Node *head);

#endif