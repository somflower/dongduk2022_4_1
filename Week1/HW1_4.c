/*�����濵�а� 4�г� 20190466 �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	int scores[5], key, i;

	printf("Enter 5���� ����: ");

	for (i = 0; i < 5; i++) {
		scanf("%d", &scores[i]);
	}

	printf("Enter a key: ");
	scanf("%d", &key);

	for (i = 0; i < 5; i++) {
		if (scores[i] == key)
			break;
	}

	if (i == 5)
		printf("����\n");
	else
		printf("%d��°�� �ִ�\n", i+1);
}