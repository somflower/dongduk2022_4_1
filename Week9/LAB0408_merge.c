#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Stdlib.h>
#include <time.h>
void merge(int* A, int p, int q, int r)
{
    int i, j, k;//loop 돌기 위해 3개 필드
    int *t;//sort후 저장할 동적배열 생성

    i = p;
    j = q+1;
    k = 0;

    t = (int*) malloc(sizeof(int)*(r-p+1));//끝idx - 시작idx + 1

    while(i<=q && j<=r){
        if(A[i]<A[j]){
            t[k] = A[i];
            i++;
        }
        else{
            t[k] = A[j];
            j++;
        }
        k++;
    }

    //i>q 또는 j>r인 경우 값 그대로 복사
    if(i>q){
        for( ; j<=r; j++, k++)
            t[k] = A[j];
    }
    else{
        for( ; i<=q; i++, k++)
            t[k] = A[i];
    }

    for(i=p, k=0; i<=r; i++, k++)
        A[i] = t[k];

    free(t);
}
void mergeSort(int* A, int p ,int r){
    int q;

    //반으로 쪼갠 후 오른쪽, 왼쪽 정렬
    if(p < r){
        q = (p+r)/2;
        mergeSort(A, p, q);
        mergeSort(A, q+1, r);
        merge(A, p, q, r);
    }
}
void printList(int A[], int s, int e)
{
    int i;
    for (i = s; i < e; i++)
        printf("%4d ", A[i]);
    printf("\n");
}
int main(void)
{
    srand(time(NULL));
    int n, i;
    int *arr;

    scanf("%d", &n);

    arr = (int *)malloc(sizeof(int) * n);

    if (!arr)
    {
        printf("메모리를 할당할 수 없습니다.");
        return 0;
    }

    for (i = 0; i < n; i++)
        arr[i] = (rand() % 1000);

    //초기값 출력
    printList(arr, 0, n);

    //정렬
    mergeSort(arr, 0, n - 1);

    //정렬후 출력
    printList(arr, 0, n);

    free(arr);
    return 0;
}