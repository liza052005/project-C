#include <stdio.h>

int main()
{
    char name[50];
    char city[50];
    
    printf("Введите ваше имя: ");
    scanf("%s", name);  // %s для строк, & НЕ НУЖНО!
    
    printf("Введите ваш город: ");
    scanf("%s", city);
    
    printf("\nПривет, %s из города %s!\n", name, city);
    printf("Добро пожаловать в мир строк в C!\n");
    
    return 0;
}

#include <stdio.h>

int count_letters(char str[])
{
    int count = 0;
    int i = 0;
    
    while(str[i] != '\0')
    {
        if(str[i] != ' ')
            count++;
        i++;
    }
    return count;
}

int main()
{
    char text[100];
    
    printf("Введите строку (с пробелами): ");
    gets(text);  // НЕ БЕЗОПАСНО! Только для примера
    
    printf("Количество букв: %d\n", count_letters(text));
    
    return 0;
}
#include <stdio.h>
#include <string.h>  // для strcmp

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