#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Stdlib.h>
int nextArr(int *arr, int n, int m)
{
    int i;

    //0번째 값이 n-m+1인지 확인, ex)n=5, m=3, 5-3+1 = 3
    //345가 조합 중 최대값이기 때문
    //앞자리가 정해지면 뒷자리도 자동으로 오름차순으로 정해져서 0번째 값만 봄
    if (arr[0] == (n - m + 1))
        return -1;
    //0번째 값이 n-m+1이 아닐때 == 조합 중 최대값이 아닐때
    //가장 오른쪽값과 그 앞의 값 이용해 다음 arr찾아내기
    else if (arr[m - 1] == n)//가장 오른쪽 값이 n일때==다음arr 구할때 복잡함(?ㅋㅋ)
    {
        
        if ((arr[m - 1] - arr[m - 2]) > 2)
        {
            arr[m - 1] = arr[m - 1] - 1;
            arr[m - 2] = arr[m - 2] + 1;
        }
        else if ((arr[m - 1] - arr[m - 2]) == 2)
        {
            arr[m - 2] = arr[m - 2] + 1;
        }
        else if ((arr[m - 1] - arr[m - 2]) == 1)
        {
            //1차이 안나는 부분 찾기
            for (i = m - 1; i > 0; i--)
            {
                if ((arr[i] - arr[i - 1]) != 1)
                    break;
            }
            //찾았으면 1차이 말고 얼마나 차이나는지 확인
            int sub = arr[i] - arr[i-1];
            //위와 같은 알고리즘
            if(sub>2){
                arr[i-1] = arr[i-1]+1;
                int k = arr[i-1];
                for(int j=i;j<m;j++)
                    arr[j] = ++k;
                //1456, N=6, M=4
                //2345
            }
            else if(sub==2){
                //2456->3456
                arr[i - 1] = arr[i - 1] + 1;
            }//sub==1은 존재 x
        }
        return 1;
    }
    else//가장 오른쪽 값이 n이 아닐때==다음arr 구할때 안 복잡함
    {
        arr[m - 1] = arr[m - 1] + 1;
        return 1;
    }
}
int main(void)
{
    int n, m;
    int *arr;
    int i;

    scanf("%d", &n);
    scanf("%d", &m);

    arr = (int *)malloc(sizeof(int) * m);

    if (!arr)
    {
        printf("메모리를 할당할 수 없습니다.");
        return 0;
    }

    //정답 입력
    for (i = 0; i < m; i++)
        scanf("%d", &arr[i]);

    if (nextArr(arr, n, m) == 1)
    {
        for (i = 0; i < m; i++)
            printf("%d ", arr[i]);
    }
    else
        printf("-1");

    printf("\n");
    free(arr);
}