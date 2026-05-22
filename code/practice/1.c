#include <stdio.h>
#include <math.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    float a, b, c;
    float d, x1, x2;

    printf("Введите a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);

    d = b*b - 4*a*c;

    if(d < 0)
    {
        printf("Нет корней\n");
    }
    else if(d == 0)
    {
        x1 = -b / (2*a);
        printf("Один корень: %.2f\n", x1);
    }
    else
    {
        x1 = (-b + sqrt(d)) / (2*a);
        x2 = (-b - sqrt(d)) / (2*a);
        printf("x1 = %.2f, x2 = %.2f\n", x1, x2);
    }

    system("pause");
    return 0;
}