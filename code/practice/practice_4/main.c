#include <stdio.h>
#include <windows.h>
#include "triangle.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    double a, b, c;
    printf("Введите стороны треугольника:\n");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3)
    {
        printf("Ошибка: Неверный ввод!\n");
        return 1;
    }
    if (a <= 0 || b <= 0 || c <= 0)
    {
        printf("Ошибка: Стороны должны быть положительными!\n");
        return 1;
    }
    if (a + b > c && a + c > b && b + c > a)
    {
        printf("Периметр: %.2lf\n", perimeter(a, b, c));
        printf("Площадь: %.2lf\n", area(a, b, c));
    }
    else
    {
        printf("Неравенство треугольника не выполняется\n");
        printf("(Сумма любых двух сторон должна быть больше третьей)\n");
    }
    return 0;
}