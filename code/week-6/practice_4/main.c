#include <stdio.h>
#include "triangle.h"

int main()
{
    double a, b, c;
    
    printf("Введите стороны треугольника:\n");
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("c = ");
    scanf("%lf", &c);
    
    if(a+b>c && a+c>b && b+c>a)
    {
        double p = perimetr(a,b,c);
        double s = area(a,b,c);
           printf("Периметр: %.2f\n", p);
        printf("Площадь: %.2f\n", s);
           printf("Периметр: %.2f\n", p);
        printf("Площадь: %.2f\n", s);
    }
    else
    {
        printf("треугольник не существует! \n");

    }
    return 0;
}