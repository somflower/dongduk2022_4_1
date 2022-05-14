#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Stdlib.h>
int find_sequence(int *arr, int n)
{
    int i;
    //321 a[0]=3, a[1]=2, a[2]=1 -> 0
    //312 a[0]=3, a[1]=1, a[2]=2 -> 2
    for (i = n - 1; i > 0; i--)
    {
        if (arr[i - 1] > arr[i])
            continue;
        else
            break;
    }
    return i;
}
void selectionSortNew(int *arr, int s, int n) //오름차순 부분정렬 함수
{
    int i, j, k = 0, max, max_idx;

    // i는 시작점부터 끝까지 범위 뜻함(0부터가 아님)
    for (i = s; i < n; i++)
    {
        //큰 수 찾아서 뒤로 보내는 오름차순 정렬을 사용할것이므로 max를 사용
        max = arr[s], max_idx = s;

        // max가 arr[s] 이므로 j=s부터 시작하면 동일한 값을 비교해서 j=s+1로 설정
        for (j = s + 1; j < n - k; j++)
        {
            if (arr[j] > max)
            {
                max = arr[j];
                max_idx = j;
            }
        }
        // printf("%d %d %d\n", max, max_idx, k);
        // max_idx가 맨 뒤가 아닐때, 맨 뒤면 그냥 그대로 냅둠
        if (max_idx != n - k - 1)
        {
            arr[max_idx] = arr[n - k - 1];
            arr[n - k - 1] = max;
        }

        //정렬을 완료했으므로 가장 마지막 배열 제외
        k++;
    }
}
int nextArr(int *arr, int n)
{
    int i, pivot, s_idx;

    s_idx = find_sequence(arr, n);

    pivot = arr[s_idx - 1];

    //pivot보다 크면서 가장 작은 수 찾기
    //가장 오른쪽값이 가장 작은값이므로 가장 오른쪽부터 찾음(내림차순이라서..)
    for (i = n - 1; i > s_idx; i--)
    {
        if (arr[i] > pivot)
            break;
    }

    // swap
    //printf("pivot: %d s_idx: %d i: %d\n", pivot, s_idx, i);

    if ((s_idx - 1) != -1)//최대시퀀스==0==가장 큰 순열(?)
    //321 a[0]=3, a[1]=2, a[2]=1
    {
        arr[s_idx - 1] = arr[i];
        arr[i] = pivot;

        /*for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
        printf("\n");*/

        selectionSortNew(arr, s_idx, n);
        return 1;
    }
    else
        return -1;
}
int main(void)
{
    int n;
    int *arr;
    int i;

    scanf("%d", &n);

    arr = (int *)malloc(sizeof(int) * n);

    if (!arr)
    {
        printf("메모리를 할당할 수 없습니다.");
        return 0;
    }

    //정답 입력
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (nextArr(arr, n) == 1)
    {

        for (i = 0; i < n; i++)
            printf("%d ", arr[i]);
    }
    else
        printf("-1\n");

    free(arr);
}