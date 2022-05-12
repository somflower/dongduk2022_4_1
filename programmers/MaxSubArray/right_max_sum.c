#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int right_max_sum(int *A, int left, int right)
{
    int sum = 0, max= A[left], i;

    for(i=left;i<=right;i++){
        sum += A[i];
        if(sum>=max)
            max = sum;
    }
    return max;
/*
    // trivial case
    if (left == right){
        max = A[left];
        return A[left];
    }
    // recursive case
    else if (left < right)
    {
        sum = right_max_sum(A, left, right - 1) + A[right];
        if (sum>=max) 
            max = sum;
    }
    return max;*/
}
int main() {
    int A[] = {-4, -3, -2, -1};
//int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
//int max = right_max_sum(A, 3, 5);// A[3], A[3]+A[4], A[3]+A[4]+A[5] 중에서 최대값 즉, 5
//int max = right_max_sum(A, 3, 4);// A[3], A[3]+A[4] 중에서 최대값 즉, 4
int max = right_max_sum(A, 0, 3);// 최대값 -1

printf("max value = %d\n", max);
}
