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
#include <stdio.h>

int main()
{
    int x = 10;
    int *ptr1 = &x;      // указатель на int
    int **ptr2 = &ptr1;  // указатель на указатель на int
    int ***ptr3 = &ptr2; // указатель на указатель на указатель на int
    
    printf("x = %d\n", x);
    printf("&x = %p\n", &x);
    
    printf("\n=== УРОВЕНЬ 1 ===\n");
    printf("ptr1 = %p (адрес x)\n", ptr1);
    printf("*ptr1 = %d (значение x)\n", *ptr1);
    
    printf("\n=== УРОВЕНЬ 2 ===\n");
    printf("ptr2 = %p (адрес ptr1)\n", ptr2);
    printf("*ptr2 = %p (значение ptr1 - адрес x)\n", *ptr2);
    printf("**ptr2 = %d (значение x)\n", **ptr2);
    
    printf("\n=== УРОВЕНЬ 3 ===\n");
    printf("ptr3 = %p (адрес ptr2)\n", ptr3);
    printf("*ptr3 = %p (значение ptr2 - адрес ptr1)\n", *ptr3);
    printf("**ptr3 = %p (значение ptr1 - адрес x)\n", **ptr3);
    printf("***ptr3 = %d (значение x)\n", ***ptr3);
    
    return 0;
}
#include <stdio.h>

// НЕПРАВИЛЬНО: передача по значению
void bad_swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    printf("Внутри функции: a=%d, b=%d\n", a, b);
}

// ПРАВИЛЬНО: передача по ссылке (через указатели)
void good_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int x = 5, y = 10;
    
    printf("До swap: x=%d, y=%d\n", x, y);
    
    // Пытаемся поменять (НЕ РАБОТАЕТ)
    bad_swap(x, y);
    printf("После bad_swap: x=%d, y=%d (не изменились!)\n", x, y);
    
    // Правильный swap (РАБОТАЕТ)
    good_swap(&x, &y);
    printf("После good_swap: x=%d, y=%d (поменялись!)\n", x, y);
    
    return 0;
}