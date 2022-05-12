#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int flag = 0;
int Calc(char opr, int n)
{
	int sum = 0;

	if (opr == '+')
		sum += n;
	else
		sum -= n;

	return sum;
}
int CheckN(int sum, int N)
{
	if (sum == N)
		return 1;
	else
		return 0;
}
void pick(char *items, int n, int *picked, int m, int toPick, int N)
{
	int i, LastIndex, smallest;

	// trivial case
	if (toPick == 0)
	{
		int itemIdx;
		int sum = 0;
		for (i = 0; i < m; i++)
		{
			itemIdx = picked[i]; // 0과 1을 뽑음

			// printf("%5c ", items[itemIdx]);//+랑-출력
			// printf("%d ", i+1);//0123...출력
			sum += Calc(items[itemIdx], i + 1); // sum계산함수
		}
		//printf(" = %5d\n", sum);

		flag += CheckN(sum, N);

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
		pick(items, n, picked, m, toPick - 1, N);
	}
}
int main(void)
{
	char items[2] = {'+', '-'};
	int n, N;
	int *picked;

	//printf("Enter: ");
	scanf("%d %d", &n, &N);

	picked = (int *)malloc(sizeof(int) * n);

	if (!picked)
	{
		printf("None\n");
		return 0;
	}

	pick(items, sizeof(items) / sizeof(items[0]), picked, n, n, N);

	if (flag > 0)
		printf("1\n");
	else
		printf("0\n");

	free(picked);

	return 0;
}