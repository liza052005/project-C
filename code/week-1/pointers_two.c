#include <stdio.h>
#include <windows.h>
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int x = 100;
    int *ptr1, *ptr2;

    ptr1 = &x;
    ptr2 = &x;
    printf("1. x = %d\n", x);
    printf("2. *ptr1 = %d\n", *ptr1);
    printf("3. *ptr2 = %d\n", *ptr2);
    *ptr1 = 200;
    printf("\nПосле изменения через ptr1:\n");
    printf("4. x = %d\n", x);
    printf("5. *ptr1 = %d\n", *ptr1);
    printf("6. *ptr2 = %d\n", *ptr2);

    return 0;
}