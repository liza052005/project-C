#include <stdio.h>

int main()
{
    int number;
    
    /* Ввод числа */
    printf("Введите целое число: ");
    scanf("%d", &number);
    
    /* Проверка четности */
    printf("\nАнализ числа %d:\n", number);
    
    if(number % 2 == 0)
        printf("- Четное\n");
    else
        printf("- Нечетное\n");
    
    /* Проверка знака */
    if(number > 0)
        printf("- Положительное\n");
    else if(number < 0)
        printf("- Отрицательное\n");
    else
        printf("- Это ноль\n");
    
    /* Проверка на большое число */
    if(number > 100)
        printf("- Большое число (больше 100)\n");
    
    return 0;
}