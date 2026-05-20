#include <stdio.h>
#include <windows.h>
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    double a[3][3];
    double sum_main = 0, sum_secondary = 0;
    int i, j;
    printf("Введите матрицу 3х3:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%lf", &a[i][j]);
        }
    }
    for (i = 0; i < 3; i++)
    {
        sum_main += a[i][i];
        sum_secondary += a[i][2 - i];
    }
    printf("Сумма по главной диагонали: %.2lf\n", sum_main);
    printf("Сумма второстепенной диагонали: %.2lf\n\n", sum_secondary);
    int b[2][2], c[2][2];
    printf("Введите матрицу 2х2:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                c[i][j] += b[i][k] * b[k][j];
            }
        }
    }
    printf("square matrix:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}