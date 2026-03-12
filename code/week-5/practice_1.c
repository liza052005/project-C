#include <stdio.h>
#include <math.h>

int main()
{
    double a,b,c;
    double D;
    double x1,x2;

    a = 1;
    b = -5;
    c = 2;

    printf("Уравнение %.1f* x^2 + %.1f*x + %.1f = 0\n", a,b,c);

    D = b*b - 4*a*c;
    printf("Дискриминант: D = %.2f\n", D);

    x1 = (-b + sqrt(D))/(2*a);
    x2 = (-b - sqrt(D))/(2*a);

    printf("Корни уравнения: \n");
    printf("x1 = %.2f\n", x1);
    printf("x2 = %.2f\n", x2);
    return 0;
}