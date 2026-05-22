Модификация 1: Добавить обработку случая a = 0 (линейное уравнение)
c
#include <stdio.h>
#include <math.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    double a, b, c, x1, x2, D;

    printf("Введите коэф-ты (a b c): \n");
    scanf("%lf %lf %lf", &a, &b, &c);

    // проверка на линейное уравнение (студенты часто забывают)
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
                printf("Бесконечно много решений\n");
            else
                printf("Нет решений\n");
        }
        else
        {
            x1 = -c / b;
            printf("Линейное уравнение, один корень: x = %.2lf\n", x1);
        }
        return 0;
    }

    D = b * b - 4 * a * c;  // b*b быстрее чем pow(b,2)

    if (D > 0)
    {
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);
        printf("Два корня: x1 = %.2lf, x2 = %.2lf\n", x1, x2);
    }
    else if (D == 0)
    {
        x1 = -b / (2 * a);
        printf("Один корень (D=0): x = %.2lf\n", x1);
    }
    else
    {
        printf("Дискриминант отрицательный, корней нет\n");
    }

    return 0;
}
Модификация 2: Добавить вычисление комплексных корней
c
#include <stdio.h>
#include <math.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    double a, b, c, D;
    double real, imag;

    printf("Введите a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a == 0)
    {
        printf("Это не квадратное уравнение (a=0)\n");
        return 1;
    }

    D = b*b - 4*a*c;

    if (D > 0)
    {
        double x1 = (-b + sqrt(D)) / (2*a);
        double x2 = (-b - sqrt(D)) / (2*a);
        printf("x1 = %.2lf, x2 = %.2lf\n", x1, x2);
    }
    else if (D == 0)
    {
        double x = -b / (2*a);
        printf("x = %.2lf\n", x);
    }
    else
    {
        // комплексные корни (препод любит такое)
        real = -b / (2*a);
        imag = sqrt(-D) / (2*a);
        printf("x1 = %.2lf + %.2lfi\n", real, imag);
        printf("x2 = %.2lf - %.2lfi\n", real, imag);
    }

    return 0;
}
Модификация 3: Добавить проверку ввода и цикл
        c
#include <stdio.h>
#include <math.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    double a, b, c, D;
    char again = 'y';

    while (again == 'y' || again == 'Y')
    {
        printf("\n=== Решение квадратного уравнения ===\n");
        printf("Введите a, b, c: ");

        if (scanf("%lf %lf %lf", &a, &b, &c) != 3)
        {
            printf("Ошибка ввода!\n");
            while(getchar() != '\n'); // чистим буфер
            continue;
        }

        if (a == 0)
        {
            printf("A не может быть 0!\n");
        }
        else
        {
            D = b*b - 4*a*c;
            printf("Дискриминант = %.2lf\n", D);

            if (D > 0)
            {
                double x1 = (-b + sqrt(D)) / (2*a);
                double x2 = (-b - sqrt(D)) / (2*a);
                printf("x1 = %.2lf, x2 = %.2lf\n", x1, x2);
            }
            else if (D == 0)
            {
                printf("x = %.2lf\n", -b/(2*a));
            }
            else
            {
                printf("Корней нет, D < 0\n");
            }
        }

        printf("\nЕщё раз? (y/n): ");
        scanf(" %c", &again);
    }

    printf("Пока!\n");
    return 0;
}
Модификация 4: "Студенческий" стиль (немного хаотичный)
        c
#include <stdio.h>
#include <math.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    double aa, bb, cc;  // странные имена как у студента
    double d, x1, x2;

    printf("Привет! Введи три числа: ");
    scanf("%lf %lf %lf", &aa, &bb, &cc);

    if (aa == 0)
    {
        printf("Ошибка! Это не квадратное уравнение!\n");
        return 1;
    }

    d = bb*bb - 4*aa*cc;

    if (d < 0)
    {
        printf("Корней нет! Дискриминант отрицательный, учи математику!\n");
    }
    else if (d == 0)
    {
        x1 = -bb / (2*aa);
        printf("Один корень: x = %.2f\n", x1);
    }
    else
    {
        x1 = (-bb + sqrt(d)) / (2*aa);
        x2 = (-bb - sqrt(d)) / (2*aa);
        printf("x1 = %.2f, x2 = %.2f\n", x1, x2);
        printf("Проверка: x1+x2 = %.2f, x1*x2 = %.2f\n", x1+x2, x1*x2);
    }

    system("pause");  // студенты любят system("pause")
    return 0;
}