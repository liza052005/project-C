#include <stdio.h>
#include <windows.h>
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    float numbers[5];
    float sum = 0, average;
    float max;
    int i = 0;
    printf("Введите 5 чисел:\n");
    while(i < 5)
    {
        printf("Число %d: ", i + 1);
        scanf("%f", &numbers[i]);
        i = i + 1;
    }
    sum = 0;
    for(i = 0; i < 5; i++)
    {
        sum = sum + numbers[i];
    }
    average = sum / 5;
    max = numbers[0];
    for(i = 1; i < 5; i++)
    {
        if(numbers[i] > max)
        {
            max = numbers[i];
        }
    }
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