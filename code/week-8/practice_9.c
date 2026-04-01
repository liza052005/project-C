#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int is_operator(char c)
{
    return (c == '+' || c == '-');
}

double calculate(char *expr)
{
    double result = 0;
    double num;
    char op = '+';
    int i = 0;
    int start;
    int first_number = 1;
    
    // Обработка первого числа (может быть со знаком)
    while(expr[i] == ' ') i++;
    
    // Если первый символ - минус, то первое число отрицательное
    if(expr[i] == '-')
    {
        op = '-';
        i++;
    }
    
    // Парсим первое число
    start = i;
    while(expr[i] != '\0' && !is_operator(expr[i]) && expr[i] != ' ')
    {
        i++;
    }
    
    char num_str[50];
    strncpy(num_str, expr + start, i - start);
    num_str[i - start] = '\0';
    result = atof(num_str);
    
    if(op == '-')
        result = -result;
    
    // Обрабатываем остальную часть выражения
    while(expr[i] != '\0')
    {
        // Пропускаем пробелы
        while(expr[i] == ' ') i++;
        
        // Если конец строки
        if(expr[i] == '\0') break;
        
        // Получаем оператор
        if(is_operator(expr[i]))
        {
            op = expr[i];
            i++;
        }
        else
        {
            printf("Ошибка: ожидался оператор\n");
            return 0;
        }
        
        // Пропускаем пробелы
        while(expr[i] == ' ') i++;
        
        // Парсим число
        start = i;
        while(expr[i] != '\0' && !is_operator(expr[i]) && expr[i] != ' ')
        {
            i++;
        }
        
        strncpy(num_str, expr + start, i - start);
        num_str[i - start] = '\0';
        num = atof(num_str);
        
        // Выполняем операцию
        if(op == '+')
            result += num;
        else if(op == '-')
            result -= num;
    }
    
    return result;
}

int main()
{
    char expression[200];
    double result;
    
    printf("Введите выражение (например: -123.5+4-456+56 или -123.5 + 4 - 456 + 56):\n");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = 0;
    
    printf("Выражение: %s\n", expression);
    
    result = calculate(expression);
    
    printf("Результат: %.2f\n", result);
    
    return 0;
}