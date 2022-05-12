#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 16
int array[SIZE] = { 2, 6, 11, 13, 18, 20, 22, 27, 29, 30, 34, 38, 41, 42, 45, 47 };
int search_binary(int key, int low, int high) {
	int middle;

	if (low <= high) {
		middle = (low + high) / 2;

		if (low == high)
			if (key != array[middle])
				return -1;

		if (key == array[middle])
			return middle;
		else if (key < array[middle]) 
			search_binary(key, low, middle - 1);
		else 
			search_binary(key, middle + 1, high);
	}
}
int main(void) {
	int key, i, anw;

	for (i = 0; i < SIZE; i++) {
		printf("%3d", array[i]);
		if (i % 8 == 7)
			printf("\n");
	}

	printf("Key 입력: ");
	scanf("%d", &key);

	anw = search_binary(key, 0, SIZE - 1);
	
	if (anw == -1)
		printf("Key 없음\n");
	else
		printf("%d번째에 있음\n", anw + 1);

	return 0;
}
