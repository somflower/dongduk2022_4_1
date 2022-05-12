#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(char items[][10], int n, int picked[], int m, int toPick) {
	int i, lastIndex, smallest;

	if (toPick == 0) {
		int picked_index;
		for (i = 0; i < m; i++) {
			picked_index = picked[i];

			printf("%10s ", items[picked_index]);

		}
		printf("\n");
		return;
	}

	lastIndex = m - toPick - 1;

	if (m == toPick)
		smallest = 0;
	else
		smallest = picked[lastIndex] + 1;

	for (i = smallest; i < n; i++) {
		picked[lastIndex + 1] = i;
		pick(items, n, picked, m, toPick - 1);
	}
}

int main(void) {
	char items[][10] = { "공유", "김수현", "송중기", "지성", "현빈" };
	int n;
	int* picked;

	printf("인기상 몇명?: ");
	scanf("%d", &n);

	picked = (int*)malloc(sizeof(int) * n);

	pick(items, sizeof(items)/sizeof(items[0]), picked, n, n);

	free(picked);

	return 0;
}
