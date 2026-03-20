#include <stdio.h>

int main()
{
    float num1, num2;
    
    /* Ввод чисел */
    printf("Введите первое число: ");
    scanf("%f", &num1);
    
    printf("Введите второе число: ");
    scanf("%f", &num2);
    
    /* Вычисления и вывод */
    printf("\nРезультаты:\n");
    printf("%.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
    printf("%.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
    printf("%.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
    
    /* Проверка деления на ноль */
    if(num2 != 0)
        printf("%.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
    else
        printf("Деление на ноль невозможно!\n");
    
    return 0;
}