#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void)
{
	char s[53] = {0,};
	int i, sum = 0, n = 0;

	//문자열로 입력
	scanf("%s", s);

	//자릿수 반환 -> strlen(n); 사용
    
    //합구하기, 3의배수 확인을 위해서
    for(i = 0; i<strlen(s); i++){
        sum += s[i] - '0';// 그냥 더하면 아스키코드 합을 더하기 때문에 -'0'또는 -48해줘야 함
    }
    //2,4,5배수 확인을 위해서 %100한 값 구하기
    if(strlen(s)>=2) //입력받은 값이 세자리수 이상인지 확인, 한자릿수나 두자릿수면 
        n = (s[strlen(s)-2] - '0')*10;//10의자리수 구하기
    n = n + s[strlen(s)-1] - '0';//위에서 구한 10의자리수에 1의자리수 더하기

    //?는 참이면 앞에 출력 거짓이면 뒤에출력
	printf("%d", n%2==0? 1:0);
	printf("%d", sum%3==0? 1:0);
	printf("%d", n%4==0? 1:0);
	printf("%d", n%5==0? 1:0);
    
	printf("\n");

	return 0;
}
