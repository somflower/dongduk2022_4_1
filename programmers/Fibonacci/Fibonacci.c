#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int fib(int n){
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else
        return fib(n-2) + fib(n-1);
}
int main(void){
    int n;

    printf("���° �Ǻ���ġ �Լ�?>>");
    scanf("%d", &n);

    printf("%d\n",fib(n));
    return 0;
}