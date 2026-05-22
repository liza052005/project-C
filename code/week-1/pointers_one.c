#include <stdio.h>
#include <windows.h>
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int number = 42;
    int *domik;
    domik = &number;
    printf("1. Значение number: %d\n", number);
    printf("2. Адрес number: %p\n", &number);
    printf("3. Значение domik (адрес в памяти): %p\n", domik);
    printf("4. Что лежит по адресу в domik: %d\n", *domik);
    return 0;
}