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
    double *A, *B, *result;
    A = (double*)malloc(n * n * sizeof(double));
    B = (double*)malloc(n * n * sizeof(double));
    if(A == NULL || B == NULL)
    {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }
    printf("\nВведите элементы матрицы A:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("A[%d][%d] = ", i, j);
            scanf("%lf", &A[i*n + j]);
        }
    }
    printf("\nВведите элементы матрицы B:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("B[%d][%d] = ", i, j);
            scanf("%lf", &B[i*n + j]);
        }
    }
    printf("\nВведите операцию (+, -, *): ");
    scanf(" %c", &op);
    result = matrix_operation(A, B, n, op);
    if(result != NULL)
    {
        printf("\nРезультат операции %c:\n", op);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                printf("%.2f\t", result[i*n + j]);
            }
            printf("\n");
        }
        free(result);
    }
    free(A);
    free(B);

    return 0;
}