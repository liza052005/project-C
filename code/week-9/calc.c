#include <stdio.h>
#include <windows.h>
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    float num1, num2;
    char operation;

    printf("Введите первое число: ");
    scanf("%f", &num1);

    printf("Введите второе число: ");
    scanf("%f", &num2);
    printf("Введите операцию : ");
    scanf(" %c", &operation);

    if(operation == '+'){
        printf("%.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
    }
    else if(operation == '-') {
        printf("%.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
    }
    else if (operation == '*'){
        printf("%.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
    }
    else if(operation == '/'){
        if (num2 != 0)
            printf("%.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
        else
            printf("Ошибка: деление на ноль!\n");
    }
    else {
        printf("Неверная операция!\n");
    }


    
    return 0;
}