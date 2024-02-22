#include <stdio.h>
#include "Header.h"
#define ElementType int
#define Maxsize 10
#define ERROR -1

typedef struct SNode *Stack;
struct SNode{
    ElementType Data[Maxsize];
    int top;
};
// 入栈
void Push(Stack PtrS, ElementType item){
    if (PtrS->top == Maxsize-1){
        printf("栈满！");
        return;
    }
    else{
        PtrS->Data[++PtrS->top] = item;//加不加括号无所谓，++放在PtrS->top的前面表示先进行加法运算后进行[]的运算
        return;
    }
}
// 出栈
ElementType Pop(Stack PtrS){
    if (PtrS->top == -1) {
        printf("栈空！");
        return ERROR; // ERROR 代表ElementType的特殊值
    }else{
        return (PtrS->Data[PtrS->top--]);// 返回删除的数据后将top-1
    }
}

int main(int argc, const char * argv[]) {
    // push
    struct SNode A;
    Stack PA = &A;
    A.Data[0] = 1;
    A.Data[1] = 2;
    A.Data[2] = 3;
    A.top = 2;
    // 打印前5个数
    printf("%d\t%d\t%d\t%d\t%d\n",A.Data[0],A.Data[1],A.Data[2],A.Data[3],A.Data[4]);
    Push(PA, 4);
    Push(PA, 5);
    // 打印前5个数
    printf("%d\t%d\t%d\t%d\t%d\n",A.Data[0],A.Data[1],A.Data[2],A.Data[3],A.Data[4]);
    // 打印最后一个数
    printf("最后一个数是：%d\n",A.Data[A.top]);
    // 打印top值
    printf("A.top = %d\n",A.top);
    Pop(PA);
    // 打印前5个数
    printf("%d\t%d\t%d\t%d\t%d\n",A.Data[0],A.Data[1],A.Data[2],A.Data[3],A.Data[4]);
    // 打印最后一个数
    printf("最后一个数是：%d\n",A.Data[A.top]);
    // 打印top值
    printf("A.top = %d\n",A.top);
    return 0;
    
    
}
