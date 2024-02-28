//
//  Header.h
//  InternalSorting
//
//  Created by Hyman on 2024/2/28.
//

#ifndef Header_h
#define Header_h
#
typedef int ElementType;

void Swap(ElementType A, ElementType B){
    
}
// 冒泡排序
void Bubble_Sort(ElementType A[], int N)
{ int P, i, flag;
    for (P=N-1; P>=0;P--){
        flag = 0;
        for (i =0; i<P;i++){
            if (A[i] >A[i+1]){
                Swap(A[i], A[i+1]);
                flag =1;
            }
            if (flag ==0 ) break;
        }
    }
}
#endif /* Header_h */
