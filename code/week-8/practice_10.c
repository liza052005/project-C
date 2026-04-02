#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Макрос для поиска максимального числа в массиве
#define MAX_IN_ARRAY(arr, n) ({ \
    double max = (arr)[0]; \
    for(int i = 1; i < (n); i++) { \
        if((arr)[i] > max) max = (arr)[i]; \
    } \
    max; \
})

int main()
{
    char input[200];
    double numbers[100];
    int count = 0;
    char *token;
    double max_value;
    
    printf("Введите числа через пробел: ");
    fgets(input, sizeof(input), stdin);
    
    // Убираем символ новой строки
    input[strcspn(input, "\n")] = 0;
    
    // Разбиваем строку по пробелам и заполняем массив
    token = strtok(input, " ");
    while(token != NULL)
    {
        numbers[count] = atof(token);
        count++;
        token = strtok(NULL, " ");
    }
    
    // Проверка, что есть числа
    if(count == 0)
    {
        printf("Ошибка: не введено ни одного числа!\n");
        return 1;
    }
    
    // Выводим все числа
    printf("\nВведенные числа: ");
    for(int i = 0; i < count; i++)
    {
        printf("%.2f ", numbers[i]);
    }
    printf("\n");
    
    // Используем макрос для поиска максимума
    max_value = MAX_IN_ARRAY(numbers, count);
    
    printf("\nМаксимальное число: %.2f\n", max_value);
    
    return 0;
}