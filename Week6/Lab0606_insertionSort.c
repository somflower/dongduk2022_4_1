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
int main(void)
{
    int n, i;
    int *array;

    srand(time(NULL));

    printf("Enter a number: ");
    scanf("%d", &n);

    array = (int *)malloc(sizeof(int) * n);

    if (!array)
    {
        printf("메모리를 할당할 수 없습니다.");
        return 0;
    }

    for (i = 0; i < n; i++)
        array[i] = (rand() % 1000);

    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");

    insertion_sort(array, n);

    printf("정렬된 후:\n");
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");

    free(array);
}