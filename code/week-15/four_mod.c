Модификация 1: Добавить проверку типа треугольника + меню
        c
#include <stdio.h>
#include <windows.h>
#include "triangle.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    double a, b, c;
    int choice;

    printf("=== ТРЕУГОЛЬНИК ===\n");
    printf("1 - Найти периметр и площадь\n");
    printf("2 - Определить тип треугольника\n");
    printf("3 - Всё вместе\n");
    printf("Выбери: ");
    scanf("%d", &choice);

    printf("\nВведите стороны треугольника: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // проверки
    if (a <= 0 || b <= 0 || c <= 0)
    {
        printf("Ошибка: Стороны должны быть положительными!\n");
        return 1;
    }

    if (!(a + b > c && a + c > b && b + c > a))
    {
        printf("Неравенство треугольника не выполняется\n");
        return 1;
    }

    // периметр и площадь
    if (choice == 1 || choice == 3)
    {
        printf("\nПериметр: %.2lf\n", perimeter(a, b, c));
        printf("Площадь: %.2lf\n", area(a, b, c));
    }

    // тип треугольника
    if (choice == 2 || choice == 3)
    {
        printf("\nТип треугольника: ");
        if (a == b && b == c)
            printf("равносторонний\n");
        else if (a == b || b == c || a == c)
            printf("равнобедренный\n");
        else
            printf("разносторонний\n");

        // проверка на прямоугольный (теорема Пифагора)
        double a2 = a*a, b2 = b*b, c2 = c*c;
        if (a2 + b2 == c2 || a2 + c2 == b2 || b2 + c2 == a2)
            printf("Также это прямоугольный треугольник!\n");
    }

    return 0;
}
И обновленный triangle.h:

c
#ifndef TRIANGLE_H
#define TRIANGLE_H

double perimeter(double a, double b, double c);
double area(double a, double b, double c);

#endif
triangle.c без изменений.

Модификация 2: "Студенческий стиль" (с косяками)
c
#include <stdio.h>
#include <windows.h>
#include "triangle.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    double A, B, C;  // заглавные - странно, но бывает
    float p;          // студенты часто путают типы

    printf("Введи стороны треугольника через пробел: ");
    scanf("%lf %lf %lf", &A, &B, &C);

    // тупая проверка (без else)
    if(A <= 0) { printf("Сторона A не может быть 0 или отрицательной!\n"); return 1; }
    if(B <= 0) { printf("Сторона B не может быть 0 или отрицательной!\n"); return 1; }
    if(C <= 0) { printf("Сторона C не может быть 0 или отрицательной!\n"); return 1; }

    if(A + B > C && A + C > B && B + C > A)
    {
        printf("Периметр = %.2f\n", A + B + C);  // посчитали прямо здесь
        printf("Площадь = %.2f\n", area(A, B, C));
    }
    else
    {
        printf("Такого треугольника не бывает!\n");
    }

    system("pause");
    return 0;
}
Модификация 3: Добавить цикл для нескольких треугольников
        c
#include <stdio.h>
#include <windows.h>
#include "triangle.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    double a, b, c;
    char again;

    do
    {
        printf("\n========================================\n");
        printf("Введите стороны треугольника: ");

        if (scanf("%lf %lf %lf", &a, &b, &c) != 3)
        {
            printf("Ошибка ввода! Попробуй ещё раз.\n");
            while(getchar() != '\n');
            continue;
        }

        if (a <= 0 || b <= 0 || c <= 0)
        {
            printf("Стороны должны быть положительными!\n");
        }
        else if (a + b > c && a + c > b && b + c > a)
        {
            printf("\nРезультаты:\n");
            printf("  Периметр = %.2lf\n", perimeter(a, b, c));
            printf("  Площадь   = %.2lf\n", area(a, b, c));

            // дополнительная инфа для препода
            double p = perimeter(a, b, c) / 2;
            printf("  Полупериметр = %.2lf\n", p);
        }
        else
        {
            printf("Это не треугольник! Нарушено неравенство.\n");
        }

        printf("\nХочешь ввести ещё один треугольник? (y/n): ");
        scanf(" %c", &again);

    } while(again == 'y' || again == 'Y' || again == 'н' || again == 'Н');

    printf("\nПока!\n");
    return 0;
}
Модификация 4: Добавить вывод в файл (преподы такое любят)
        c
