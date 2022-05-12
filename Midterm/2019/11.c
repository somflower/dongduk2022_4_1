#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//횟수를 센 것
int pick(int* items, int n, int* picked, int m, int toPick, int target){
    int i, LastIndex, ret = 0; // smallest는 없어도 됨

    //trivial case
    if(toPick == 0){
        int itemIdx;
        int sum = 0;
        for(i=0;i<m;i++){
            itemIdx = picked[i];
            printf("%c%d", items[itemIdx] == 1? '+':'-', i+1);
            sum = sum + items[itemIdx]*(i+1);
        }
        printf(" = %d\n", sum);
        
        if(sum == target)
            return 1;
        else
            return 0;
    }

    //LastIndex
    LastIndex = m - toPick - 1;

    //smallest
    //smallest = 0;
   
    //recursive case
    for(i=0;i<n;i++){
        picked[LastIndex + 1] = i;
        ret = ret + pick(items, n, picked, m, toPick - 1, target); 
    }
    return ret;
}
int main(void){
    int items[2] = {1, -1};
    int n1, n2;
    int *picked;
    int cnt;

    printf("입력: ");
    scanf("%d %d", &n1, &n2);

    picked = (int *)malloc(sizeof(int) * n1);

    if (!picked)
    {
        printf("메모리를 할당할 수 없습니다.\n");
        return 0;
    }

    cnt = pick(items, sizeof(items) / sizeof(items[0]), picked, n1, n1, n2);

    printf("%d\n", cnt);

    free(picked);

    return 0;
}