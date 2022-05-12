#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int get_cycle_number(int n) {

	do {
		if (n % 2 == 0) {
			n = n / 2;
			printf("%d ", n);
		}
		else if (n % 2 == 1) {
			n = n * 3 + 1;
			printf("%d ", n);
		}
	} while (n != 1); // true¸é ¹Ýº¹
}
int main(void) {
	int num;

	scanf("%d", &num);

	get_cycle_number(num);

	return 0;
}
