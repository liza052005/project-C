
#include <stdio.h>
#include <windows.h>
void my_strcpy(char dest[], char src[])
{
    int i = 0;
    while(src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    char source[100] = "Привет, мир!";
    char destination[100];
    my_strcpy(destination, source);
    printf("Исходная строка: %s\n", source);
    printf("Скопированная: %s\n", destination);
    return 0;
}