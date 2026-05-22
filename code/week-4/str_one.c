#include <stdio.h>
#include <windows.h>
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    char name[50];
    printf("Как тебя зовут?");
    scanf("%s", name);
    printf("Привет, %s!\n", name);
    printf("Добро пожаловать в мир C!\n");

    return 0;
}