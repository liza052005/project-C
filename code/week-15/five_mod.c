Модификация 1: Добавить вывод исходных матриц и проверки
c
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "matrix_ops.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int n;
    char op;

    printf("=== ОПЕРАЦИИ С МАТРИЦАМИ ===\n");
    printf("Введите размер матриц n: ");
    scanf("%d", &n);

    if(n <= 0)
    {
        printf("Размер должен быть положительным!\n");
        return 1;
    }

    double *A, *B, *result;
    A = (double*)malloc(n * n * sizeof(double));
    B = (double*)malloc(n * n * sizeof(double));

    if(A == NULL || B == NULL)
    {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }

    // ввод матрицы A
    printf("\n=== Матрица A ===\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("A[%d][%d] = ", i, j);
            scanf("%lf", &A[i*n + j]);
        }
    }

    // ввод матрицы B
    printf("\n=== Матрица B ===\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("B[%d][%d] = ", i, j);
            scanf("%lf", &B[i*n + j]);
        }
    }

    // вывод введенных матриц
    printf("\n=== Введенные матрицы ===\n");
    printf("Матрица A:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%8.2lf ", A[i*n + j]);
        }
        printf("\n");
    }

    printf("\nМатрица B:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%8.2lf ", B[i*n + j]);
        }
        printf("\n");
    }

    printf("\nВведите операцию (+, -, *): ");
    scanf(" %c", &op);

    result = matrix_operation(A, B, n, op);

    if(result != NULL)
    {
        printf("\n=== РЕЗУЛЬТАТ %c ===\n", op);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                printf("%8.2lf ", result[i*n + j]);
            }
            printf("\n");
        }
        free(result);
    }

    free(A);
    free(B);

    return 0;
}
Модификация 2: "Студенческий стиль" (с косяками и комментариями)
c
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "matrix_ops.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int n;
    char znak;  // операция

    printf("Введи размер квадратных матриц: ");
    scanf("%d", &n);

    // выделяем память (могли и забыть про проверку, но ладно)
    double *A = (double*)malloc(n * n * sizeof(double));
    double *B = (double*)malloc(n * n * sizeof(double));

    printf("\nЗаполняем матрицу А:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("A[%d][%d] = ", i, j);
            scanf("%lf", &A[i*n + j]);
        }
    }

    printf("\nЗаполняем матрицу B:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("B[%d][%d] = ", i, j);
            scanf("%lf", &B[i*n + j]);
        }
    }

    printf("\nЧто делаем? (+, -, *): ");
    scanf(" %c", &znak);

    double *C = matrix_operation(A, B, n, znak);

    if(C != NULL)
    {
        printf("\nРезультат:\n");
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                printf("%.1f  ", C[i*n + j]);
            }
            printf("\n");
        }
        free(C);
    }

    free(A);
    free(B);

    system("pause");
    return 0;
}
Модификация 3: Добавить меню и несколько операций подряд
c
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "matrix_ops.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int n;

    printf("Введите размер матриц: ");
    scanf("%d", &n);

    if(n <= 0)
    {
        printf("Неверный размер!\n");
        return 1;
    }

    double *A = (double*)malloc(n * n * sizeof(double));
    double *B = (double*)malloc(n * n * sizeof(double));

    if(!A || !B)
    {
        printf("Ошибка памяти!\n");
        return 1;
    }

    // ввод A
    printf("\n=== Матрица A ===\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            printf("A[%d][%d] = ", i, j);
            scanf("%lf", &A[i*n + j]);
        }

    // ввод B
    printf("\n=== Матрица B ===\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            printf("B[%d][%d] = ", i, j);
            scanf("%lf", &B[i*n + j]);
        }

    int menu;
    do
    {
        printf("\n=== МЕНЮ ===\n");
        printf("1 - Сложение (A+B)\n");
        printf("2 - Вычитание (A-B)\n");
        printf("3 - Умножение (A*B)\n");
        printf("4 - Выйти\n");
        printf("Выбери: ");
        scanf("%d", &menu);

        char op;
        if(menu == 1) op = '+';
        else if(menu == 2) op = '-';
        else if(menu == 3) op = '*';
        else if(menu == 4) break;
        else
        {
            printf("Неверный выбор!\n");
            continue;
        }

        double *result = matrix_operation(A, B, n, op);

        if(result)
        {
            printf("\nРезультат %c:\n", op);
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    printf("%8.2lf ", result[i*n + j]);
                }
                printf("\n");
            }
            free(result);
        }

    } while(menu != 4);

    free(A);
    free(B);

    printf("До свидания!\n");
    return 0;
}
Модификация 4: Добавить проверку на совместимость и запись в файл
c
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "matrix_ops.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int n;
    char op;

    printf("Введите размер матриц n: ");
    scanf("%d", &n);

    if(n <= 0)
    {
        printf("Ошибка: n должно быть > 0\n");
        return 1;
    }

    double *A = (double*)malloc(n * n * sizeof(double));
    double *B = (double*)malloc(n * n * sizeof(double));

    if(A == NULL || B == NULL)
    {
        printf("Не хватило памяти!\n");
        return 1;
    }

    printf("\nВвод матрицы A (%d x %d):\n", n, n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            printf("A[%d][%d] = ", i, j);
            scanf("%lf", &A[i*n + j]);
        }

    printf("\nВвод матрицы B:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            printf("B[%d][%d] = ", i, j);
            scanf("%lf", &B[i*n + j]);
        }

    printf("\nОперация (+, -, *): ");
    scanf(" %c", &op);

    double *result = matrix_operation(A, B, n, op);

    if(result != NULL)
    {
        // вывод на экран
        printf("\n=== РЕЗУЛЬТАТ ===\n");
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                printf("%10.2lf ", result[i*n + j]);
            }
            printf("\n");
        }

        // запись в файл
        FILE *f = fopen("matrix_result.txt", "w");
        if(f != NULL)
        {
            fprintf(f, "Операция: %c\n", op);
            fprintf(f, "Размер: %d x %d\n", n, n);
            fprintf(f, "Результат:\n");
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    fprintf(f, "%10.2lf ", result[i*n + j]);
                }
                fprintf(f, "\n");
            }
            fclose(f);
            printf("\nРезультат сохранен в matrix_result.txt\n");
        }

        free(result);
    }

    free(A);
    free(B);

    return 0;
}

