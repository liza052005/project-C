#include <stdio.h>
#include "triangle.h"

void main()
{
    double a, b, c;
    
    printf("Input triangle sides:\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    
    if (a + b > c && a + c > b && b + c > a)
    {
        printf("Perimeter: %.2lf\n", perimeter(a, b, c));
        printf("Area: %.2lf\n", area(a, b, c));
    }
    else
    {
        printf("Triangle inequality failed\n");
    }
}