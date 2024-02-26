//
//  Header.h
//  Heap
//
//  Created by Hyman on 2024/2/25.
//

#include <stdlib.h>
#ifndef Header_h
#define Header_h
//#define MaxSize 10
#define ElementType int
#define MaxData 1



typedef struct HeapStruct *MaxHeap;
struct HeapStruct{
    ElementType *Elements;
    int Size;
    int capacity;
};

// 最大堆的创建
MaxHeap Create(int MaxSize){
    MaxHeap H = malloc(sizeof(sizeof(struct HeapStruct)));
    H->Elements = malloc((MaxSize+1)*sizeof(ElementType));
    H -> capacity = MaxSize;
    H -> Size = 0;
    H -> Elements[0] = MaxData;
    return H;
}
// 最大堆的插入
void Insert(MaxHeap H,ElementType item){
    int i;
    // 这里省略判断最大堆有没有满的操作；
    i = ++H->Size;
    for (;H->Elements[i/2]<item;i/=2 ) H->Elements[i]=H->Elements[i/2];
    H->Elements[i] = item;
}

#endif /* Header_h */
