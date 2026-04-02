#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Макрос для поиска максимального числа в массиве
#define MAX_IN_ARRAY(arr, n) ({ \
    double max = (arr)[0]; \
    for(int i = 1; i < (n); i++) { \
        if((arr)[i] > max) max = (arr)[i]; \
    } \
    max; \
})

int main()
{
    char input[200];
    double numbers[100];
    int count = 0;
    
    printf("Введите числа через пробел: ");
    fgets(input, sizeof(input), stdin);
    
    // Здесь будем парсить строку
    
    return 0;
}