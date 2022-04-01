#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void pick(char *items, int n, int *picked, int m, int toPick){
	int i, lastIndex, smallest;

	if( toPick == 0 ){
		int picked_index;
		for( i=0; i<n; i++ ){
			picked_index = picked[i];

			printf("%c ", items[picked_index]);

		}
		printf("\n");
		return;
	}

	lastIndex = m - toPick - 1;

	if( m == toPick )
		smallest = 0;
	else
		smallest = picked[lastIndex] + 1;

	for( i=smallest; i<m; i++ ){
		picked[lastIndex + 1] = i;
		pick(items, n, picked, m, toPick -1 );
	}
}

int main(void) {
	char *items[] = { "공유", "김수현", "송중기", "지성", "현빈" };
	int picked[3];

	pick( items, 7, picked, 3, 3);

	return 0;
}
