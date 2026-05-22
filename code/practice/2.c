#include <stdio.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    double mat[3][3];
    double sum1 = 0, sum2 = 0;
    int i, j;
    printf("Введи матрицу 3х3 (9 чисел):\n");
    for(i = 0; i < 3; i++)
    {
        printf("Строка %d: ", i+1);
        for(j = 0; j < 3; j++)
        {
            scanf("%lf", &mat[i][j]);
        }
    }
    for(i = 0; i < 3; i++)
    {
        sum1 += mat[i][i];
        sum2 += mat[i][2-i];
    }
    printf("\nГлавная диагональ = %.2f\n", sum1);
    printf("Побочная диагональ = %.2f\n\n", sum2);

    int A[2][2], rez[2][2];

    printf("Введи матрицу 2х2 (4 целых числа):\n");
    for(i = 0; i < 2; i++)
    {
        printf("Строка %d: ", i+1);
        for(j = 0; j < 2; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            rez[i][j] = A[i][0]*A[0][j] + A[i][1]*A[1][j];
        }
    }
    printf("\nКвадрат матрицы:\n");
    for(i = 0; i < 2; i++)
    {
        printf("%d %d\n", rez[i][0], rez[i][1]);
    }

    system("pause");
    return 0;
}