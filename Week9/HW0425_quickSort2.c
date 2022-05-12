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

    // j�� ��� �������� Pivot(A[r])�� ��
    for (; j < r; j++)
    {
        //�������� ���� '>', �������� ���� '<'
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

    // Pivot�� �� ����, Pivot�� i++�� �ڸ��� ����
    i++;
    
    swap(A, i, r);

    return i; // partition��ġ ��ȯ
}
void quickSort(struct Student *A, int p, int r, int select)
{
    int q;

    if (p < r)
    {
        q = partition(A, p, r, select);

        // partition��ġ �������� �տ� �ٽ� ����, �ڿ��� ����
        // partition�� ���ĵǾ������Ƿ� q-1, q+1�ϴ� ��
        quickSort(A, p, q - 1, select);
        quickSort(A, q + 1, r, select);
    }
}
void printList(struct Student *A, int s, int e)
{
    int i;
    for (i = s; i < e; i++)
        printf("�й� : %d,\t���� : %d,\t���� : %d,\t���� : %d\n", A[i].id, A[i].english, A[i].math, A[i].korean);
    printf("\n");
}
int main(void)
{
    int n, i, select;
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

    // select&�ݺ���
    do
    {
        printf("���� ���� ����(1:����, 2:����, 3:����, 4:id(��������), 0:������) : ");
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