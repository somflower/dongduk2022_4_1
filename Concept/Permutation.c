#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void pick(char *items, int n, int *picked, int m, int toPick)
{
    int i, LastIndex, smallest;
    int j; //중복되지 않은 순열이기 때문에 중복확인을 위해 j가 필요

    // trivial case, 전부 다 뽑았을 때
    if (toPick == 0)
    {
        int itemIdx;
        for (i = 0; i < m; i++)
        {
            itemIdx = picked[i];

            printf("%5c ", items[itemIdx]);
        }
        printf("\n");
        return; // return 안 들어가면 무한루프..
    }

    // LastIndex설정
    LastIndex = m - toPick - 1;

    // smallest설정
    // smallest는 중요하지 않음, 뽑은 수 중에 item이 있는지 없는지 확인이 중요함
    //전체 item과 picked[]를 비교하기 위해서 item 시작을 0으로 줌(항상 0으로 시작)
    smallest = 0;

    // recursive case
   /* for (i = smallest; i < n; i++)
    {
        for (j = 0; j <= LastIndex; j++)
        {
            if (picked[j] == i)
                break;
            else
                continue;
        }
        if (j == LastIndex + 1)
        {
            picked[LastIndex + 1] = i;
            pick(items, n, picked, m, toPick - 1); //윗줄에서 1개를 뽑았으므로 toPick -1
        }
    }*/

    //flag 사용 시 recursive case
    
        int flag;
        for (i = smallest; i < n; i++)
    {
        flag = 1;
        for (j = 0; j <= LastIndex; j++)
        {
            if (picked[j] == i)
                flag = 0;
            else
                continue;
        }
        if (flag == 1)
        {
            picked[LastIndex + 1] = i;
            pick(items, n, picked, m, toPick - 1); //윗줄에서 1개를 뽑았으므로 toPick -1
        }
    }
    
}
int main(void)
{
    char items[] = "ABCDEFG";
    int picked[3];

    pick(items, 7, picked, 3, 3);
}