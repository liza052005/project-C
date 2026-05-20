#include <stdio.h>
#include <math.h>
#include <windows.h>

int main()  // Исправлено: void main() -> int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    double a, b, c, x1, x2, D;
    printf("Введите коэф-ты (a b c): \n");
    scanf("%lf %lf %lf", &a, &b, &c);
    D = pow(b, 2) - 4 * a * c;
    if(D >= 0)
    {
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);
        printf("Корни уравнения: x1 = %.2lf, x2 = %.2lf\n", x1, x2);
    }
    else
    {
        printf("Нет действительных корней\n");
    }

    return 0;
}