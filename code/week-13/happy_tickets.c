#include <stdio.h>

int main() {
    int count = 0;
    for (int num = 0; num <= 999999; num++) {
        int a = (num / 100000) % 10; 
        int b = (num / 10000) % 10;  
        int c = (num / 1000) % 10; 
        int d = (num / 100) % 10;    
        int e = (num / 10) % 10;   
        int f = num % 10;     
        int sum1 = a + b + c;
        int sum2 = d + e + f;
        if (sum1 == sum2) {
            count++;
        }
    }
    printf("Количество счастливых билетов: %d\n", count);
    return 0;
}