#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int findC(int c)
{
    int cnt = 0;

    while (c != 0)
    {
        //printf("%d %d\n", c, cnt);
        if (c % 10 == 1)
        {
            c = c / 10;
            cnt++;
           //printf("%d %d\n", c, cnt);
        }
        else
            return 0;
    }

    if (c == 0)
        return cnt;
}
int main(void)
{
    int A, B, C = -1, i;

    scanf("%d", &A);

    

    if (A % 2 == 0 || A == 5)
        printf("No\n");
    else
    {   
        B = 0;
        do{
            B++;
            C = A*B;
            //printf("%d %d %d\n", A, B, C);
            //printf("%d\n", findC(C));
        }while(findC(C)==0);
        printf("%d\n", findC(C));
    }

    return 0;
}
