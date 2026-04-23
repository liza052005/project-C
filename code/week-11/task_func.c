#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 18 + 3; // от 3 до 20
    }
}
int main() {
    srand(time(0));
    int buildings[7];
    fillArray(buildings, 7);
    for (int i = 0; i < 7; i++) {
        printf("Здание %d: %d этажей\n", i+1, buildings[i]);
    }
    return 0;
}