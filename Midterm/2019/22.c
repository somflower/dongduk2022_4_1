#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int solution(int n)
{ //자릿수 구하기
	int ret = 0;

    while(n != 0)
	{
		n = n / 10;
        ret++;
	}
	return ret;
}
int main(void)
{
    //3배수의 자릿수를 계속 계산해서 합함, 그 합이 n과 같은지 확인
    //합하지는 않고 n에서 3의배수 자릿수를 계속 뺄셈, 어느순간 0보다 작거나 같으면 찾은 것
	int i, n, m, number;

	scanf("%d", &n);

    for(i=3; ; i = i+3){//3의배수 무한.. n에서 자릿수 뺐을때 값구하기
        m = solution(i);
        if(n - m <= 0)//n에서 자릿수 뺀 값이 0이하다 -> 자릿수 찾음
            break;
        else   
            n = n - m; //0보다 크다 -> 더 빼야함
    }

    number = i;//몇승일때 자릿수에 존재하는지 찾았으면 정답의 곱한 값을 저장

    for(i=0;i<m-n;i++) //n은 n-m이 0보다작은값이 되기 전의 값
        number = number/10;

    printf("%d\n", number %10);

	return 0;
}