//артем сказал
Модификация 1: Покомпонентное деление (простой вариант)
        c
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "matrix_ops.h"

double* matrix_operation(double *A, double *B, int n, char op)
{
    double *C = (double*)malloc(n * n * sizeof(double));
    if(C == NULL)
    {
        printf("Ошибка выделения памяти для результата!\n");
        return NULL;
    }

    switch(op)
    {
        case '+':
            for(int i = 0; i < n * n; i++)
                C[i] = A[i] + B[i];
            break;

        case '-':
            for(int i = 0; i < n * n; i++)
                C[i] = A[i] - B[i];
            break;

        case '*':
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                {
                    C[i*n + j] = 0;
                    for(int k = 0; k < n; k++)
                        C[i*n + j] += A[i*n + k] * B[k*n + j];
                }
            break;

            // НОВАЯ ОПЕРАЦИЯ: покомпонентное деление
        case '/':
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(B[i*n + j] == 0)
                    {
                        printf("Ошибка: деление на ноль в элементе [%d][%d]!\n", i, j);
                        free(C);
                        return NULL;
                    }
                    C[i*n + j] = A[i*n + j] / B[i*n + j];
                }
            }
            break;

        default:
            printf("Неизвестная операция!\n");
            free(C);
            return NULL;
    }

    return C;
}
Обновлённый main.c (с учётом новой операции):

c
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "matrix_ops.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int n;
    char op;

    printf("=== ОПЕРАЦИИ С МАТРИЦАМИ ===\n");
    printf("Введите размер матриц n: ");
    scanf("%d", &n);

    if(n <= 0)
    {
        printf("Неверный размер!\n");
        return 1;
    }

    double *A = (double*)malloc(n * n * sizeof(double));
    double *B = (double*)malloc(n * n * sizeof(double));

    if(A == NULL || B == NULL)
    {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }

    printf("\n=== Матрица A ===\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            printf("A[%d][%d] = ", i, j);
            scanf("%lf", &A[i*n + j]);
        }

    printf("\n=== Матрица B ===\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            printf("B[%d][%d] = ", i, j);
            scanf("%lf", &B[i*n + j]);
        }

    printf("\nДоступные операции: +, -, *, /\n");
    printf("Введите операцию: ");
    scanf(" %c", &op);

    double *result = matrix_operation(A, B, n, op);

    if(result != NULL)
    {
        printf("\n=== РЕЗУЛЬТАТ ОПЕРАЦИИ %c ===\n", op);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                printf("%10.2lf ", result[i*n + j]);
            printf("\n");
        }
        free(result);
    }

    free(A);
    free(B);

    return 0;
}