
#include <stdio.h>
#include <windows.h>
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    FILE *file;
    int numbers[] = {10, 20, 30, 40, 50};
    int i, num;
    file = fopen("treni.txt", "w");
    if(file == NULL)
    {
        printf("Ошибка!\n");
        return 1;
    }
    for(i = 0; i < 5; i++)
    {
        fprintf(file, "%d\n", numbers[i]);
    }

    fclose(file);
    printf("Массив записан в файл.\n");
    printf("\nЧтение из файла:\n");
    file = fopen("treni.txt", "r");
    while(fscanf(file, "%d", &num) == 1)
    {
        printf("Прочитано: %d\n", num);
    }
    fclose(file);
    return 0;
}