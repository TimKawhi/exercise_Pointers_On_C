/*
**插入到一个有序的单链表，函数的参数是一个指向第一个节点的指针以及需要插入的值。
**@version 1
*/
#include<stdlib.h>
#include<stdio.h>
#include"sll_node.h"

#define FALSE 0
#define TRUE  1

int
sll_insert( Node *current, int new_value){
    Node *privious;
    Node *new;

    /*
    **寻找正确的插入位置，方法是按顺序访问列表，直到到达其值大于或等于
    **新插入节点的值
    */
    while( current != NULL && current->value < new_value ) {
        privious = current;
        current = current->link;
    }

    /*
    **为新节点分配内存，把新值存储到新节点中，如果内存分配失败，
    **函数返回FALSE
    */
    new = (Node *)malloc( sizeof(Node) );
    if( new == NULL )
        return FALSE;
    new->value = new_value;

    /*
    **把新节点插入到链表中,并返回TRUE。
    */
    new->link = current;
    privious->link = new;
    return TRUE;
}
