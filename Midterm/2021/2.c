#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int checkDigit(int n) {
    int i;

    for (i = 0; n > 0; i++)
        n = n / 10;
    return i;
}
int main(void) {
    int n, n9, digit, i;
    int* narr;

    scanf("%d", &n);
    n9 = n * 9;

    digit = checkDigit(n9);
    narr = (int*)malloc(sizeof(int) * digit);

    if (!narr) {
        printf("None\n");
        return 0;
    }

    for (i = digit - 1; n9 > 0; i--) {
        narr[i] = n9 % 10;
        n9 = n9 / 10;
    }

    for (i = 0; i < digit; i++)
        printf("%d ", narr[i]);
    printf("\n");

    free(narr);

    return 0;
}