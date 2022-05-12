#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int minusCarry(int n1, int n2, int m_carry){
	//문자열로 입력받았기 때문에 계산을 위해 int형으로 형변환
	//계산했을때 음수값이 나오면 carry 발생한것으로 인식하고 1리턴
    if ((int)(n1 - 48) - (int)(n2 - 48) - m_carry < 0)
		return 1;
	else
	//양수값이 나오면 carry가 발생하지 않은 것으로 인식하고 0리턴
		return 0;
}
void reverse(char src_s[], char s[]) {
	int i, idx;

	idx = strlen(src_s);

	//거꾸로 넣기
	for (i = 0; src_s[i] != '\0'; i++) {
		s[idx - i - 1] = src_s[i];
	}

	//마지막에 \0넣기
	s[idx] = '\0';
}
int main(void) {
    //자릿수를 구하고 strlen(n1), strlen(n2), 자릿수가 같으면 그냥 뒤집어넣고 뺄셈
    //자릿수가 큰 애(무조건n1)한테 맞춰서 작은 애 앞에 0을 넣음
    //그다음 i=0;i<큰애자릿수;i++해서 각자릿수 끼리 뺄셈 -> 음수
    char n1[11], n11[11];
	char n2[11], n22[11];
    int i, m_carry = 0, cnt = 0, d1, d2;

    //입력받고
    scanf("%s %s", n1, n2);

    //일단 뒤집고
    reverse(n1, n11);
	reverse(n2, n22);

    //뒤집은애 자릿수 구하고, 당연히 d1>=d2
    d1 = strlen(n11);
	d2 = strlen(n22);

    //자릿수 다를때 뒤에 0넣기
    if(d1>d2){
        for (i = d1 - (d1 - d2); i < d1; i++)
			n22[i] = '0';
		n22[d1] = '\0';
    }

	//carry 계산
    for (i = 0; i < strlen(n11); i++) {
		if (minusCarry(n11[i], n22[i], m_carry) == 1) {
			//carry가 발생했으므로 m_carry는 1이 됨
			m_carry = 1;
			cnt++;
		}
		else
			//carry가 발생하지 않았으므로 m_carry는 0이 됨
			m_carry = 0;
	}

    printf("%d\n", cnt);

	return 0;
}
