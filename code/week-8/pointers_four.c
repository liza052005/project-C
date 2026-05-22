
#include <stdio.h>
#include <windows.h>
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int number = 5;
    int *ptr = &number;
    int **ptr2ptr = &ptr;
    printf("1. number = %d\n", number);
    printf("2. Адрес number: %p\n", &number);
    printf("3. ptr хранит: %p\n", ptr);
    printf("4. *ptr = %d\n", *ptr);
    printf("5. ptr2ptr хранит: %p\n", ptr2ptr);
    printf("6. *ptr2ptr = %p (адрес ptr)\n", *ptr2ptr);
    printf("7. **ptr2ptr = %d (значение number)\n", **ptr2ptr);

    return 0;
}