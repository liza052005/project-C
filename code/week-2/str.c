#include <stdio.h>

int main()
{
    char name[50];  // массив символов (строка)
    
    printf("Как тебя зовут? ");
    scanf("%s", name);  // %s - для строк, & НЕ НУЖНО!
    
    printf("Привет, %s!\n", name);
    printf("Добро пожаловать в мир C!\n");
    
    return 0;
}