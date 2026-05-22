
#include <stdio.h>
#include <string.h>
#include <windows.h>
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    char password[50] = "secret123";
    char input[50];
    int attempts = 3;

    while(attempts > 0)
    {
        printf("Введите пароль (осталось %d попыток): ", attempts);
        scanf("%s", input);

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
