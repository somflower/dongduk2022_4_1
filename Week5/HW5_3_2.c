#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int *items, int n, int *picked, int m, int toPick, int money)
{
    int i, LastIndex, smallest, sum, itemIdx;

    //0�� ������, 'toPick == 0'�� �߿����� ����, �� ���� �ʾƵ� return �� �� �ֱ� ������

    // LastIndex, �տ� ����, ó������ lastindex������ ���� ���� ����
    LastIndex = m - toPick - 1;
    sum = 0;
    for (i = 0; i <= LastIndex; i++){
            itemIdx = picked[i];
            sum += items[itemIdx];
        }
    
    //sum�� money�� ���ٸ� LastIndex���� ��� �� ����
    if (sum == money){
            for (i = 0; i <= LastIndex; i++){
                itemIdx = picked[i];
                printf("%5d ", items[itemIdx]);
            }
            printf("\n");
            return;
        }

    //sum�� money���� ũ�ٸ� �׳� ����
    if(sum > money){
        return;
    }

    //�� �̾Ҵٸ�, ���� ������ �������� ���ߴٸ�
    //->sum�� money�� �۴�(�ٸ���), ���⼭�� 1000�� m�� �̴� case��
    if(toPick == 0){
        return;
    } 

    // smallest
    if (m == toPick)
        smallest = 0;
    else
        smallest = picked[LastIndex];

    // recursive case
    for (i = smallest; i < n; i++)
    {
        picked[LastIndex + 1] = i;
        pick(items, n, picked, m, toPick - 1, money);
    }
}
int main(void)
{
    //int items[] = {0, 1000, 5000, 10000};
    int items[] = {1000, 5000, 10000};
    int n;
    int *picked;

    printf("�Է�: ");
    scanf("%d", &n);

    picked = (int *)malloc(sizeof(int) * n/items[0]); // n/items[0]�� ����, 1000�� ���� 0��°��,,

    if (!picked)
    {
        printf("�޸𸮸� �Ҵ��� �� �����ϴ�.\n");
        return 0;
    }

    pick(items, sizeof(items) / sizeof(items[0]), picked, n/items[0], n/items[0], n);

    free(picked);
}