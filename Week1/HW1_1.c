/*�����濵�а� 4�г� 20190466 �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	int n, i, mul = 1;

	printf("Enter a number: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		mul *= 2;
	}
	printf("%d\n", mul);

}