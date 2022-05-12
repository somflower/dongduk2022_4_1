#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char n[53];
	int i;

	//문자열로 입력
	scanf("%s", n);

	//자릿수 반환
	for (i = 0; n[i] != '\0'; i++);

	if ((n[i - 1] -48)% 2 == 0)
		printf("1\n");
	else
		printf("0\n");
	//printf("%d",n[i - 1]-48); //아스키코드 반환

	return 0;
}
