#include <stdio.h>
#include <windows.h>
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int number;
    printf("Введите целое число: ");
    scanf("%d", &number);
    printf("\nАнализ числа %d:\n", number);
    if(number % 2 == 0)
        printf("- Четное\n");
    else
        printf("- Нечетное\n");
    if(number > 0)
        printf("- Положительное\n");
    else if(number < 0)
        printf("- Отрицательное\n");
    else
        printf("- Это ноль\n");

    if(number > 100)
        printf("- Большое число (больше 100)\n");
    
    return 0;
}