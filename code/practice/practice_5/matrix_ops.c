#include <stdio.h>
#include <stdlib.h>
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
            {
                C[i] = A[i] + B[i];
            }
            break;

        case '-':
            for(int i = 0; i < n * n; i++)
            {
                C[i] = A[i] - B[i];
            }
            break;

        case '*':
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    C[i*n + j] = 0;
                    for(int k = 0; k < n; k++)
                    {
                        C[i*n + j] += A[i*n + k] * B[k*n + j];
                    }
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