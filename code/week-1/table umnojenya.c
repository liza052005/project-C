#include <stdio.h>

int main() {
    int n, i;
    
    printf("Для какого числа показать таблицу умножения? ");
    scanf("%d", &n);
    
    printf("Таблица умножения для %d:\n", n);
    for (i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", n, i, n * i);
    }
    
    return 0;
}