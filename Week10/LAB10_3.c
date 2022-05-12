#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Stdlib.h>
#include <time.h>
int partition(int* A, int p, int r)
{
    int i, j, t;

    j = p;
    i = p-1;

    //j를 계속 증가시켜 Pivot(A[r])과 비교
    for( ; j<r;j++){
        if(A[j]<A[r]){
            i++;
            //A[j]<->A[i]
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }

    //Pivot과 비교 끝남, Pivot을 i++한 자리에 넣음
    i++;
    t = A[i];
    A[i] = A[r];
    A[r] = t;

    return i;//partition위치 반환
}
void quickSort(int* A, int p, int r)
{
    int q;

    if(p < r){
        q = partition(A, p, r);
        
        //partition위치 기준으로 앞에 다시 정렬, 뒤에도 정렬
        //partition은 정렬되어있으므로 q-1, q+1하는 것
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}
void printList(int* A, int s, int e)
{
    int i;
    for (i = s; i < e; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int selection(int *A, int p, int r, int n){
    int q;//pivot idx
    int ranking;
    
    if( p < r ){
        q = partition(A, p, r);//pivot idx 구함, pivot은 q-p-1번째로 작은 숫자임
        ranking = q - p + 1;

        if( n == ranking )
            return A[q];
        else if ( n > ranking )
            return selection(A, q+1, r, n - ranking);
        else if ( n < ranking)
            return selection(A, p, q-1, n);

    }
}
int main(void)
{
    srand(time(NULL));
    int n, i, small;
    int *arr;

    scanf("%d", &n);
    scanf("%d", &small);

    arr = (int *)malloc(sizeof(int) * n);

    if (!arr)
    {
        printf("메모리를 할당할 수 없습니다.");
        return 0;
    }

    // arr에 값 입력
    for (i = 0; i < n; i++)
        arr[i] = (rand() % 1000);

    printList(arr, 0, n);

    printf("%d ", selection(arr, 0, small, n));
    
   // printList(arr, 0, n);

    free(arr);
    return 0;
}