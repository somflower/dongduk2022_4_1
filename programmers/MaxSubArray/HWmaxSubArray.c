#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Stdlib.h>
int left_max_sum(int *A, int left, int right)
{
    int sum = 0, max = A[right], i;

    //if (left < right)
    {
        for (i = right; i >= left; i--)
        {
            sum += A[i];
            if (sum >= max)
                max = sum;
        }
        return max;
    }
}
int right_max_sum(int *A, int left, int right)
{
    int sum = 0, max = A[left], i;

    //if (left < right)
    {
        for (i = left; i <= right; i++)
        {
            sum += A[i];
            if (sum >= max)
                max = sum;
        }
        return max;
}
}
int max_subarray(int *A, int left, int right)
{
    int i, v1, v2, v3;
    //int max;
    int middle = (left + right) / 2;

    if (left < right)
    {
        v1 = max_subarray(A, left, middle);
        v2 = max_subarray(A, middle + 1, right);
        v3 = left_max_sum(A, left, middle) + right_max_sum(A, middle + 1, right);

        if (v1 > v2 && v1 > v3)
            return v1;
        else if (v1 < v2 && v2 > v3)
            return v2;
        else 
            return v3;
    }
    else if(left == middle)
        return A[left];
       
}
int main()
{
    int array_size, max, i;
    int *A;

    scanf("%d", &array_size);

    A = (int *)malloc(sizeof(int) * array_size);

    for (i = 0; i < array_size; i++)
        scanf("%d", &A[i]);

    max = max_subarray(A, 0, array_size - 1);

    printf("%d\n", max);

    free(A);
    return 0;
}