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
#include <stdio.h>

// Своя функция подсчета длины строки
int my_strlen(char str[])
{
    int length = 0;
    
    while(str[length] != '\0')  // пока не встретим '\0'
    {
        length++;
    }
    
    return length;
}

int main()
{
    char word[100];
    
    printf("Введите слово: ");
    scanf("%s", word);
    
    printf("Длина строки: %d\n", my_strlen(word));
    printf("(Проверка: sizeof = %lu)\n", sizeof(word));
    
    return 0;
}
#include <stdio.h>

// Своя функция копирования строки
void my_strcpy(char dest[], char src[])
{
    int i = 0;
    
    while(src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';  // обязательно добавить нуль-символ!
}

int main()
{
    char source[100] = "Привет, мир!";
    char destination[100];
    
    my_strcpy(destination, source);
    
    printf("Исходная строка: %s\n", source);
    printf("Скопированная: %s\n", destination);
    
    return 0;
}