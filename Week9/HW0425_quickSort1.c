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

    // j�� ��� �������� Pivot(A[r])�� ��
    for (; j < r; j++)
    {
        //�������� ���� '>'
        if (A[j].korean > A[r].korean)
        {
            i++;
            // A[j]<->A[i]
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }

    // Pivot�� �� ����, Pivot�� i++�� �ڸ��� ����
    i++;
    t = A[i];
    A[i] = A[r];
    A[r] = t;

    return i; // partition��ġ ��ȯ
}
void quickSort(struct Student *A, int p, int r)
{
    int q;

    if (p < r)
    {
        q = partition(A, p, r);

        // partition��ġ �������� �տ� �ٽ� ����, �ڿ��� ����
        // partition�� ���ĵǾ������Ƿ� q-1, q+1�ϴ� ��
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

    printf("�л� ���� �Է��ϼ���: ");
    scanf("%d", &n);

    arr = (struct Student *)malloc(sizeof(struct Student) * n);

    if (!arr)
    {
        printf("�޸𸮸� �Ҵ��� �� �����ϴ�.");
        return 0;
    }

    // arr�� �� �Է�
    for (i = 0; i < n; i++)
    {
        arr[i].id = i + 1;
        arr[i].english = (rand() % 101);
        arr[i].korean = (rand() % 101);
        arr[i].math = (rand() % 101);
    }

    //���� �� ���
    printList(arr, 0, n);

    //���� ���� �������� ����
    quickSort(arr, 0, n - 1);

    //���� �� ���
    printList(arr, 0, n);

    free(arr);
    return 0;
}