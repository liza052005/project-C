#include <stdio.h>

/* Простая функция - приветствие */
void say_hello()
{
    printf("Привет! Я функция.\n");
}

/* Функция, которая складывает два числа */
int sum_two(int a, int b)
{
    int result;
    result = a + b;
    return result;
}

int main()
{
    int x, y, total;
    
    /* Вызов функции без параметров */
    say_hello();
    
    /* Ввод чисел */
    printf("Введите первое число: ");
    scanf("%d", &x);
    
    printf("Введите второе число: ");
    scanf("%d", &y);
    
    /* Вызов функции с параметрами */
    total = sum_two(x, y);
    
    /* Вывод результата */
    printf("%d + %d = %d\n", x, y, total);
    
    return 0;
}