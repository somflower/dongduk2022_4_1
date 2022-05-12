#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int four_bonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 1;
    else if (n == 3)
        return 1;
    else if (n == 4)
        return 1;
    else
        return four_bonacci(n - 1) + four_bonacci(n - 2) 
        + four_bonacci(n - 3) + four_bonacci(n - 4);
}
int main(void)
{
    int n;

    printf("몇번째 4-보나치 함수?>>");
    scanf("%d", &n);

    printf("%d\n", four_bonacci(n));
    return 0;
}