#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int k_bonacci(int k, int n)
{
    int i, sum = 0;

    if (n == 0)//0번째값은 0
        return 0;
    else if (n <= k)//k보나치의 1~k번째 값은 모두 1
    {
        return 1;
        /*for (i = 0; i <= k; i++)
        {
            if (n == i)
                return 1;
        }*/
    }
    else //if (n > k)
    {
        for (i = 1; i <= k; i++)
            sum += k_bonacci(k, n - i);
        return sum;
    }
}
int main(void)
{
    int n, k;

    printf("입력)");
    scanf("%d %d", &k, &n);

    printf("출력)");
    printf("%d\n", k_bonacci(k, n));
    return 0;
}