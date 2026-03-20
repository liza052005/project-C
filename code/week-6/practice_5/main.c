#include <stdio.h>
#include <stdlib.h>
#include "matrix_ops.h"

int main()
{
    int n;
    char op;
    
    printf("Введите размер матриц n: ");
    scanf("%d", &n);
    
    double *A, *B, *result;
    
    // Выделяем память под матрицы
    A = (double*)malloc(n * n * sizeof(double));
    B = (double*)malloc(n * n * sizeof(double));
    
    // Проверяем, выделилась ли память
    if(A == NULL || B == NULL)
    {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }
    
    // Ввод матрицы A
    printf("\nВведите элементы матрицы A:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("A[%d][%d] = ", i, j);
            scanf("%lf", &A[i*n + j]);
        }
    }
    
    // Ввод матрицы B
    printf("\nВведите элементы матрицы B:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("B[%d][%d] = ", i, j);
            scanf("%lf", &B[i*n + j]);
        }
    }
    
    // Ввод операции
    printf("\nВведите операцию (+, -, *): ");
    scanf(" %c", &op);
    
    // Здесь будем вызывать функцию
    
    return 0;
}