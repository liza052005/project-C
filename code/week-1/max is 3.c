#include <stdio.h>

int main() {
    int a, b, c, max;
    
    printf("Введите три числа: ");
    scanf("%d %d %d", &a, &b, &c);
    
    max = a;
    
    if (b > max) {
        max = b;
    }
    
    if (c > max) {
        max = c;
    }
    
    printf("Максимальное число: %d\n", max);
    
    return 0;
}