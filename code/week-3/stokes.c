#include <stdio.h>

int main()
{
    char name[50];
    char city[50];
    
    printf("Введите ваше имя: ");
    scanf("%s", name); 
     // %s для строк, & НЕ НУЖНО!
    
    printf("Введите ваш город: ");
    scanf("%s", city);
    
    printf("\nПривет, %s из города %s!\n", name, city);
    printf("Добро пожаловать в мир строк в C!\n");
    
    return 0;
}


#include <stdio.h>
#include <string.h> 
 // для strcmp

int main()
{
    char password[50] = "secret123";
    char input[50];
    int attempts = 3;
    
    while(attempts > 0)
    {
        printf("Введите пароль (осталось %d попыток): ", attempts);
        scanf("%s", input);
        
        // strcmp возвращает 0 если строки равны
        if(strcmp(input, password) == 0)
        {
            printf("Доступ разрешен!\n");
            return 0;
        }
        else
        {
            printf("Неверный пароль!\n");
            attempts--;
        }
    }
    
    printf("Доступ заблокирован!\n");
    return 1;
}
#include <stdio.h>
#include <string.h>

int count_words(char str[])
{
    int count = 0;
    int i = 0;
    int in_word = 0;  // флаг: находимся ли мы внутри слова
    
    while(str[i] != '\0')
    {
        if(str[i] != ' ' && in_word == 0)
        {
            // Начало нового слова
            count++;
            in_word = 1;
        }
        else if(str[i] == ' ')
        {
            // Пробел - вышли из слова
            in_word = 0;
        }
        i++;
    }
    
    return count;
}

int main()
{
    char text[200];
    
    printf("Введите предложение: ");
    fgets(text, sizeof(text), stdin);  // читает с пробелами
    
    // fgets оставляет \n в конце, убираем его
    text[strlen(text)-1] = '\0';
    
    printf("Количество слов: %d\n", count_words(text));
    
    return 0;
}
#include <stdio.h>
#include <string.h>

void reverse_string(char str[])
{
    int length = strlen(str);
    int i, j;
    char temp;
    
    i = 0;            // первый символ
    j = length - 1;   // последний символ (без '\0')
    
    while(i < j)
    {
        // меняем местами символы
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        
        i++;
        j--;
    }
}

int main()
{
    char text[100];
    
    printf("Введите строку: ");
    fgets(text, sizeof(text), stdin);
    
    // Убираем \n из конца
    text[strlen(text)-1] = '\0';
    
    printf("Исходная строка: %s\n", text);
    
    reverse_string(text);
    
    printf("Перевернутая: %s\n", text);
    
    return 0;
}
#include <stdio.h>
#include <string.h>

void analyze_string(char str[])
{
    int length = strlen(str);
    int words = 1;  // минимум одно слово
    int letters = 0;
    int digits = 0;
    int spaces = 0;
    int i;
    
    for(i = 0; i < length; i++)
    {
        if(str[i] == ' ')
        {
            spaces++;
            words++;  // пробел = новое слово
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
    char text[200];
    
    printf("Введите строку для анализа: ");
    fgets(text, sizeof(text), stdin);
    
    // Убираем \n
    text[strlen(text)-1] = '\0';
    
    analyze_string(text);
    
    return 0;
}