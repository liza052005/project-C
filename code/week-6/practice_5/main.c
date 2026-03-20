#include <stdio.h>
#include <stdlib.h>  // для malloc/free
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
    printf("\nВведите элементы матрицы A:\n");
for(int i = 0; i < n; i++)
{
    for(int j = 0; j < n; j++)
    {
        printf("A[%d][%d] = ", i, j);
        // Обращение к элементу: A[i*n + j]
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
scanf(" %c", &op);  // пробел перед %c важен!
    return 1;
}
    
    return 0;
}