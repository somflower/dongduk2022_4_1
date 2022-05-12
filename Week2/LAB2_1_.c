#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void pick(int n, int picked[], int m, int toPick) {
	//n=전체 수, picked=뽑아서 저장하는 배열, m=뽑아야하는 전체 개수, toPick=m개중에서 앞으로 뽑아야하는 수
	int smallest; //앞으로 뽑을 수 중에 가장 작은 수(뽑은 수 중에 가장 큰 수+1)
	int index; //뽑은 수 중에 가장 큰 수가 담겨있는 index번호
	int i;
	

	//다 뽑은 경우, base case, 출력
	if (toPick == 0) {
		for (i = 0; i < m; i++)
			printf("%d  ", picked[i]);
		printf("\n");
		return;
	}

	//index설정
	index = m - toPick - 1;

	//오름차순 정렬(조합이라서 겹치지 않기 때문), 가장 작은 수 설정
	if (m == toPick)
		smallest = 0; //처음 뽑는 경우
	else
		smallest = picked[index] + 1; //처음이 아닌 뽑는 경우

	//뽑기
	for (i = smallest; i < n; i++) {
		picked[index + 1] = i;
		pick(n, picked, m, toPick - 1); //하나를 뽑았으므로 toPick-1 해야함
	}

}
int main(void) {
	int picked[4];
	
	pick(7, picked, 4, 4);

	return 0;
}
