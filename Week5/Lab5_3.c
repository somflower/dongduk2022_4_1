#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void pick(char *items, int n, int *picked, int m, int toPick){
	int i, lastIndex;

	if( toPick == 0 ){
		int picked_index;
		for( i=0; i<n; i++ ){
			picked_index = picked[i];

			printf("%s ", items[picked_index]);

		}
		printf("\n");
		return;
	}

	lastIndex = m - toPick - 1;

	

	for( i=0; i<m; i++ ){
        int j;
        int flag = 0;

        for( j=0; j<=lastIndex; j++)
            if (picked[j] == i)
                flag = 1;
        if ( flag == 1) continue;
        
		picked[lastIndex + 1] = i;
		pick(items, n, picked, m, toPick -1 );
	}
}

int main(void) {
	char *items[] = { "AAA", "BBB", "CCC", "DDD", "EEE" };
	int picked[3];

	pick( items, 7, picked, 3, 3);

	return 0;
}
