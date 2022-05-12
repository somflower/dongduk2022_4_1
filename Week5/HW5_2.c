#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int Calc(char opr, int n){
    int sum = 0;

    if(opr == '+')
        sum += n;
    else
        sum -= n;

    return sum;
}
void pick(char* items, int n, int* picked, int m, int toPick){
    int i, LastIndex, smallest;

    //trivial case
    if(toPick == 0){
        int itemIdx;
        int sum = 0;
        for(i=0;i<m;i++){
            itemIdx = picked[i];

            printf("%5c ", items[itemIdx]);
            printf("%d ", i+1);
            sum += Calc(items[itemIdx], i+1);
        }
        printf(" = %5d\n", sum);
        
        return;
    }

    //LastIndex
    LastIndex = m - toPick - 1;

    //smallest
    smallest = 0;
    
    //recursive case
    for(i=smallest;i<n;i++){
        picked[LastIndex + 1] = i;
        pick(items, n, picked, m, toPick - 1); 
    }


}
int main(void){
    char items[2] = {'+', '-'};
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