#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void readMatrix(int a[][3], int n)
{
    // n은 행의 개수 의미
    //입력하는 함수
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}
void matrixAdd(int a[][3], int b[][3], int x[][3], int n)
{
    // a,b,x 모두 동일한 크기여야 배열 합 가능
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 3; j++)
        {
            x[i][j] = a[i][j] + b[i][j];
        }
    }
}
void printMatrix(int a[][3], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
}
int main(void)
{
    int A[3][3], B[3][3], X[3][3];
    
    readMatrix(A, 3);
    readMatrix(B, 3);
    matrixAdd(A, B, X, 3);
    printMatrix(X, 3);


    return 0;
}
