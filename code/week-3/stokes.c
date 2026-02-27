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