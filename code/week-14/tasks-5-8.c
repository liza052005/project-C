// #ifndef MATRIX_OPS_H
// #define MATRIX_OPS_H
// double** matrix_add(double **a, double **b, int n);
// double** matrix_sub(double **a, double **b, int n);
// double** matrix_mul(double **a, double **b, int n);
// #endif
// double** matrix_add(double **a, double **b, int n)
// {
//     int i, j;
//     double **res = (double**)malloc(n * sizeof(double*));
    
//     for (i = 0; i < n; i++)
//     {
//         res[i] = (double*)malloc(n * sizeof(double));
//         for (j = 0; j < n; j++)
//         {
//             res[i][j] = a[i][j] + b[i][j];
//         }
//     }
//     return res;
// }
// double** matrix_sub(double **a, double **b, int n)
// {
//     int i, j;
//     double **res = (double**)malloc(n * sizeof(double*));
    
//     for (i = 0; i < n; i++)
//     {
//         res[i] = (double*)malloc(n * sizeof(double));
//         for (j = 0; j < n; j++)
//         {
//             res[i][j] = a[i][j] - b[i][j];
//         }
//     }
//     return res;
// }
// double** matrix_mul(double **a, double **b, int n)
// {
//     int i, j, k;
//     double **res = (double**)malloc(n * sizeof(double*));
    
//     for (i = 0; i < n; i++)
//     {
//         res[i] = (double*)malloc(n * sizeof(double));
//         for (j = 0; j < n; j++)
//         {
//             res[i][j] = 0;
//             for (k = 0; k < n; k++)
//             {
//                 res[i][j] += a[i][k] * b[k][j];
//             }
//         }
//     }
//     return res;
// }
// #include <stdio.h>
// #include <stdlib.h>
// #include "matrix_ops.h"
// void main()
// {
//     int n, i, j;
//     char op;
//     double **a, **b, **res;
//     printf("Input matrix size n:\n");
//     scanf("%d", &n);
//     a = (double**)malloc(n * sizeof(double*));
//     b = (double**)malloc(n * sizeof(double*));
//         printf("Input first matrix:\n");
//     for (i = 0; i < n; i++)
//     {
//         a[i] = (double*)malloc(n * sizeof(double));
//         for (j = 0; j < n; j++)
//         {
//             scanf("%lf", &a[i][j]);
//         }
//     }
//         printf("Input second matrix:\n");
//     for (i = 0; i < n; i++)
//     {
//         b[i] = (double*)malloc(n * sizeof(double));
//         for (j = 0; j < n; j++)
//         {
//             scanf("%lf", &b[i][j]);
//         }
//     }
//     printf("Input operation (+, -, *):\n");
//     scanf(" %c", &op);
//         switch (op)
//     {
//         case '+': res = matrix_add(a, b, n); break;
//         case '-': res = matrix_sub(a, b, n); break;
//         case '*': res = matrix_mul(a, b, n); break;
//         default: printf("Unknown operation\n"); return;
//     }
//         printf("Result:\n");
//     for (i = 0; i < n; i++)
//     {
//         for (j = 0; j < n; j++)
//         {
//             printf("%.2lf ", res[i][j]);
//         }
//         printf("\n");
//     }
//         for (i = 0; i < n; i++)
//     {
//         free(a[i]);
//         free(b[i]);
//         free(res[i]);
//     }
//     free(a);
//     free(b);
//     free(res);

#include <stdio.h>
#include <string.h>

void main()
{
    FILE *f1, *f2;
    char line[200];
    char surname[50], name[50], patronymic[50];
    int year;
    
    f1 = fopen("input.txt", "rt");
    f2 = fopen("output.txt", "wt");
    
    if (f1 == NULL || f2 == NULL)
    {
        printf("Error opening files\n");
        return;
    }
    
    while (fgets(line, 200, f1) != NULL)
    {
        sscanf(line, "%s %s %s %d", surname, name, patronymic, &year);
        if (year > 1980)
        {
            fprintf(f2, "%s %s %s %d\n", surname, name, patronymic, year);
        }
    }
    
    fclose(f1);
    fclose(f2);
    printf("Done\n");
}
#include <stdio.h>
#include <string.h>

struct humen
{
    char name[50];
    char surname[50];
    int year;
};

void main()
{
    struct humen arr1[4], arr2[4];
    struct humen temp;
    int i, j;
    
    printf("Input 4 persons (name, surname, year):\n");
    for (i = 0; i < 4; i++)
    {
        scanf("%s %s %d", arr1[i].name, arr1[i].surname, &arr1[i].year);
        arr2[i] = arr1[i];
    }
    
    for (i = 0; i < 3; i++)
    {
        for (j = i + 1; j < 4; j++)
        {
            if (arr2[i].year > arr2[j].year)
            {
                temp = arr2[i];
                arr2[i] = arr2[j];
                arr2[j] = temp;
            }
        }
    }
    
    printf("Sorted by year:\n");
    for (i = 0; i < 4; i++)
    {
        printf("%s %s %d\n", arr2[i].name, arr2[i].surname, arr2[i].year);
    }
}