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
#include <stdio.h>

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr;
    
    ptr = arr;  // то же самое что ptr = &arr[0]
    
    printf("=== МАССИВ И УКАЗАТЕЛИ ===\n");
    printf("arr[0] = %d\n", arr[0]);
    printf("*arr = %d\n", *arr);
    printf("ptr = %p, arr = %p\n", ptr, arr);
    
    printf("\n=== ДОСТУП К ЭЛЕМЕНТАМ ===\n");
    printf("arr[2] = %d\n", arr[2]);
    printf("*(arr + 2) = %d\n", *(arr + 2));
    printf("*(ptr + 2) = %d\n", *(ptr + 2));
    printf("ptr[2] = %d\n", ptr[2]);
    
    printf("\n=== АДРЕСА ===\n");
    printf("&arr[2] = %p\n", &arr[2]);
    printf("arr + 2 = %p\n", arr + 2);
    printf("ptr + 2 = %p\n", ptr + 2);
    
    return 0;
}