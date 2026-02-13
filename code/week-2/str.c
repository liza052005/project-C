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
#include <stdio.h>

// Своя функция сравнения строк
// Возвращает 0 - если строки равны
// Возвращает 1 - если не равны
int my_strcmp(char str1[], char str2[])
{
    int i = 0;
    
    while(str1[i] != '\0' && str2[i] != '\0')
    {
        if(str1[i] != str2[i])
            return 1;  // символы не совпали
        i++;
    }
    
    // Проверяем, обе ли строки закончились
    if(str1[i] == '\0' && str2[i] == '\0')
        return 0;      // строки равны
    else
        return 1;      // разная длина
}

int main()
{
    char pass[50] = "secret";
    char input[50];
    
    printf("Введите пароль: ");
    scanf("%s", input);
    
    if(my_strcmp(pass, input) == 0)
        printf("Доступ разрешен!\n");
    else
        printf("Неверный пароль!\n");
    
    return 0;
}