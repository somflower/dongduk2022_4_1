#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void selection_sort(int *arr, int n)
{
    int i, j, max, max_idx;

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

    selection_sort(array, n);

    printf("정렬된 후:\n");
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");

    free(array);
}