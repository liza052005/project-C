#include <stdio.h>
#include <math.h>

int main() {
    double a = 1, b = -5, c = 6;  
    double D, x1, x2;
    
    D = b*b - 4*a*c;
    
    if (D > 0) {
        x1 = (-b + sqrt(D)) / (2*a);
        x2 = (-b - sqrt(D)) / (2*a);
        printf("Корни: %f и %f\n", x1, x2);
    }
    else if (D == 0) {
        x1 = -b / (2*a);
        printf("Корень: %f\n", x1);
    }
    else {
        printf("Корней нет\n");
    }
    
    return 0;
}