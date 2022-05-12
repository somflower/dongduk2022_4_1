#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Stdlib.h>
#include <time.h>
struct Student
{
    int id;
    int korean, english, math;
};
int partition(struct Student *A, int p, int r)
{
    int i, j;
    struct Student t;

    j = p;
    i = p - 1;

    // j를 계속 증가시켜 Pivot(A[r])과 비교
    for (; j < r; j++)
    {
        //내림차순 정렬 '>'
        if (A[j].korean > A[r].korean)
        {
            i++;
            // A[j]<->A[i]
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }

    // Pivot과 비교 끝남, Pivot을 i++한 자리에 넣음
    i++;
    t = A[i];
    A[i] = A[r];
    A[r] = t;

    return i; // partition위치 반환
}
void quickSort(struct Student *A, int p, int r)
{
    int q;

    if (p < r)
    {
        q = partition(A, p, r);

        // partition위치 기준으로 앞에 다시 정렬, 뒤에도 정렬
        // partition은 정렬되어있으므로 q-1, q+1하는 것
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}
void printList(struct Student *A, int s, int e)
{
    int i;
    for (i = s; i < e; i++)
        printf("id: %d, korean: %d, english: %d, math: %d\n", A[i].id, A[i].korean, A[i].english, A[i].math);
    printf("\n");
}
int main(void)
{
    int n, i;
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

    //국어 성적 기준으로 정렬
    quickSort(arr, 0, n - 1);

    //정렬 후 출력
    printList(arr, 0, n);

    free(arr);
    return 0;
}