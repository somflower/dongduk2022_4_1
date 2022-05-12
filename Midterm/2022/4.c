#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void selectionSortNew(int *arr, int n, int s)
{
    int i, j, k = 0, max, max_idx;

    //i는 시작점부터 끝까지 범위 뜻함
    for (i = s; i < n; i++)
    {
        //큰 수 찾아서 뒤로 보내는 오름차순 정렬을 사용할것이므로 max를 사용
        max = arr[s], max_idx = s;

        //max가 arr[s] 이므로 j=s부터 시작하면 동일한 값을 비교해서 j=s+1로 설정
        for (j = s+1; j < n - k; j++) 
        {
            if (arr[j] > max)
            {
                max = arr[j];
                max_idx = j;
            }
        }
		//printf("%d %d %d\n", max, max_idx, k);
		//max_idx가 맨 뒤가 아닐때, 맨 뒤면 그냥 그대로 냅둠
        if (max_idx != n - k - 1) 
		{
            arr[max_idx] = arr[n - k - 1];
            arr[n - k - 1] = max;
        }
	
        //정렬을 완료했으므로 가장 마지막 배열 제외
		k++;
    }
}
int main(void)
{
    int n, i, s;
    int *array;

    scanf("%d", &n);

    array = (int *)malloc(sizeof(int) * n);

    if (!array)
    {
        printf("메모리를 할당할 수 없습니다.");
        return 0;
    }

    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);

	scanf("%d", &s);

    selectionSortNew(array, n, s);

    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");

    free(array);
}
