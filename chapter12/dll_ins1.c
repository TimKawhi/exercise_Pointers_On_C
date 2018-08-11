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
        if( this != rootp ){ /* 情况1：并非位于链表的起始位置*/
            newnode->fwd = next;
            this->fwd = newnode;
            next->bwd = newnode;
            newnode->bwd = this;
        }
        else {               /* 情况2：位于链表的起始位置*/
            newnode->fwd = next;
            rootp->fwd = newnode;
            next->bwd = newnode;
            newnode->bwd = NULL;
        }
    }
    else {
    /*
    **情况3或情况4：位于链表的尾部
    */
        if( this != rootp ) {   /* 情况3：不位于链表的起始位置*/
            newnode->fwd = NULL;
            this->fwd = newnode;
            newnode->bwd = this;
            rootp->bwd = newnode; 
        }
        else {                  /* 情况4：位于链表的起始位置*/
            rootp->fwd = newnode;
            newnode->fwd = NULL;
            rootp->bwd = newnode;
            newnode->bwd = NULL;
        }    
    }

    return 1;
}
