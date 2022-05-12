#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Student
{
    int id;
    int korean, english, math;
};
void selection_sort(int n, struct Student *s)
{
    int i, j, max, max_idx;
    struct Student tmp;

    for (i = 0; i < n - 1; i++)
    {
        max = s[n - 1].korean;
        max_idx = n - 1;
        for (j = i; j < n - 1; j++)
        {
            if (s[j].korean > max)
            {
                max = s[j].korean;
                max_idx = j;
            }
        }
        if (max_idx != i)
            {
                tmp = s[max_idx];
                s[max_idx] = s[i];
                s[i] = tmp;
            }
    }
}
int main(void)
{
    int n, i;
    struct Student *sList;

    srand(time(NULL));

    printf("Enter a Student number: ");
    scanf("%d", &n);

    sList = (struct Student *)malloc(sizeof(struct Student) * n);
    if (!sList)
    {
        printf("메모리를 할당할 수 없습니다.");
        return 0;
    }

    for (i = 0; i < n; i++)
    {
        sList[i].id = i + 1;
        sList[i].english = rand() % 101;
        sList[i].korean = rand() % 101;
        sList[i].math = rand() % 101;
    }

    printf("Before\n");
    for (i = 0; i < n; i++)
    {
        printf("ID: %d\nKorean: %d\nEnglish: %d\nMath: %d\n",
               sList[i].id, sList[i].korean, sList[i].english, sList[i].math);
        printf("\n");
    }

    printf("After\n");
    selection_sort(n, sList);
    for (i = 0; i < n; i++)
    {
        printf("ID: %d\nKorean: %d\nEnglish: %d\nMath: %d\n",
               sList[i].id, sList[i].korean, sList[i].english, sList[i].math);
        printf("\n");
    }

    free(sList);

    return 0;
}