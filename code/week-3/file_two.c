#include <stdio.h>
#include <windows.h>
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    FILE *file;
    char line[200];
    file = fopen("treni.txt", "r");

    if(file == NULL)
    {
        printf("Файл не найден!\n");
        return 1;
    }

    printf("Содержимое файла:\n");
    while(fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);
    }

    fclose(file);
    return 0;
}
