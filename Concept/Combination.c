#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void pick(char* items, int n, int* picked, int m, int toPick){
    int i, LastIndex, smallest;

    //trivial case, 전부 다 뽑았을 때
    if(toPick == 0){
        int itemIdx;
        for(i=0;i<m;i++){
            itemIdx = picked[i];

            printf("%5c ", items[itemIdx]);
        }
        printf("\n");
        return;//return 안 들어가면 무한루프..
    }

    //LastIndex설정
    LastIndex = m - toPick - 1;

    //smallest설정
    if(m == toPick)//하나도 안 뽑았을 때
        smallest = 0;
    else //한 개 이상 뽑았을 때
        smallest = picked[LastIndex] + 1;
    
    //recursive case
    for(i=smallest;i<n;i++){
        picked[LastIndex + 1] = i;
        pick(items, n, picked, m, toPick - 1); //윗줄에서 1개를 뽑았으므로 toPick -1
    }


}
int main(void){
    char items[] = "ABCDEFG";
    int picked[3];

    pick(items, 7, picked, 3, 3);
}