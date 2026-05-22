


#include <stdio.h>
#include <windows.h>
void change_value(int *p)
{
    *p = 999;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int num = 10;
    printf("До вызова функции: num = %d\n", num);
    change_value(&num);
    printf("После вызова функции: num = %d\n", num);
    
    return 0;
}