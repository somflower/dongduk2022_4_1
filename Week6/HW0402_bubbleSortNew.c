#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int check_sort(int *arr, int n)
{
    int flag = 1, i;

    for (i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
void printArr(int n, int *arr)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("  %4d", arr[i]);
    }
    printf("\n");
}
void bubble_sort(int n, int *arr)
{
    int i, j, tmp;

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
        printf("i = %d :", i - 1);
        printArr(n, arr);
        if (check_sort(arr, n) == 1)
            break;
    }
}
int main(void)
{
    int n, i = 0;
    int *arr;

    srand(time(NULL));

    printf("Enter a number : ");
    scanf("%d", &n);

    arr = (int *)malloc(sizeof(int) * n);
    if (!arr)
    {
        printf("�޸𸮸� �Ҵ��� �� �����ϴ�.");
        return 0;
    }

    for (i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }

    printf("�ʱ�  :");
    printArr(n, arr);

    bubble_sort(n, arr);

    printf("����  :");
    printArr(n, arr);

    free(arr);

    return 0;
}