#include <stdio.h>
#include <math.h>

int main() {
    double a = 1, b = -5, c = 6;
    double D;
    
    D = pow(b, 2) - 4*a*c;  
    
    if (D > 0) {
        printf("x1=%.2f\n", (-b + sqrt(D))/(2*a));
        printf("x2=%.2f\n", (-b - sqrt(D))/(2*a));
    }
    else if (D == 0) {
        printf("x=%.2f\n", -b/(2*a));
    }
    else {
        printf("Нет корней\n");
    }
    
    return 0;
}