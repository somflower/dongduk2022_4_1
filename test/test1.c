#include <stdio.h>
void cntf(int *cnt){
    printf("f %d\n", *cnt);
    *cnt = *cnt + 1;
}
int main(void){
    int i;
    //printf("%c%c\n", 57,48);
    char n[5];
	int  cnt;

    scanf("%d", &cnt);
	
    cntf(cnt);

    printf("%d\n", cnt);
   /* for(i= 0; n[i]!="\0";i++){
        scanf("%s", n[i]);
    }
    
    n[i] = '\0';

    for(i= 0; n[i]!='\0';i++){
        printf("%c", n[i]);
    }*/
        
}