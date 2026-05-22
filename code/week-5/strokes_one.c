#include <stdio.h>
#include <windows.h>
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    char name[50];
    char city[50];

    printf("Введите ваше имя: ");
    scanf("%s", name);

    printf("Введите ваш город: ");
    scanf("%s", city);
    printf("\nПривет, %s из города %s!\n", name, city);
    return 0;
}
