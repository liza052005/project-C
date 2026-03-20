#include <stdio.h>

main() {
    double d1, d2, d3, d4, d5, d6, d7, d8, d9;
    int n1, n2, n3, n4;
    int r1, r2, r3, r4;
    
    // Часть 1
    printf("9 чисел: ");
    scanf("%lf %lf %lf", &d1, &d2, &d3);
    scanf("%lf %lf %lf", &d4, &d5, &d6);
    scanf("%lf %lf %lf", &d7, &d8, &d9);
    
    printf("Диагональ1: %.2f\n", d1 + d5 + d9);
    printf("Диагональ2: %.2f\n", d3 + d5 + d7);
    
    // Часть 2
    printf("\n4 числа: ");
    scanf("%d %d", &n1, &n2);
    scanf("%d %d", &n3, &n4);
    
    r1 = n1*n1 + n2*n3;
    r2 = n1*n2 + n2*n4;
    r3 = n3*n1 + n4*n3;
    r4 = n3*n2 + n4*n4;
    
    printf("Квадрат:\n");
    printf("%d %d\n", r1, r2);
    printf("%d %d\n", r3, r4);
    
    return 0;
}