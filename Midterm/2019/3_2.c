#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int checkDigit(int n3)
{ //자릿수 구하기
	int i;

	for (i = 0; n3 != 0; i++)
	{
		n3 = n3 / 10;
	}
	return i;
}
int main(void)
{
	int i, j = 1, n, n3, n10, digit, idx = 0, arr[99999];

	scanf("%d", &n);

	do
	{
		n10 = 1;
		n3 = 3 * j;
		digit = checkDigit(n3);

		// 10 자릿수만큼 n승
		for (i = 1; i < digit; i++)
			n10 = n10 * 10;

		//printf("n3: %d, digit: %d, n10: %d\n", n3, digit, n10);

		for (i = 0; n10 != 0; i++)
		{
			if (checkDigit(n3) == checkDigit(n10)) //n3=30, 2 ,2 
			{
				arr[idx] = n3 / n10;
				idx++;
				n3 = n3 % n10; // n3 = 0
				n10 = n10 / 10; // n10 = 1
				//printf("1. n3: %d, n10: %d\n", n3, n10);
			}
			else{
				arr[idx] = 0;
				idx++;
				n10 = n10 / 10;
			}

			//printf("2. arr[%d]: %d\n", idx-1, arr[idx-1]);
			if (idx == n)
				break;
		}
		j++;
		
	}while(idx<n);

	printf("%d\n", arr[idx - 1]);

	return 0;
}