#include <stdio.h>
#include <windows.h>
#include "triangle.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    double a, b, c;

    printf("Введите стороны треугольника: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a <= 0 || b <= 0 || c <= 0)
    {
        printf("Ошибка: Стороны должны быть положительными!\n");
        return 1;
    }

    if (a + b > c && a + c > b && b + c > a)
    {
        double per = perimeter(a, b, c);
        double ar = area(a, b, c);

        printf("\nПериметр: %.2lf\n", per);
        printf("Площадь: %.2lf\n", ar);

        // записываем в файл
        FILE *f = fopen("rezultat.txt", "w");
        if(f != NULL)
        {
            fprintf(f, "Стороны: %.2lf, %.2lf, %.2lf\n", a, b, c);
            fprintf(f, "Периметр: %.2lf\n", per);
            fprintf(f, "Площадь: %.2lf\n", ar);
            fclose(f);
            printf("Результат сохранён в файл rezultat.txt\n");
        }
        else
        {
            printf("Не удалось создать файл!\n");
        }
    }
    else
    {
        printf("Неравенство треугольника не выполняется\n");
    }

    return 0;
}


//артем сказал
Модификация: Добавить функцию is_valid_triangle()
        c
#include <stdio.h>
#include <windows.h>
#include "triangle.h"

// НОВАЯ ФУНКЦИЯ: проверяет, существует ли треугольник
// Возвращает 1 (true) если существует, 0 (false) если нет
int is_valid_triangle(double a, double b, double c)
{
    if(a <= 0 || b <= 0 || c <= 0)
        return 0;  // стороны не могут быть отрицательными или нулевыми

    if(a + b > c && a + c > b && b + c > a)
        return 1;  // неравенство треугольника выполняется

    return 0;     // треугольник не существует
}

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

    // ИСПОЛЬЗУЕМ НОВУЮ ФУНКЦИЮ ДЛЯ ПРОВЕРКИ
    if (is_valid_triangle(a, b, c))
    {
        printf("Треугольник существует!\n");
        printf("Периметр: %.2lf\n", perimeter(a, b, c));
        printf("Площадь: %.2lf\n", area(a, b, c));
    }
    else
    {
        printf("Треугольник с такими сторонами не существует!\n");
        printf("(Сумма любых двух сторон должна быть больше третьей)\n");
    }

    return 0;
}
Полный код с обновлённым triangle.h:
triangle.h (добавляем прототип новой функции):

c
#ifndef TRIANGLE_H
#define TRIANGLE_H

double perimeter(double a, double b, double c);
double area(double a, double b, double c);
int is_valid_triangle(double a, double b, double c);  // НОВАЯ ФУНКЦИЯ

#endif
        triangle.c (добавляем реализацию):

c
#include <math.h>
#include "triangle.h"

double perimeter(double a, double b, double c)
{
    return a + b + c;
}

double area(double a, double b, double c)
{
    double p = perimeter(a, b, c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

// НОВАЯ ФУНКЦИЯ: проверка существования треугольника
int is_valid_triangle(double a, double b, double c)
{
    // проверка на положительность сторон
    if(a <= 0 || b <= 0 || c <= 0)
        return 0;

    // проверка неравенства треугольника
    if(a + b > c && a + c > b && b + c > a)
        return 1;

    return 0;
}
main.c (упрощённый, с использованием новой функции):

c
#include <stdio.h>
#include <windows.h>
#include "triangle.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    double a, b, c;

    printf("Введите стороны треугольника: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // используем новую функцию
    if(is_valid_triangle(a, b, c))
    {
        printf("OK! Треугольник существует\n");
        printf("Периметр = %.2lf\n", perimeter(a, b, c));
        printf("Площадь = %.2lf\n", area(a, b, c));
    }
    else
    {
        printf("Треугольник НЕ существует!\n");
        printf("Проверь стороны: a=%.2lf, b=%.2lf, c=%.2lf\n", a, b, c);
    }

    return 0;
}
"Студенческий" вариант (с комментариями на русском):
c
#include <stdio.h>
#include <windows.h>
#include "triangle.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    double a, b, c;

    printf("Введи стороны треугольника через пробел: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // проверяем существует ли треугольник
    if(is_valid_triangle(a, b, c) == 1)
    {
        printf("\nТреугольник правильный!\n");
        printf("Периметр: %.2f\n", perimeter(a, b, c));
        printf("Площадь: %.2f\n", area(a, b, c));
    }
    else
    {
        printf("\nТреугольник НЕ существует!\n");
        printf("Стороны не подходят\n");
    }

    system("pause");
    return 0;
}