//
//  Header.h
//  SetType
//
//  Created by Hyman on 2024/2/26.
//

#ifndef Header_h
#define Header_h
#define MaxSize 10

typedef int ElementType;
typedef struct{
    ElementType Data;
    int Parent;
}SetType;
// 查找某个元素所在的集合，用根结点表示
int Find(SetType S[],ElementType X){
    int i;
    for (i=0;i<MaxSize && S[i].Data != X;i++);
    if (i>=MaxSize) return -1;
    for (;S[i].Parent >=0;i=S[i].Parent);
    return i;
}
#endif /* Header_h */
