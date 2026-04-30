#include <stdio.h>
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

void bubbleSortDesc(int arr[], int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            // Если текущий элемент МЕНЬШЕ следующего — меняем (для убывания)
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int countExcellent(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == 5) {
            count++;
        }
    }
    return count;
}
int main() {
    int grades[] = {3, 5, 2, 4, 5, 3, 4, 5, 2, 4};
    int size = sizeof(grades) / sizeof(grades[0]);
    printf("Исходный массив оценок: ");
    printArray(grades, size);

    // Подсчёт отличников в исходном массиве
    int excellentCount = countExcellent(grades, size);
    printf("Количество отличников в исходном массиве: %d\n", excellentCount);
    // Сортировка
    bubbleSortDesc(grades, size);
    printf("Отсортированный массив (по убыванию): ");
    printArray(grades, size);
    // Проверка, что количество отличников не изменилось
    excellentCount = countExcellent(grades, size);
    printf("Количество отличников после сортировки: %d\n", excellentCount);

    return 0;
}