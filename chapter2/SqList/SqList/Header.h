//
//  Header.h
//  SqList
//
//  Created by Hyman on 2024/2/22.
//
#include <stdlib.h>
#ifndef Header_h
#define Header_h

// 定义链表结点
typedef struct Node{
    int data;
    struct Node* next;
}LNode;
typedef LNode *LinkList;

// 单链表的初始化（带头结点）
void InitList(LinkList *L){
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    return;
}
// 单链表的初始化（不带头结点）
void InitListII(LinkList *L){
    *L =NULL;
    return;
}
#endif /* Header_h */
