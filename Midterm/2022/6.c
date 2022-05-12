#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//전역변수 사용
int *arr2;
int cnt = 0;
int isSequence(int *a, int size)//등차수열 check
{
	int i, value, flag = 1;
	value = a[1] - a[0];

	for (i = 0; i < size - 1; i++)
	{
		if (a[i + 1] - a[i] != value)
			flag = 0;
	}
	return flag;
}
void pick(int *items, int n, int *picked, int m, int toPick, int * arr)
{
	int i, j, LastIndex, smallest;

	// trivial case
	if (toPick == 0)
	{
		int itemIdx;
		int sum = 0;
		for (i = 0; i < m; i++)
		{
			itemIdx = picked[i];
			//printf("%d ",items[itemIdx]);
			arr2[i] = arr[i]+items[itemIdx];
		
			//printf("%d ", arr2[i]);

			//printf("%d ",arr[j]+items[itemIdx]);
			//printf("\n");
		}
		if(isSequence(arr2, m)==1){
				/*for(j=0;j<m;j++)
					printf("%d ", arr2[j]);
				printf("\n");*/
				cnt++;
				}
		//printf("\n");
		return;
	}

	// LastIndex
	LastIndex = m - toPick - 1;

	// smallest
	smallest = 0;

	// recursive case
	for (i = smallest; i < n; i++)
	{
		picked[LastIndex + 1] = i;
		pick(items, n, picked, m, toPick - 1, arr);
	}
}
int main(void)
{
	//<로직 설명>
	//1. item에서 중복순열로 뽑고 2. arr에서 순열로 뽑음
	//그다음 1과 2를 더해서 arr2에 입력함
	//arr2가 등차수열인지 계산
	//주석처리된 printf문은 디버깅시 확인하기 위한 코드임
	int items[3] = {1, 0, -1};
	int *arr;
	int n;
	int *picked;
	int i;

	scanf("%d", &n);

	picked = (int *)malloc(sizeof(int) * n);
	arr = (int *)malloc(sizeof(int) * n);
	arr2 = (int *)malloc(sizeof(int) * n);

	if (!picked)
	{
		printf(".\n");
		return 0;
	}
	if (!arr)
	{
		printf(".\n");
		return 0;
	}
	if (!arr2)
	{
		printf(".\n");
		return 0;
	}

	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	pick(items, sizeof(items) / sizeof(items[0]), picked, n, n, arr);

	printf("%d\n", cnt);
	free(picked);
	free(arr);
	free(arr2);

	return 0;
}
