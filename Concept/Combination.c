#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void pick(char* items, int n, int* picked, int m, int toPick){
    int i, LastIndex, smallest;

    //trivial case, ���� �� �̾��� ��
    if(toPick == 0){
        int itemIdx;
        for(i=0;i<m;i++){
            itemIdx = picked[i];

            printf("%5c ", items[itemIdx]);
        }
        printf("\n");
        return;//return �� ���� ���ѷ���..
    }

    //LastIndex����
    LastIndex = m - toPick - 1;

    //smallest����
    if(m == toPick)//�ϳ��� �� �̾��� ��
        smallest = 0;
    else //�� �� �̻� �̾��� ��
        smallest = picked[LastIndex] + 1;
    
    //recursive case
    for(i=smallest;i<n;i++){
        picked[LastIndex + 1] = i;
        pick(items, n, picked, m, toPick - 1); //���ٿ��� 1���� �̾����Ƿ� toPick -1
    }


}
int main(void){
    char items[] = "ABCDEFG";
    int picked[3];

    pick(items, 7, picked, 3, 3);
}