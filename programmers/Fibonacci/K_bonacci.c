#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int k_bonacci(int k, int n)
{
    int i, sum = 0;

    if (n == 0)//0��°���� 0
        return 0;
    else if (n <= k)//k����ġ�� 1~k��° ���� ��� 1
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

    printf("�Է�)");
    scanf("%d %d", &k, &n);

    printf("���)");
    printf("%d\n", k_bonacci(k, n));
    return 0;
}