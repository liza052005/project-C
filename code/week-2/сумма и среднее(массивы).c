#include <stdio.h>

int main()
{
    float numbers[5]; /* Массив на 5 чисел */
    float sum = 0, average;
    float max;
    int i = 0;
    
    /* Ввод 5 чисел */
    printf("Введите 5 чисел:\n");
    
    while(i < 5)
    {
        printf("Число %d: ", i + 1);
        scanf("%f", &numbers[i]);
        i = i + 1;
    }
    
    /* Вычисление суммы */
    sum = 0;
    for(i = 0; i < 5; i++)
    {
        sum = sum + numbers[i];
    }
    
    /* Вычисление среднего */
    average = sum / 5;
    
    /* Поиск максимального */
    max = numbers[0]; /* Предполагаем, что первое - максимальное */
    for(i = 1; i < 5; i++)
    {
        if(numbers[i] > max)
        {
            max = numbers[i];
        }
    }
    
    /* Вывод результатов */
    printf("\n=== РЕЗУЛЬТАТЫ ===\n");
    
    /* Вывод всех чисел */
    printf("Введенные числа: ");
    for(i = 0; i < 5; i++)
    {
        printf("%.2f ", numbers[i]);
    }
    printf("\n");
    
    printf("Сумма: %.2f\n", sum);
    printf("Среднее: %.2f\n", average);
    printf("Максимальное: %.2f\n", max);
    
    return 0;
}