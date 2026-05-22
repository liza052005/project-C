#include <stdio.h>
#include <windows.h>
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    FILE *file;
    file = fopen("treni.txt", "w");
    if(file == NULL)
    {
        printf("Ошибка открытия файла!\n");
        return 1;
    }
    fprintf(file, "Привет, мир!\n");
    fprintf(file, "Это мой первый файл.\n");
    fprintf(file, "Я учу C программирование.\n");
    fclose(file);
    printf("Файл успешно записан!\n");
    return 0;
}