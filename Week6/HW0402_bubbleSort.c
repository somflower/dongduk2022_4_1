#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Student
{
    int id;
    int korean, english, math;
};
void printStudentArr(int n, struct Student *s){
    int i;

     for (i = 0; i < n; i++)
    {
        printf("�й� : %d\t���� : %d\t���� : %d\t���� : %d\n",
               s[i].id, s[i].english, s[i].math, s[i].korean);
    }
}
void bubble_sort_swap(int n, struct Student *s)
{
    int i, j;
    struct Student tmp;

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            if (s[j].id > s[j + 1].id)
            {
                tmp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = tmp;
            }
        }
    }
}
void bubble_sort(int n, int select, struct Student *s)
{
    int i, j;
    struct Student tmp;

    for (i = 0; i < n-1; i++)
    {
        for (j = n-1; j > i; j--)
        {
            switch (select)
            {
            case 1:
                if (s[j].korean > s[j - 1].korean)
                {
                    tmp = s[j];
                    s[j] = s[j - 1];
                    s[j - 1] = tmp;
                }
                break;
            case 2:
                if (s[j].math > s[j - 1].math)
                {
                    tmp = s[j];
                    s[j] = s[j - 1];
                    s[j - 1] = tmp;
                }
                break;
            case 3:
                if (s[j].english > s[j - 1].english)
                {
                    tmp = s[j];
                    s[j] = s[j - 1];
                    s[j - 1] = tmp;
                }
                break;

            default:
                break;
            }
        }
    }
}
int main(void)
{
    int n, i, select;
    struct Student *sList;

    srand(time(NULL));

    printf("�л� ���� �Է��ϼ���: ");
    scanf("%d", &n);

    sList = (struct Student *)malloc(sizeof(struct Student) * n);
    if (!sList)
    {
        printf("�޸𸮸� �Ҵ��� �� �����ϴ�.");
        return 0;
    }

    for (i = 0; i < n; i++)
    {
        sList[i].id = i + 1;
        sList[i].english = rand() % 101;
        sList[i].korean = rand() % 101;
        sList[i].math = rand() % 101;
    }

    printStudentArr(n, sList);
    printf("\n");

    do
    {
        printf("���� ���� ����(1:����, 2:����, 3:����, 4:id(��������), 0:������) : ");
        scanf("%d", &select);

        if (select < 4 && select > 0)
        {
            bubble_sort(n, select, sList);
            printStudentArr(n, sList);
            printf("\n");
        }
        else if (select == 4)
        {
            bubble_sort_swap(n, sList);
            printStudentArr(n, sList);
            printf("\n");
        }

    } while (select != 0);

    free(sList);

    return 0;
}