#include <stdio.h>

int main()
{
    int number = 42;        // обычная переменная
    int *ptr;               // указатель (хранит адрес)
    
    ptr = &number;          // ptr теперь хранит адрес number
    
    printf("=== ПЕРЕМЕННАЯ ===\n");
    printf("Значение number: %d\n", number);
    printf("Адрес number: %p\n", &number);
    printf("Размер number: %lu байт\n", sizeof(number));
    
    printf("\n=== УКАЗАТЕЛЬ ===\n");
    printf("Значение ptr (адрес): %p\n", ptr);
    printf("Адрес самого ptr: %p\n", &ptr);
    printf("Размер ptr: %lu байт\n", sizeof(ptr));
    
    printf("\n=== РАЗЫМЕНОВАНИЕ ===\n");
    printf("*ptr = %d (значение по адресу)\n", *ptr);
    
    // Меняем значение через указатель
    *ptr = 100;
    printf("После *ptr = 100, number = %d\n", number);
    
    return 0;
}