
#include <stdio.h>
#include <string.h>
#include <windows.h>

void analyze_string(char str[])
{
    int length = strlen(str);
    int words = 1;
    int letters = 0;
    int digits = 0;
    int spaces = 0;
    int i;
    
    for(i = 0; i < length; i++)
    {
        if(str[i] == ' ')
        {
            spaces++;
            words++;
        }
        else if((str[i] >= 'a' && str[i] <= 'z') || 
                (str[i] >= 'A' && str[i] <= 'Z'))
        {
            letters++;
        }
        else if(str[i] >= '0' && str[i] <= '9')
        {
            digits++;
        }
    }
    printf("\n=== АНАЛИЗ СТРОКИ ===\n");
    printf("Строка: %s\n", str);
    printf("Длина: %d\n", length);
    printf("Слов: %d\n", words);
    printf("Букв: %d\n", letters);
    printf("Цифр: %d\n", digits);
    printf("Пробелов: %d\n", spaces);
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    char text[200];
    printf("Введите строку для анализа: ");
    fgets(text, sizeof(text), stdin);
    // Убираем \n
    text[strlen(text)-1] = '\0';
    analyze_string(text);
    return 0;
}