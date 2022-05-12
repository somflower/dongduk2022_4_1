#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
    int n, i;
    int *array;

    srand(time(NULL));

    printf("Enter a number: ");
    scanf("%d", &n);

    array = (int*)malloc(sizeof(int) * n);

    if(!array){
        printf("메모리를 할당할 수 없습니다.");
        return 0;
    }

    for (i = 0; i < n; i++)
        array[i] = (rand() % 1000);

    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");

    free(array);
}