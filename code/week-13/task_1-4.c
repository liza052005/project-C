#include <stdio.h>
#include <math.h>

void main()
{
    double a, b, c, x1, x2;
    printf("Введите коэф-ты:: \n");
    scanf("%lf %lf %lf, &a, &b, &c");
    d = pow(b,2) - 4*a*c;
    if(d<0)
    {
        x1 = (-b + sqrt(d))/(2*a);
        x2 = (-b - sqrt(d))/(2*a);
    }
}