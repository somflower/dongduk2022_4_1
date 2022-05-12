#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Stdlib.h>
#include <time.h>
struct Student
{
    int id;
    int korean, english, math;
};
void swap(struct Student *A, int i, int j)
{
    struct Student t;

    t = A[i];
    A[i] = A[j];
    A[j] = t;
}
int partition(struct Student *A, int p, int r, int select)
{
    int i, j;
    struct Student t;

    j = p;
    i = p - 1;

    // j를 계속 증가시켜 Pivot(A[r])과 비교
    for (; j < r; j++)
    {
        //내림차순 정렬 '>', 오름차순 정렬 '<'
        if (select == 1 && A[j].korean > A[r].korean ||
            select == 2 && A[j].math > A[r].math ||
            select == 3 && A[j].english > A[r].english ||
            select == 4 && A[j].id < A[r].id)
        {
            i++;
            // A[j]<->A[i]
            swap(A, i, j);
        }
    }

    // Pivot과 비교 끝남, Pivot을 i++한 자리에 넣음
    i++;
    
    swap(A, i, r);

    return i; // partition위치 반환
}
void quickSort(struct Student *A, int p, int r, int select)
{
    int q;

    if (p < r)
    {
        q = partition(A, p, r, select);

        // partition위치 기준으로 앞에 다시 정렬, 뒤에도 정렬
        // partition은 정렬되어있으므로 q-1, q+1하는 것
        quickSort(A, p, q - 1, select);
        quickSort(A, q + 1, r, select);
    }
}
void printList(struct Student *A, int s, int e)
{
    int i;
    for (i = s; i < e; i++)
        printf("학번 : %d,\t영어 : %d,\t수학 : %d,\t국어 : %d\n", A[i].id, A[i].english, A[i].math, A[i].korean);
    printf("\n");
}
int main(void)
{
    int n, i, select;
    struct Student *arr;

    srand(time(NULL));

    printf("학생 수를 입력하세요: ");
    scanf("%d", &n);

    arr = (struct Student *)malloc(sizeof(struct Student) * n);

    if (!arr)
    {
        printf("메모리를 할당할 수 없습니다.");
        return 0;
    }

    // arr에 값 입력
    for (i = 0; i < n; i++)
    {
        arr[i].id = i + 1;
        arr[i].english = (rand() % 101);
        arr[i].korean = (rand() % 101);
        arr[i].math = (rand() % 101);
    }

    //정렬 전 출력
    printList(arr, 0, n);

    // select&반복문
    do
    {
        printf("정렬 기준 선택(1:국어, 2:수학, 3:영어, 4:id(오름차순), 0:끝내기) : ");
        scanf("%d", &select);

        if (select <= 4 && select > 0)
        {
            quickSort(arr, 0, n - 1, select);
            printList(arr, 0, n);
        }
    } while (select != 0);

    free(arr);
    return 0;
}