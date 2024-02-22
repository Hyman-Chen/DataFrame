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
// 定义堆栈结点和堆(顺序存储实现)
typedef struct SNode *Stack;
struct SNode{
    ElementType Data[MaxSize];
    int Top;
};

// 一个数组放两个栈
struct DStack{
    ElementType Data[MaxSize];
    int top1;
    int top2;
};

// 放两个栈的数组Push操作
void DPush(struct DStack *PtrS, ElementType item, int tag){
    if (PtrS->top2-PtrS->top1 == 1){
        printf("栈满！");return;
    }
    if (tag == 1){
        PtrS->Data[++PtrS->top1] = item;
        return;
    }
    else {
        PtrS->Data[++PtrS->top2] = item;
        return;
    }
        

}

// 制造空栈
Stack CreatStack(){
    /*构建一个堆栈的头结点，返回指针*/
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    if (S) return (*PtrS);
    else return NULL;
}

// 入栈
void Push(Stack PtrS, ElementType item){
    if (PtrS -> Top == MaxSize - 1) {printf("栈满！");return;}
    else {
        PtrS -> Data[++PtrS->Top] = item;
        return;
    }
}



// 出栈
ElementType Pop(Stack PtrS){
    if (PtrS->Top == -1){
        printf("栈空!");
        return ERROR;
    }
    else return (PtrS->Data[PtrS->Top--]);
}

// // 定义堆栈结点和堆(链式存储实现)
typedef struct SNodeL *StackL;
struct SNodeL{
    ElementType Data;
    struct SNodeL *Next;
};

// 链式堆栈初始化
void CreatStackL(){
    Stack S;
    S = (Stack)malloc(sizeof(struct SNodeL));
    S->Next = NULL;
    return S;
}

// 判断堆栈S是否为空
int IsEmpty(StackL S) return (S->Next == NULL);

// 压栈
void PushL(StackL S, ElementType item){
    /* 含头结点 */
    struct SNodeL *TmpCell;
    TmpCell = (Stack)malloc(sizeof(struct SNodeL));
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
    TmpCell->Data = item;
}

// 出栈
ElementType PopL(StackL S){
    if (!S->Next){printf("栈空！");return ERROR;}
    StackL TmpCell;
    SNodeL Topval;
    TmpCell = S->Next;
    S->Next = TmpCell->Next;
    Topval = TmpCell->data;
    free(TmpCell);
    return Topval;
    
}

#endif /* Header_h */
