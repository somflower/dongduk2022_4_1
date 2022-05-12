#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{  
    int n1, n2, k, digit, i;
    int *arr;

    scanf("%d %d", &n1, &k);

    //k진법으로 표현할때 몇자리인지 확인하기 위해 k진법 자릿수 구하기
    n2 = n1;
    for (i = 0; n2 > 0; i++)
    {
        //입력받은 값을 0이 될때까지 k로 계속 나눠줌
        n2 /= k;
    }
    digit = i;

    //k진법 자릿수에 맞춰 동적배열할당
    arr = (int *)malloc(sizeof(int) * digit);

    //k진법 거꾸로 배열에 입력
    for (i = digit - 1; i >= 0; i--)
    {
        arr[i] = n1 % k;
        n1 /= k;
    }

    //k진법 출력
    for (i = 0; i < digit; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    free(arr);

    return 0;
}