#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int cnt = 0;
void pick(int *items, int n, int *picked, int m, int toPick)
{
    int i, LastIndex, smallest, itemIdx, sum;

    // LastIndex
    LastIndex = m - toPick - 1;

    // trivial case
    if (toPick == 0){//�� �̾Ҵٴ� ���� 10���� �� ä���ٴ� ���� �ǹ���
        sum = 0;
        for (i = 0; i < m; i++){
            itemIdx = picked[i];
            sum += items[itemIdx];
            //printf("%d ",items[itemIdx]);
        }
        //printf("\n");
        if (sum == 10 * m)
        {
            cnt++;
            return;
        }
        else
            return;
    }
    else if(toPick < m){//�� �Ȼ̾Ҵµ� ���� m*10�� �ǰų� ������ return, �������� ���x
        sum = 0;
        for (i = 0; i <= LastIndex; i++){
            itemIdx = picked[i];
            sum += items[itemIdx];
        }
        if (sum == 10 * m)
        {
            cnt++;
            return;
        }
        else if(sum > 10 * m)
            return;
    }

    // smallest
    if (m == toPick)
        smallest = 0;
    else
        smallest = picked[LastIndex];

    // recursive case
    for (i = smallest; i < n; i++){
        picked[LastIndex + 1] = i;
        pick(items, n, picked, m, toPick - 1);
    }
}
int main(void)
{
    int items[] = {10, 50, 100, 500};
    int n;
    int *picked;

    // printf("�Է�: ");
    scanf("%d", &n);

    picked = (int *)malloc(sizeof(int) * n / 10);

    if (!picked)
    {
        printf("�޸𸮸� �Ҵ��� �� �����ϴ�.\n");
        return 0;
    }
    if (n % 10 != 0)
        printf("0\n");
    else if (n <= 0)
        printf("0\n");
    else
    {
        pick(items, sizeof(items) / sizeof(items[0]), picked, n / 10, n / 10);
        printf("%d\n", cnt);
    }

    free(picked);
    return 0;
}