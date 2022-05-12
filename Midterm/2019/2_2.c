#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int check2(int digit, char *n)
{
	if ((n[digit - 1]-48) % 2 == 0)
		return 1;
	else
		return 0;
}
int check3(int digit, char *n)
{
	int i, sum = 0;

	for(i=0;n[i]!='\0';i++){
		sum += n[i];
	}
	if (sum % 3 == 0)
		return 1;
	else
		return 0;
}

int check4(int digit, char *n)
{
	int i, num = 0;

	for(i=0;n[i]!='\0';i++){
		num = num*10 +n[i];
	}

	if ((num%100) % 4 == 0)
		return 1;
	else
		return 0;
}

int check5(int digit, char *n)
{
	if ((n[digit - 1]-48) == 0||(n[digit - 1]-48) == 5)
		return 1;
	else
		return 0;
}

int main(void)
{
	char n[53];
	int i;

	//문자열로 입력
	scanf("%s", n);

	//자릿수 반환
	for (i = 0; n[i] != '\0'; i++)
		;

	printf("%d", check2(i, n));
	printf("%d", check3(i, n));
	printf("%d", check4(i, n));
	printf("%d", check5(i, n));

	printf("\n");
	//printf("%d",n[i - 1]-48);

	return 0;
}
