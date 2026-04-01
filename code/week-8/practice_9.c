#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char expression[200];
    char *token;
    double result;
    int first = 1;  // флаг первого числа
    
    printf("Введите выражение (например: -123.5 + 4 - 456+56): ");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = 0;
    
    printf("Выражение: %s\n", expression);
    
    // Разбиваем строку по пробелам
    token = strtok(expression, " ");
    
    while(token != NULL)
    {
        printf("Токен: %s\n", token);
        token = strtok(NULL, " ");
    }
    
    return 0;
}