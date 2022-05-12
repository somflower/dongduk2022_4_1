#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void selection_sort(int *arr, int n)
{
    int i, j, max, max_idx, min, min_idx;

    //가장 큰 수 찾아서 위치 교환, 오름차순
    for (i = 0; i < n - 1; i++)
    {
        max = arr[0], max_idx = 0;
        for (j = 1; j < n - i; j++)
        {
            if (arr[j] > max)
            {
                max = arr[j];
                max_idx = j;
            }
        }
        if (max != arr[n - i - 1]){
            arr[max_idx] = arr[n - i - 1];
            arr[n - i - 1] = max;
            }
    }

    //가장 작은 수 찾아서 위치 교환, 내림차순
     for (i = 0; i < n - 1; i++)
    {
        min = arr[0], min_idx = 0;
        for (j = 1; j < n - i; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                min_idx = j;
            }
        }
        if (min != arr[n - i - 1]){
            arr[max_idx] = arr[n - i - 1];
            arr[n - i - 1] = max;
            }
    }
}
int main(void){
    int arr[10]={7,8,9,10,1,2,3,4,5,6};
    int i;

    for(i=0;i<10;i++)
        printf("%d ", arr[i]);
    printf("\n");

    selection_sort(arr, 10);
    
    for(i=0;i<10;i++)
        printf("%d ", arr[i]);
    printf("\n");
}