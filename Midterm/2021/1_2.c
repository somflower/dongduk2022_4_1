#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int checkCarry(char n1, char n2, int carry) {
	printf("%d %d\n", n1 - 48, n2 - 48);
	if ((int)(n1 - 48) + (int)(n2 - 48) + carry >= 10)
		return 1;
	else
		return 0;
}
void reverse(char src_s[], char s[]) {
	int i, idx;

	idx = strlen(src_s);


	//거꾸로 넣기
	for (i = 0; src_s[i] != '\0'; i++) {
		s[idx - i - 1] = src_s[i];
	}

	//마지막에 \0넣기
	s[idx] = '\0';
}
int main(void) {
	char n1[101], n11[101];
	char n2[101], n22[101];
	int i, carry = 0, cnt = 0, d1, d2;

	scanf("%s %s", n1, n2);

	reverse(n1, n11);
	reverse(n2, n22);

	d1 = strlen(n11);
	d2 = strlen(n22);

	printf("d1: %d d2: %d\n", d1, d2);
	//자릿수 크기 비교
	//비교 후 자릿수 작은 값 뒤에 0이랑 \0넣어주기
	if (d1 > d2) {
		for (i = d1 - (d1 - d2); i < d1; i++)
			n22[i] = '0';
		n22[d1] = '\0';
	}
	else if (d1 < d2) {
		for (i = d2 - (d2 - d1); i < d2; i++)
			n11[i] = '0';
		n11[d2] = '\0';
	}
	printf("n11: %s, n22: %s\n", n11, n22);
	
	//reverse값을 더해서 carry구하기
	for (i = 0; i < strlen(n11); i++) {
		if (checkCarry(n11[i], n22[i], carry) == 1) {
			carry = 1;
			cnt++;
		}
		else
			carry = 0;
	}

	printf("%d\n", cnt);
	return 0;
}