#include <stdio.h>
#include <windows.h>
#include "triangle.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    double a, b, c;
    printf("Input triangle sides:\n");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3)
    {
        printf("Error: Invalid input!\n");
        return 1;
    }
    if (a <= 0 || b <= 0 || c <= 0)
    {
        printf("Error: Sides must be positive!\n");
        return 1;
    }
    if (a + b > c && a + c > b && b + c > a)
    {
        printf("Perimeter: %.2lf\n", perimeter(a, b, c));
        printf("Area: %.2lf\n", area(a, b, c));
    }
    else
    {
        printf("Triangle inequality failed\n");
        printf("(The sum of any two sides must be greater than the third)\n");
    }
    return 0;
}