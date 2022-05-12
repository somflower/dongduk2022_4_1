#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int *items, int n, int *picked, int m, int toPick)
{
    int i, LastIndex, smallest;

    // trivial case
    if (toPick == 0)
    {
        int itemIdx;
        for (i = 0; i < m; i++)
        {
            itemIdx = picked[i];
            printf("%5d ", items[itemIdx]);
        }
        printf("\n");
        return;
    }

    // LastIndex
    LastIndex = m - toPick - 1;

    // smallest
    if (m == toPick)
        smallest = 0;
    else
        smallest = picked[LastIndex];

    // recursive case
    for (i = smallest; i < n; i++)
    {
        picked[LastIndex + 1] = i;
        pick(items, n, picked, m, toPick - 1);
    }
}
int main(void)
{
    int items[4] = {0, 1, 2, 3};
    int n;
    int *picked;

    printf("입력: ");
    scanf("%d", &n);

    picked = (int *)malloc(sizeof(int) * n);

    if (!picked)
    {
        printf("메모리를 할당할 수 없습니다.\n");
        return 0;
    }

    pick(items, sizeof(items) / sizeof(items[0]), picked, n, n);

    free(picked);

    return 0;
}