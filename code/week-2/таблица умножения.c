#include <stdio.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int n, i;

    printf("Введите число от 1 до 10: ");
    scanf("%d", &n);
    if(n < 1 || n > 10)
    {
        printf("Ошибка! Число должно быть от 1 до 10\n");
        return 1;
    }
    for(i = 1; i <= 10; i = i + 1)
    {
        printf("%d x %d = %d\n", i, n, i * n);
    }
    return 0;
}