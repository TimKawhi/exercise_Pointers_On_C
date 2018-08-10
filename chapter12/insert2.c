 /*
 **插入到一个有序单向链表，函数的参数是一个指向链表根指针的指针，以及一个需要插入的值。
 **@version 2
 */
#include<stdlib.h>
#include<stdio.h>
#include"sll_node.h"

#define FALSE   0
#define TRUE    1

int
sll_insert( Node **rootp, int new_value)
{
    Node *current;
    Node *privous;
    Node *new;

    /*
    **得到指向第一个节点的指针
    */
    current = *rootp;
    privous = NULL;

    /*
    **寻找正确的插入位置，方法是按顺序访问列表，直到到达其值大于或等于
    **新插入节点的值
    */
    while( current != NULL && current->value < new_value) {
        privous = current;
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
    if( privous == NULL)
        *rootp = new;
    else
        privous->link = new;

    return TRUE;
}
