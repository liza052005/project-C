#include <stdio.h>

int main()
{
    int number = 42;
    int *ptr;  // указатель на int
    
    ptr = &number;  // ptr теперь хранит адрес number
    
    printf("1. Значение number: %d\n", number);
    printf("2. Адрес number: %p\n", &number);
    printf("3. Значение ptr (адрес в памяти): %p\n", ptr);
    printf("4. Что лежит по адресу в ptr: %d\n", *ptr);
    
    return 0;
}