#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int changeInt(char *n, int digit)
{	
	//입력받은 n을 int형으로 바꿔주기
	int i, N = 0;

	for (i = 0; i < digit; i++)
	{
		N = N * 10 + (n[i] - 48);
	}

	return N;
}
void changeK(char *arr, int N, int k, int Kdigit)
{
	int i;

	// k가 1~9인 경우
	if (k > 1 && k < 10)
	{
		//배열에 거꾸로 넣기
		for (i = Kdigit - 1; i >= 0; i--)
		{
			// printf("arr[%d]: %c, N: %d\n", i, (N % k)+48, N);
			arr[i] = (N % k) + 48;
			N /= k;
		}
	}

	else if (k == 16)
	{
		//배열에 거꾸로 넣을때 나머지가 0~9인지 확인
		for (i = Kdigit - 1; i >= 0; i--)
		{
			//나머지가 0~9이면 위와 같이 넣고
			if ((N % k) > 0 && (N % k) < 9)
			{
				arr[i] = (N % k) + 48;
				//printf("1나머지: %d \n",(N % k) + 48);
				N /= k;
			}
			else
			{
				arr[i] = (N % k) + 55;
				//printf("2나머지: %d \n",(N % k) + 55);
				N /= k;
			}
		}
	}

	//문자열 배열이니 마지막에 null값 넣어주기
	arr[i] = '\0';
}
void calculateReverse(char *N1, char *N2, int Kdigit)
{
	int i;

	for (i = 0; i < Kdigit; i++)
	{
		N2[i] = N1[Kdigit - 1 - i];
	}
	N2[i] == '\0';
}
int checkPalindrome(char *N1, int Kdigit)
{
	//배열을 뒤집은 후 뒤집기 전과 palindrome 확인
	int i, flag = 1;
	char N2[Kdigit];

	calculateReverse(N1, N2, Kdigit);

	for (i = 0; i < Kdigit / 2; i++)
	{
		if (N1[i] != N2[i]){
			flag = 0;
			break;
		}
	}
	return flag;
}
int main(void)
{
	//n의 최대값이 10^12승이므로 문자열 배열로 입력받음
	//또한 16진수로 변환할때 알파벳을 넣어야 하므로 문자열 배열 이용
	char n[14]; // 10^12승까지 들어가므로.. 마지막 null값까지 +1 해서 14
	int k, i, n2, digit, N, N2, Kdigit;
	char *arr;

	// n(숫자), k(진법)
	scanf("%s %d", n, &k);

	//자릿수 구하기
	for (i = 0; n[i] != '\0'; i++)
		;
	// printf("%d", i);
	digit = i;

	// n을 int형으로 변경
	N = changeInt(n, digit);

	// k진법으로 만들때 몇자리인지 확인
	//확인 후 동적배열할당
	N2 = N;
	for (i = 0; N2 > 0; i++)
		N2 /= k;
	Kdigit = i;

	// printf("Kdight: %d N: %d, digit: %d\n", Kdigit, N, digit);
	arr = (char *)malloc(sizeof(char) * (Kdigit + 1));

	// k진법으로 바꾸기...
	changeK(arr, N, k, Kdigit);

	// test, arr 출력
	/*for (i = 0; i < Kdigit; i++)
		printf("%c ", arr[i]);
	printf("\n");*/

	//palindrome check
	printf("%d\n", checkPalindrome(arr, Kdigit));

	free(arr);

	return 0;
}