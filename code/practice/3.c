#include <stdio.h>
#include <string.h>
#include <ctype.h>  // Для toupper()
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    char s[81];
    printf("Введите строку до 80 символов:\n");
    if (fgets(s, sizeof(s), stdin) == NULL) {
        printf("Ошибка ввода!\n");
        return 1;
    }
    s[strcspn(s, "\n")] = '\0';

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == 'a' || s[i] == 'b')
        {
            s[i] = toupper(s[i]);
        }
        else if (s[i] == 'а' || s[i] == 'б')
        {
            s[i] = s[i] - 32;
        }
    }
    printf("Result: %s\n", s);
    return 0;
}