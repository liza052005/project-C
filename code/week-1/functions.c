#include <stdio.h>
#include <windows.h>
void say_hello()
{
    printf("Привет! Я функция.\n");
}

int sum_two(int a, int b)
{
    int result;
    result = a + b;
    return result;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int x, y, total;
    say_hello();
    printf("Введите первое число: ");
    scanf("%d", &x);
    
    printf("Введите второе число: ");
    scanf("%d", &y);

    total = sum_two(x, y);
    printf("%d + %d = %d\n", x, y, total);
    
    return 0;
}