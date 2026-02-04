#include <stdio.h>

int main()
{
    int choice;
    float temp, result;
    char again;
    
    do
    {
        /* Меню */
        printf("\n=== КОНВЕРТЕР ТЕМПЕРАТУР ===\n");
        printf("1. Цельсий -> Фаренгейт\n");
        printf("2. Фаренгейт -> Цельсий\n");
        printf("Выберите операцию (1 или 2): ");
        scanf("%d", &choice);
        
        /* Ввод температуры */
        if(choice == 1)
        {
            printf("Введите температуру в Цельсиях: ");
            scanf("%f", &temp);
            result = temp * 9.0 / 5.0 + 32.0;
            printf("Результат: %.2f°C = %.2f°F\n", temp, result);
        }
        else if(choice == 2)
        {
            printf("Введите температуру в Фаренгейтах: ");
            scanf("%f", &temp);
            result = (temp - 32.0) * 5.0 / 9.0;
            printf("Результат: %.2f°F = %.2f°C\n", temp, result);
        }
        else
        {
            printf("Ошибка! Выберите 1 или 2\n");
        }
        
        /* Повторить? */
        printf("\nЕще раз? (y/n): ");
        scanf(" %c", &again); /* Пробел перед %c важен! */
        
    } while(again == 'y' || again == 'Y');
    
    printf("\nДо свидания!\n");
    return 0;
}