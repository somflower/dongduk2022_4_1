#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int List[5] = { 0, 1, 2, 4, 6 };
int sorted_seq_search(int key, int low, int high) {
	int i;

	for (i = low; i <= high; i++) {
		if (List[i] > key)
			return -1;
		else if (List[i] == key)
			return i;
	}
}
int main(void) {
	int key, anw;

	printf("key�� �Է�>>");
	scanf("%d", &key);

	anw = sorted_seq_search(key, 0, 6);

	if (anw == -1)
		printf("key�� ����\n");
	else
		printf("%d��°�� ����\n", anw + 1);

	return 0;
}