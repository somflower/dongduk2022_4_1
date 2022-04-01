/*국제경영학과 4학년 20190466 김미현*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	char str[100], ch;
	int i, cnt = 0;

	printf("Enter a String: ");
	scanf("%s", str, sizeof(str));
	

	printf("Enter a character: ");
	scanf(" %c", &ch);

	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == ch)
			cnt++;
	}

	printf("'%c' is appeared %d times\n", ch, cnt);
}