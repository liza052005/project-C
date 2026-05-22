
#include <stdio.h>
#include <windows.h>
int my_strlen(char str[])
{
    int length = 0;
    while(str[length] != '\0')
    {
        length++;
    }
    return length;
}
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    char word[100];
    printf("Введите слово: ");
    scanf("%s", word);
    printf("Длина строки: %d\n", my_strlen(word));
    return 0;
}