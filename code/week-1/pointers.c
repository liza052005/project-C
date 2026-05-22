#include <stdio.h>

int main()
{
    int number = 42;
    int *ptr;
    ptr = &number;
    printf("1. Значение number: %d\n", number);
    printf("2. Адрес number: %p\n", &number);
    printf("3. Значение ptr (адрес в памяти): %p\n", ptr);
    printf("4. Что лежит по адресу в ptr: %d\n", *ptr);
    return 0;
}
#include <stdio.h>

int main()
{
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
#include <stdio.h>

int main()
{
    int value = 10;
    int *pointer = &value;
    printf("До изменения: value = %d\n", value);
    *pointer = 50;
    printf("После изменения: value = %d\n", value);
    printf("Через указатель: *pointer = %d\n", *pointer);
    
    return 0;
}
#include <stdio.h>
int main()
{
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

#include <stdio.h>
void change_value(int *p)
{
    *p = 999;
}

int main()
{
    int num = 10;
    printf("До вызова функции: num = %d\n", num);
    change_value(&num);
    printf("После вызова функции: num = %d\n", num);
    
    return 0;
}