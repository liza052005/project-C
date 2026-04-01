#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char expression[200];
    double result;
    
    printf("Введите выражение (например: -123.5 + 4 - 456+56): ");
    fgets(expression, sizeof(expression), stdin);
    
    // Убираем символ новой строки
    expression[strcspn(expression, "\n")] = 0;
    
    printf("Выражение: %s\n", expression);
    
    return 0;
}