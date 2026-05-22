#include <stdio.h>
#include <string.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    char text[100];
    char reversed[100];
    printf("Введите строку: ");
    fgets(text, sizeof(text), stdin);
    text[strlen(text)-1] = '\0';
    printf("Исходная строка: %s\n", text);
    int len = strlen(text);
    for(int i = 0; i < len; i++)
    {
        reversed[i] = text[len - 1 - i];
    }
    reversed[len] = '\0';
    printf("Перевернутая: %s\n", reversed);
    return 0;
}