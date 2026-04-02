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
    
    printf("Введите числа через пробел: ");
    fgets(input, sizeof(input), stdin);
    
    // Убираем символ новой строки
    input[strcspn(input, "\n")] = 0;
    
    // Разбиваем строку по пробелам
    token = strtok(input, " ");
    
    while(token != NULL)
    {
        // Преобразуем строку в число
        numbers[count] = atof(token);
        count++;
        token = strtok(NULL, " ");
    }
    
    printf("Введено чисел: %d\n", count);
    
    // Выводим все числа
    printf("Числа: ");
    for(int i = 0; i < count; i++)
    {
        printf("%.2f ", numbers[i]);
    }
    printf("\n");
    
    // Здесь будем использовать макрос
    
    return 0;
}