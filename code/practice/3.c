#include <stdio.h>
#include <string.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    char str[100];
    int i;
    printf("Введите строку: ");
    gets(str);
    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == 'a')
        {
            str[i] = 'A';
        }
        else if(str[i] == 'b')
        {
            str[i] = 'B';
        }
        else if(str[i] == 'а')
        {
            str[i] = 'А';
        }
        else if(str[i] == 'б')
        {
            str[i] = 'Б';
        }
    }
    printf("Результат: %s\n", str);
    system("pause");
}