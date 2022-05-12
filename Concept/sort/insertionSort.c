#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void insertion_sort(int *arr, int n)
{
    int i, j, k, tmp;

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (arr[j] > arr[i])
                break;
        }
        tmp = arr[i];

        for(k=i;k>j;k--){
            arr[k] = arr[k-1];
        }
        arr[k] = tmp;
    }
}