//
//  Header.h
//  training_of_queue
//
//  Created by Hyman on 2024/2/22.
//
#include <stdlib.h>
#ifndef Header_h
#define Header_h
#define ElementType int
#define MaxSize 10
#define ERROR -1
// 定义列队结点和堆(顺序存储实现)
struct QNode{
    ElementType Data[MaxSize];
    int rear;
    int front;// 均指下标
};
typedef struct QNode *Queue;

// 入队列（只放n-1个元素）
void Push(Queue PtrQ, ElementType item){
    if ((PtrQ->rear+1) % MaxSize == PtrQ->front) {printf("队列满！");return;}
    else {
        PtrQ->rear = (PtrQ->rear+1) % MaxSize;
        PtrQ->Data[PtrQ->rear] = item;
        return;
    }
}

// 出队列
ElementType Pop(Queue PtrQ){
    ElementType Topval;
    if (PtrQ->rear == PtrQ->front){
        printf("栈空!");
        return ERROR;
    }
    else {
        PtrQ->front = (PtrQ->front+1) % MaxSize;
        return (PtrQ->Data[PtrQ->front]);
    };
}

// 队列的链式存储实现
struct Node{
    ElementType Data;
    struct Node *Next;
};
struct QNodeL{
    struct Node *front;
    struct Node *rear;
};
typedef struct QNodeL *QueueL;
QueueL PtrQ;

// 出队列(不带头结点)
ElementType DeleteQ(QueueL PtrQ){
    struct QNodeL *FrontCell;
    ElementType FrontElem;
    if (PtrQ->front == NULL){printf("队列空！");return ERROR;}
    FrontCell = PtrQ->front;
    if (PtrQ->rear == PtrQ->front) PtrQ->rear=PtrQ->front = NULL;
    else PtrQ->front = FrontCell->Next;
    FrontElem = FrontCell->Data;
    free(FrontCell);
    return FrontElem;
}

#endif /* Header_h */
