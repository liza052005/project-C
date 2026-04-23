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
#include <stdio.h>

int findBuilding(int arr[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int main() {
    int buildings[5] = {4, 7, 2, 9, 5};
    int search = 9;
    
    int index = findBuilding(buildings, 5, search);
    
    if (index != -1) {
        printf("Здание с %d этажами найдено на позиции %d\n", search, index);
    } else {
        printf("Здание с %d этажами не найдено\n", search);
    }
    return 0;
}
#include <stdio.h>

int countTall(int arr[], int n, int limit) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > limit) {
            count++;
        }
    }
    return count;
}

int main() {
    int buildings[] = {5, 12, 8, 15, 3, 10, 18};
    int limit;
    
    printf("Введите минимальное количество этажей: ");
    scanf("%d", &limit);
    
    int result = countTall(buildings, 7, limit);
    printf("Зданий выше %d этажей: %d\n", limit, result);
    
    return 0;
}
