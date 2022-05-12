#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int *items, int n, int *picked, int m, int toPick)
{
    int i, LastIndex, smallest;

    // trivial case
    if (toPick == 0){
        int itemIdx;
        int sum = 0;

        for (i = 0; i < m; i++){
            itemIdx = picked[i];
            sum += items[itemIdx];
        }

        if (sum == 1000 * m){
            for (i = 0; i < m; i++){
                itemIdx = picked[i];
                if(items[itemIdx]!=0)
                    printf("%5d ", items[itemIdx]);
            }
            printf("\n");
        }

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
    int items[] = {0, 1000, 5000, 10000};
    //int items[] = {1000, 5000, 10000};
    int n;
    int *picked;

    printf("입력: ");
    scanf("%d", &n);

    picked = (int *)malloc(sizeof(int) * n / 1000); // n/items[0]도 가능, 1000이 보통 0번째라서,,

    if (!picked)
    {
        printf("메모리를 할당할 수 없습니다.\n");
        return 0;
    }

    pick(items, sizeof(items) / sizeof(items[0]), picked, n / 1000, n / 1000);

    free(picked);
}