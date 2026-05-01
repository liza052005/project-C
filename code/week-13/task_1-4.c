// #include <stdio.h>
// #include <math.h>

// void main()
// {
//     double a, b, c, x1, x2;
//     printf("Введите коэф-ты:: \n");
//     scanf("%lf %lf %lf, &a, &b, &c");
//     d = pow(b,2) - 4*a*c;
//     if(d<0)
//     {
//         x1 = (-b + sqrt(d))/(2*a);
//         x2 = (-b - sqrt(d))/(2*a);
//     }
//     else
//     {
//         printf("Нет корней\n");
//     }
// }

// таск 2
#include <stdio.h>

void main()
{
    // Матрица 3x3 для диагоналей
    double a[3][3];
    double sum_main = 0, sum_secondary = 0;
    int i, j;
    printf("Input 3x3 matrix:\n");
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
    printf("Main diagonal sum: %.2lf\n", sum_main);
    printf("Secondary diagonal sum: %.2lf\n", sum_secondary);
    
    // Матрица 2x2 для квадрата
    int b[2][2], c[2][2];
    int k, l, m;
    
    printf("Input 2x2 integer matrix:\n");
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
            for (k = 0; k < 2; k++)
            {
                c[i][j] += b[i][k] * b[k][j];
            }
        }
    }
    printf("Square of matrix:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}
// таск 3 - замена симвволов на заглавные

#include <stdio.h>
#include <string.h>

void main()
{
    char s[81];
    int i;
    
    printf("Введите строку до 80 символов:\n");
    gets(s);
    
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == 'a' || s[i] == 'b')
        {
            s[i] = s[i]-32;
        }
    }
    
    printf("Result: %s\n", s);
}