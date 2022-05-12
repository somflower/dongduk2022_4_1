#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
    int n;

    srand(time(NULL));

    n = (rand() % 100);
}