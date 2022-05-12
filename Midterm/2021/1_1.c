#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void reverse(char src_s[], char s[]) {
    int i, j, idx;

    //글자수 세기
    idx = strlen(src_s);

    //printf("%d", idx);

    //거꾸로 넣기
    for (i = 0; src_s[i] != '\0'; i++) {
        s[idx - i - 1] = src_s[i];
    }

    //마지막에 \0넣기
    s[idx] = '\0';
    //printf("%s\n", s);

}
int main(void) {
    char src_s[101];
    char s[101];

    scanf("%s", src_s);
    reverse(src_s, s);
    printf("%s\n", s);

    return 0;
}