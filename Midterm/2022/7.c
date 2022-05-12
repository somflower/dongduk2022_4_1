#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int isSequence(int *a, int size)
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
void pick(int *items, int n, int *picked, int m, int toPick, int *arr1, int *arr2, int *cnt1, int *cnt2, int *max)
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
			//printf("%d ",picked[i]);
			arr2[i] = arr1[i] + items[itemIdx];
			
			// printf("%d ", arr2[i]);

			// printf("%d ",arr1[i]+items[itemIdx]);
			// printf("\n");
		}
		if (isSequence(arr2, m) == 1)
		{
			/*for (j = 0; j < m; j++){
				printf("%d ", arr2[j]);
				}*/
			//printf("\n");

			//여기서 0의 개수 세기
			for(i=0; i<m; i++){
				if(picked[i]==1)
					*cnt2 = *cnt2 + 1;
			}
			
			if(*cnt2 >= *max)
				*max = *cnt2;
			*cnt2 = 0;

			*cnt1 = *cnt1 + 1;
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
		pick(items, n, picked, m, toPick - 1, arr1, arr2, cnt1, cnt2, max);
	}
}
int main(void)
{
	//6번 코드 수정, 전역변수를 다 지우고 포인터를 이용해 매개변수로 사용
	//등차수열판별하는 것은 앞과 동일하고 item을 픽할때 0의 개수를 세어 가장 많은 0의값을 max로 줌
	//출력은 가장 적은 연산회수기 때문에 n(배열 수)-max(가장 많은 0의값)을 출력함
	int items[3] = {1, 0, -1};
	int *arr1, *arr2;
	int n;
	int *picked;
	int i, cnt1 = 0, cnt2 = 0, max = 0;

	scanf("%d", &n);

	picked = (int *)malloc(sizeof(int) * n);
	arr1 = (int *)malloc(sizeof(int) * n);
	arr2 = (int *)malloc(sizeof(int) * n);

	if (!picked)
	{
		printf(".\n");
		return 0;
	}
	if (!arr1)
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
		scanf("%d", &arr1[i]);

	pick(items, sizeof(items) / sizeof(items[0]), picked, n, n, arr1, arr2, &cnt1, &cnt2, &max);

	//등차수열이 없을 경우
	if (cnt1 == 0)
		printf("-1\n");
	//등차수열이 1개 이상인 경우 n - 0의 개수 출력
	else 
		printf("%d\n", n - max);

	free(picked);
	free(arr1);
	free(arr2);

	return 0;
}
