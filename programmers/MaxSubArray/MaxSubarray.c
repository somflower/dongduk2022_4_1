#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
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

    if (left < right)
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
    int max = A[left]; //모든 원소가 음수일때 0번째값이 가장 클때
    int middle = (left + right) / 2;

        v1 = left_max_sum(A, left, middle);
        v2 = right_max_sum(A, middle + 1, right);
        v3 = v1 + v2;

        if (v1 > v2 && v1 > v3 && v1 > max)
            max = v1;
        else if (v1 < v2 && v2 > v3 && v2 > max)
            max = v2;
        else if (v3 > max)
            max = v3;

        return max;    

} // 숙제
int main()
{
    // int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // tc #1: max는 6
    //  int A[] = {2, -1, 5, -2, 2, -3, 1}; // tc #2: max는 6
    //  int A[] = {3, -1, 1, 2, 3, 1, -1, 5}; // tc #3: max는 13
    //  int A[] = {1, 2, 3}; // tc #4: max는 6
    //  int A[] = {-1, -2, -3, -4}; //tc #5: max는 -1
    int A[] = {5}; // tc #6: max는 5

    int lastIndex = sizeof(A) / sizeof(int) - 1;

    int max = max_subarray(A, 0, lastIndex);

    printf("max value = %d\n", max);

    return 0;
}