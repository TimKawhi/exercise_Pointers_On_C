/*
**把一个值插入到一个双链表，rootp是一个指向根节点的指针，
**value是欲插入的新值。
**返回值：如果欲插入的值已存在于链表中，函数返回0；
**如果内存不足导致无法插入，函数返回-1；如果插入成功，函数返回1。
*/
#include<stdlib.h>
#include<stdio.h>
#include"dll_node.h"

int
dll_insert( Node *rootp, int value )
{
    Node *this;
    Node *next;
    Node *newnode;

    /*
    **查看value是否在已经在链表中，如果是就返回
    **否则为其创造一个新的节点--newone
    **"this"将指向新节点之前的那个节点
    **"next"将指向新节点之后的那个节点
    *
    */
    for( this = rootp; (next = this->fwd) != NULL; this = next ){
        if( next->value == value )
            return 0;
        if( next->value > value )
            break;
    }

    newnode = (Node *)malloc( sizeof( Node ) );
    if( newnode == NULL )
        return -1;
    newnode->value = value;

    /*
    **把新值添加到链表中
    */
    if( next != NULL ) {
    /*
    **情况1 或情况2：并非位于链表尾部
    */
        newnode->fwd = next;
        if( this != rootp ){ /* 情况1：并非位于链表的起始位置*/
            this->fwd = newnode;
            newnode->bwd = this;
        }
        else {               /* 情况2：位于链表的起始位置*/
            rootp->fwd = newnode;
            newnode->bwd = NULL;
        }
        next->bwd = newnode;
    }
    else {
    /*
    **情况3或情况4：位于链表的尾部
    */
        newnode->fwd = NULL;
        if( this != rootp ) {   /* 情况3：不位于链表的起始位置*/
            this->fwd = newnode;
            newnode->bwd = this; 
        }
        else {                  /* 情况4：位于链表的起始位置*/
            rootp->fwd = newnode;
            newnode->bwd = NULL;
        }
        rootp->bwd = newnode;    
    }

    return 1;
}
