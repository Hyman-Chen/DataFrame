#include <stdio.h>

int MaxSubseSum4(int A[], int N){
    int ThisSum, MaxSum;
    int i;
    for (i=0;i<N;i++){
        ThisSum += A[i];
        if (ThisSum > MaxSum)
            MaxSum =ThisSum;
        else if(ThisSum < 0)
            ThisSum = 0;
    }
    return MaxSum;
}
int main(){
    printf("%d\n",3);
    return 0;
}
