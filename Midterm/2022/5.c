#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//등차수열: 모든 항의 차이가 같다.
int isSequence(int* a, int size)
{
	int i, value, flag = 1;
	value = a[1]-a[0];

	for(i=0;i<size-1;i++){
		if(a[i+1]-a[i]!=value)
			flag = 0;
	}
	return flag;
}
int main(void)
{
	int n;
	int* a;

	scanf("%d", &n);
	a = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	printf("%d\n", isSequence(a, n));

	free(a);
	return 0;
}