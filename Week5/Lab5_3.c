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

	smallest = 0;

	for (i = smallest; i < n; i++) {
		int j;
		for (j = 0; j <= lastIndex; j++) {
			if (picked[j] == i)
				break;
			else
				continue;
		}
		if(j==lastIndex+1){
			picked[lastIndex + 1] = i;
			pick(items, n, picked, m, toPick - 1);
		}
	}
}

int main(void) {
	char items[][10] = { "공유", "김수현", "송중기", "지성", "현빈" };
	int n;
	int* picked;

	printf("상의 종류는?: ");
	scanf("%d", &n);

	if (n == 2)
		printf("      상1        상2\n");
	else if (n == 3)
		printf("      상1        상2        상3\n");
	else if (n == 4)
		printf("      상1        상2        상3        상4\n");
	else if (n == 5)
		printf("      상1        상2        상3        상4        상5\n");

	picked = (int*)malloc(sizeof(int) * n);

	pick(items, sizeof(items) / sizeof(items[0]), picked, n, n);

	free(picked);

	return 0;
}
