#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    FILE *input, *output;
    char line[200];
    input = fopen("people.txt", "r");
    if(input == NULL)
    {
        printf("Ошибка: файл people.txt не найден!\n");
        return 1;
    }
    output = fopen("result.txt", "w");
    if(output == NULL)
    {
        printf("Ошибка создания файла result.txt!\n");
        fclose(input);
        return 1;
    }
    while(fgets(line, sizeof(line), input) != NULL)
    {
        line[strcspn(line, "\n")] = 0;
        
        int len = strlen(line);
        int last_space = -1;
        
        for(int i = 0; i < len; i++)
        {
            if(line[i] == ' ')
                last_space = i;
        }
        
        if(last_space != -1)
        {
            char year_str[10];
            strcpy(year_str, &line[last_space + 1]);
            int year = atoi(year_str);
            
            if(year > 1980)
            {
                fprintf(output, "%s\n", line);
            }

        }
    }
    
    fclose(input);
    fclose(output);
    
    printf("Готово! Люди, родившиеся после 1980 года, сохранены в result.txt\n");
    
    return 0;
}