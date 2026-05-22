//вывод исходных матриц
        c
#include <stdio.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    double a[3][3];
    double sum_main = 0, sum_secondary = 0;

    printf("=== ЧАСТЬ 1: Матрица 3x3 ===\n");
    printf("Введите 9 чисел через пробел или enter:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Строка %d: ", i + 1);
        for (int j = 0; j < 3; j++)
        {
            scanf("%lf", &a[i][j]);
        }
    }

    // вывод введенной матрицы (чтоб препод видел)
    printf("\nВведенная матрица:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%8.2lf ", a[i][j]);
        }
        printf("\n");
    }

    // суммы диагоналей
    for (int i = 0; i < 3; i++)
    {
        sum_main += a[i][i];
        sum_secondary += a[i][2 - i];
    }

    printf("\nСумма главной диагонали: %.2lf\n", sum_main);
    printf("Сумма побочной диагонали: %.2lf\n", sum_secondary);

    // ============ ЧАСТЬ 2 ============
    printf("\n=== ЧАСТЬ 2: Матрица 2x2 ===\n");

    int b[2][2], c[2][2];

    printf("Введите 4 целых числа:\n");
    for (int i = 0; i < 2; i++)
    {
        printf("Строка %d: ", i + 1);
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    // вывод исходной матрицы
    printf("\nИсходная матрица:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%4d ", b[i][j]);
        }
        printf("\n");
    }

    // умножение матрицы на себя
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                c[i][j] += b[i][k] * b[k][j];
            }
        }
    }

    printf("\nКвадрат матрицы (B * B):\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%4d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}
//proverka vvoda i obrabotka
c
#include <stdio.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    double a[3][3];
    double sum_main = 0, sum_secondary = 0;
    int i, j;

    printf("Введите матрицу 3x3 (9 чисел):\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (scanf("%lf", &a[i][j]) != 1)
            {
                printf("Ошибка ввода! Нужно вводить числа.\n");
                return 1;
            }
        }
    }

    // тупой вывод матрицы для наглядности
    printf("\nМатрица:\n");
    for (i = 0; i < 3; i++)
    {
        printf("| ");
        for (j = 0; j < 3; j++)
        {
            printf("%6.2lf ", a[i][j]);
        }
        printf("|\n");
    }

    for (i = 0; i < 3; i++)
    {
        sum_main += a[i][i];
        sum_secondary += a[i][2 - i];
    }

    printf("\nГлавная диагональ (a[0][0]+a[1][1]+a[2][2]) = %.2lf\n", sum_main);
    printf("Побочная диагональ (a[0][2]+a[1][1]+a[2][0]) = %.2lf\n", sum_secondary);

    // матрица 2x2
    int b[2][2], rez[2][2];

    printf("\nТеперь матрица 2x2 (4 целых числа):\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            if (scanf("%d", &b[i][j]) != 1)
            {
                printf("Ошибка ввода!\n");
                return 1;
            }
        }
    }

    printf("\nМатрица B:\n");
    for (i = 0; i < 2; i++)
    {
        printf("| %d %d |\n", b[i][0], b[i][1]);
    }

    // считаем квадрат матрицы вручную (студенты так делают)
    rez[0][0] = b[0][0]*b[0][0] + b[0][1]*b[1][0];
    rez[0][1] = b[0][0]*b[0][1] + b[0][1]*b[1][1];
    rez[1][0] = b[1][0]*b[0][0] + b[1][1]*b[1][0];
    rez[1][1] = b[1][0]*b[0][1] + b[1][1]*b[1][1];

    printf("\nB^2:\n");
    for (i = 0; i < 2; i++)
    {
        printf("| %d %d |\n", rez[i][0], rez[i][1]);
    }

    return 0;
}
//stude stylec
#include <stdio.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // матрица 3х3 для диагоналек
    double mat[3][3];
    double glav = 0, pob = 0;  // суммы диагоналей

    printf("Введи 9 чисел для матрицы 3х3:\n");

    // заполняем матрицу
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            scanf("%lf", &mat[i][j]);
        }
    }

    // считаем сумму главной и побочной диагонали
    for(int i=0; i<3; i++)
    {
        glav = glav + mat[i][i];           // главная - это где i=j
        pob = pob + mat[i][2-i];            // побочная - где j=2-i
    }

    printf("\nСумма главной = %.2f\n", glav);
    printf("Сумма побочной = %.2f\n\n", pob);

    // ====== матрица 2х2 ======
    int A[2][2];
    int B[2][2];

    printf("Введи 4 числа для матрицы 2х2:\n");
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    // умножаем матрицу саму на себя
    // формула: C[i][j] = sum(A[i][k] * A[k][j])
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            B[i][j] = A[i][0]*A[0][j] + A[i][1]*A[1][j];  // расписали для 2х2
        }
    }

    printf("\nРезультат возведения в квадрат:\n");
    for(int i=0; i<2; i++)
    {
        printf("%d %d\n", B[i][0], B[i][1]);
    }

    return 0;
}