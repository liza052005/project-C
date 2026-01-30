#include <stdio.h>

int main() {
    float a, b;
    char op;
    
    printf("Введите пример (например: 5 + 3): ");
    scanf("%f %c %f", &a, &op, &b);
    
    if (op == '+') {
        printf("Ответ: %.2f\n", a + b);
    } else if (op == '-') {
        printf("Ответ: %.2f\n", a - b);
    } else if (op == '*') {
        printf("Ответ: %.2f\n", a * b);
    } else if (op == '/') {
        if (b != 0) {
            printf("Ответ: %.2f\n", a / b);
        } else {
            printf("Ошибка: деление на ноль!\n");
        }
    } else {
        printf("Неизвестная операция\n");
    }
    
    return 0;
}