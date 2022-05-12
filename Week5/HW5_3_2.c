#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int *items, int n, int *picked, int m, int toPick, int money)
{
    int i, LastIndex, smallest, sum, itemIdx;

    //0이 없을때, 'toPick == 0'은 중요하지 않음, 다 뽑지 않아도 return 할 수 있기 때문에

    // LastIndex, 앞에 선언, 처음부터 lastindex까지의 합을 먼저 구함
    LastIndex = m - toPick - 1;
    sum = 0;
    for (i = 0; i <= LastIndex; i++){
            itemIdx = picked[i];
            sum += items[itemIdx];
        }
    
    //sum이 money와 같다면 LastIndex까지 출력 후 리턴
    if (sum == money){
            for (i = 0; i <= LastIndex; i++){
                itemIdx = picked[i];
                printf("%5d ", items[itemIdx]);
            }
            printf("\n");
            return;
        }

    //sum이 money보다 크다면 그냥 리턴
    if(sum > money){
        return;
    }

    //다 뽑았다면, 위의 조건을 만족하지 못했다면
    //->sum이 money와 작다(다르다), 여기서는 1000을 m개 뽑는 case임
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

    printf("입력: ");
    scanf("%d", &n);

    picked = (int *)malloc(sizeof(int) * n/items[0]); // n/items[0]도 가능, 1000이 보통 0번째라서,,

    if (!picked)
    {
        printf("메모리를 할당할 수 없습니다.\n");
        return 0;
    }

    pick(items, sizeof(items) / sizeof(items[0]), picked, n/items[0], n/items[0], n);

    free(picked);
}