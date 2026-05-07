#include <stdio.h>
#include <stdlib.h>
#include "matrix_ops.h"
void main()
{
    int n, i, j;
    char op;
    double **a, **b, **res;
    printf("Input matrix size n:\n");
    scanf("%d", &n);
    a = (double**)malloc(n * sizeof(double*));
    b = (double**)malloc(n * sizeof(double*));
        printf("Input first matrix:\n");
    for (i = 0; i < n; i++)
    {
        a[i] = (double*)malloc(n * sizeof(double));
        for (j = 0; j < n; j++)
        {
            scanf("%lf", &a[i][j]);
        }
    }
        printf("Input second matrix:\n");
    for (i = 0; i < n; i++)
    {
        b[i] = (double*)malloc(n * sizeof(double));
        for (j = 0; j < n; j++)
        {
            scanf("%lf", &b[i][j]);
        }
    }
    printf("Input operation (+, -, *):\n");
    scanf(" %c", &op);
        switch (op)
    {
        case '+': res = matrix_add(a, b, n); break;
        case '-': res = matrix_sub(a, b, n); break;
        case '*': res = matrix_mul(a, b, n); break;
        default: printf("Unknown operation\n"); return;
    }
        printf("Result:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%.2lf ", res[i][j]);
        }
        printf("\n");
    }
        for (i = 0; i < n; i++)
    {
        free(a[i]);
        free(b[i]);
        free(res[i]);
    }
    free(a);
    free(b);
    free(res);