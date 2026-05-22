#include <stdio.h>
#include <windows.h>
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int value = 10;
    int *pointer = &value;
    printf("До изменения: value = %d\n", value);
    *pointer = 50;
    printf("После изменения: value = %d\n", value);
    printf("Через указатель: *pointer = %d\n", *pointer);

    return 0;
}