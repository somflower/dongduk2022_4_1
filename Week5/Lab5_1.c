#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void pick(char *items, int n, int *picked, int m, int toPick){
	int smallest, LastIndex, i;

	//trivial case
	if(toPick == 0){
		int picked_idx;
		for(i=0;i<m;i++){
			picked_idx = picked[i];
			
			printf("%c ", items[picked_idx]);
		}
		printf("\n");
		return;
	}
	//LastIndex 설정
	LastIndex = m - toPick - 1;

	//smallest 설정
	if(toPick == m)
		smallest = 0;
	else
		smallest = picked[LastIndex] + 1;
	
	//recursive case
	for(i=smallest;i<n;i++){
		picked[LastIndex + 1] = i;
		pick(items, n, picked, m, toPick - 1);
	}
}
int main(void){
	char items[] = "ABCDEFG"; 
	int picked[3];

	pick(items,7,picked,3,3);

	return 0;
}