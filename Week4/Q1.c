#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int findCarry(int n1_r, int n2_r, int carry)
{
    if ((n1_r + n2_r + carry) >= 10)
        return 1;
    else
        return 0;
}
int main(void)
{
    int n1, n2, n1_remain, n2_remain, cnt = 0, carry = 0;

    scanf("%d %d", &n1, &n2);
   
        while (n1 != 0 || n2 != 0)
        {
            //오버플로우 확인코드
            /* if (a>0&&b>0)
            {
                if(a+b<=0)
                    break;
            }
            else if(a<0&&b<0)
                if(a+b>=0)
                    break;
            */
           //printf("1 %d %d %d %d\n", n1, n2, n1_remain, n2_remain);
            if (n1 != 0||n1_remain != 0)
            {
                n1_remain = n1 % 10;
                n1 = n1 / 10;
            }
            if (n2 != 0||n2_remain != 0)
            {
                n2_remain = n2 % 10;
                n2 = n2 / 10;
            }
            //printf("2 %d %d %d %d %d %d\n", n1, n2, n1_remain, n2_remain, carry, cnt);
            if (findCarry(n1_remain, n2_remain, carry) == 1)
            {
                carry = 1;
                cnt++;
            }
            else
                carry = 0;
           //printf("3 %d %d %d %d %d %d\n", n1, n2, n1_remain, n2_remain, carry, cnt);
        }
        printf("%d\n", cnt);

    return 0;
}
