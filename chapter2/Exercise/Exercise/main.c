//
//  main.c
//  Exercise
//
//  Created by Hyman on 2024/2/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct List{
    int data[10];
    int Length;
};
typedef struct List SqList;

// 1、删除顺序表中的最小值，并将顺序表最后一位替换该最小值，删除最后一位数。
int ReturnMin(SqList *L){
    if (L->Length == 0) {printf("顺序表为空。");return 404;}
    int Min = L->data[0];
    int pos = 0;
    for (int i=0;i<L->Length;i++){
        if (L->data[i]<Min){
            Min = L->data[i];
            pos = i;
        }
    }
    L->data[pos] = L->data[L->Length-1];
    L->Length--;
    return Min;
    
}

// 2、逆置顺序表所有元素,时间复杂度为O(1)。
void Reverse(SqList *L){
    int tmp;
    if (L->Length == 0) {printf("空");return;}
    for (int i=0;i<=L->Length/2;i++){
        tmp = L->data[i];
        L->data[i] = L->data[L->Length-i-1];
        L->data[L->Length-i-1] = tmp;
    }
    return;
}
// 3、删除长度为n的顺序表中值为X的元素，时间复杂度为O(n)，空间复杂度为O(1)。
void DeleteX(SqList *L,int X){
    int k=0;
    for (int i =0;i<L->Length;i++){
        if (L->data[i]!=X){
            L->data[k]=L->data[i];
            k++;
        }else{
            L->Length--;
        }
    }
}
// 13、给定一个含n个整数的数组，找出数组中未出现的最小正整数，如{-5,3,2,3}，要求输出1。
int FindInteger(int A[], int n){
    int *B,i;
    B = (int*)malloc(sizeof(int)*n);
    memset(B,0,sizeof(int)*n);
    
    for (i = 0;i<n;i++){
        if (A[i]>0 && A[i]<=n)
            B[A[i]-1]=A[i];
    }
    for (i=0;i<n;i++) if (B[i]==0) break;
    return i+1;
}

int main(int argc, const char * argv[]) {
    // 1、删除顺序表中的最小值，并将顺序表最后一位替换该最小值，删除最后一位数。
//    SqList L;// Ld代表一个线性表
//    L.data[0] = 2;
//    L.data[1] = 4;
//    L.data[2] = 8;
//    L.data[3] = 1;
//    L.data[4] = 9;
//    L.Length = 5;
//    printf("%d\n",ReturnMin(&L));
    // 2、逆置顺序表所有元素,时间复杂度为O(1)。
//    SqList L;// Ld代表一个线性表
//    L.data[0] = 2;
//    L.data[1] = 4;
//    L.data[2] = 8;
//    L.data[3] = 1;
//    L.data[4] = 9;
//    L.Length = 5;
//    for(int i=0;i<L.Length;i++) printf("%d",L.data[i]);
//    Reverse(&L);
//    printf("\n");
//    for(int j=0;j<L.Length;j++) printf("%d",L.data[j]);
//    printf("\n");
    // 3、删除长度为n的顺序表中值为X的元素，时间复杂度为O(n)，空间复杂度为O(1)。
    // 13、给定一个含n个整数的数组，找出数组中未出现的最小正整数，如{-5,3,2,3}，要求输出1。
    int A[4] = {1,2,3,4};
    printf("%d\n",FindInteger(A, 4));
    return 0;
}
