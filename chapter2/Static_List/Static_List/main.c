//
//  main.c
//  Static_List
//
//  Created by Hyman on 2024/2/23.
//

#include <stdio.h>
#define MaxSize 10

// 静态链表结点定义
struct SNode{
    int data;
    int next;
};

int main(int argc, const char * argv[]) {
    struct SNode L[MaxSize];
    L[0].data = 2;
    L[0].next = 1;
    L[1].data = 3;
    L[1].next = 2;
    L[2].data = 4;
    L[2].next = 3;
    L[3].data = 5;
    L[3].next = -1;
    // 删除3号结点
    L[2].next = 4;
    L[3].next = -1;
    printf("%d\n",L[3].data);
    printf("%d\n",L[3].next);
    
    return 0;
}
