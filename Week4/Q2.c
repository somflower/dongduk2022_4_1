#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int calculateReverse(int N1){
	int N2 = 0;

	do{
		//printf("%d %d\n", N1, N2);
		N2 = N2*10 + N1%10;
		N1 = N1/10;
	}while(N1!=0);

	return N2;
}
int checkPalindrome(int N2){
	//int N3, i, cnt = 0, digit;
	//, x = 1;

	/*N3 = N2;

	for(i=0;N3!=0;i++){
		N3 = N3/10;
	}
	
	digit = i;*/
	
	/*for(i=0;i<digit/2;i++){
		x = x*10;
	}*/
	//printf("%d %d %d\n", N2, N3, x);
	//printf("%d %d\n", N2, calculateReverse(N2));
	if((N2)==(calculateReverse(N2)))
		return 1;
	else
		return 0;
}
int main(void) {
	int n1, cnt = 0;

	scanf("%d", &n1);

	do{
		//입력받은 수(=n1)이 palindrome일 때
		if(checkPalindrome(n1)==1){
			//printf("%d %d\n", n1, cnt);
			break;
		}//입력받은 수(=n1)이 0일 때
		else if(n1==0)
			break;
		else{
		n1 = n1 + calculateReverse(n1);
		cnt++;
		}
		//printf("%d %d\n", n1, cnt);
	}while(checkPalindrome(n1)==0&&cnt<1000&&n1>0);

	//printf("%d %d\n", n1, n2);
	if(cnt>1000||n1<=0)
		printf("NaN\n");
	else if (checkPalindrome(n1)==1)
		printf("%d %d\n", cnt ,n1);
	return 0;
}
