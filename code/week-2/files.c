#include <stdio.h>

int main()
{
    FILE *file;  // указатель на файл
    
    // Открываем файл для записи (w = write)
    file = fopen("treni.txt", "w");
    
    if(file == NULL)
    {
        printf("Ошибка открытия файла!\n");
        return 1;
    }
    
    // Записываем текст в файл
    fprintf(file, "Привет, мир!\n");
    fprintf(file, "Это мой первый файл.\n");
    fprintf(file, "Я учу C программирование.\n");
    
    // Закрываем файл
    fclose(file);
    
    printf("Файл успешно записан!\n");
    return 0;
}

#include <stdio.h>

int main()
{
    FILE *file;
    char line[200];  // буфер для строки
    
    // Открываем для чтения (r = read)
    file = fopen("treni.txt", "r");
    
    if(file == NULL)
    {
        printf("Файл не найден!\n");
        return 1;
    }
    
    printf("Содержимое файла:\n");
    printf("=================\n");
    
    // Читаем файл построчно
    while(fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);
    }
    
    fclose(file);
    return 0;
}

#include <stdio.h>

int main()
{
    FILE *file;
    int numbers[] = {10, 20, 30, 40, 50};
    int i, num;
    
    // ЗАПИСЬ
    file = fopen("treni.txt", "w");
    
    if(file == NULL)
    {
        printf("Ошибка!\n");
        return 1;
    }
    
    // Записываем каждое число в отдельной строке
    for(i = 0; i < 5; i++)
    {
        fprintf(file, "%d\n", numbers[i]);
    }
    
    fclose(file);
    printf("Массив записан в файл.\n");
    
    // ЧТЕНИЕ
    printf("\nЧтение из файла:\n");
    file = fopen("treni.txt", "r");
    
    while(fscanf(file, "%d", &num) == 1)
    {
        printf("Прочитано: %d\n", num);
    }
    
    fclose(file);
    return 0;
}

#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float grade;
};

int main()
{
    FILE *file;
    struct Student s;
    
    // Ввод данных
    printf("Введите имя студента: ");
    scanf("%s", s.name);
    printf("Введите возраст: ");
    scanf("%d", &s.age);
    printf("Введите оценку: ");
    scanf("%f", &s.grade);
    
    // Запись в файл
    file = fopen("treni.txt", "a");  // a = append (добавить)
    
    if(file == NULL)
    {
        printf("Ошибка!\n");
        return 1;
    }
    
    // Записываем данные через запятую
    fprintf(file, "%s,%d,%.1f\n", s.name, s.age, s.grade);
    
    fclose(file);
    printf("Данные сохранены!\n");
    
    return 0;
}

#include <stdio.h>
#include <string.h>  // для strcmp

struct Student {
    char name[50];
    int age;
    float grade;
};

int main()
{
    FILE *file;
    struct Student s;
    char search_name[50];
    int found = 0;
    
    printf("Введите имя для поиска: ");
    scanf("%s", search_name);
    
    file = fopen("treni.txt", "r");
    
    if(file == NULL)
    {
        printf("Файл не найден!\n");
        return 1;
    }
    
    printf("\nРезультаты поиска:\n");
    
    // Читаем построчно
    while(fscanf(file, "%49[^,],%d,%f\n", s.name, &s.age, &s.grade) == 3)
    {
        if(strcmp(s.name, search_name) == 0)
        {
            printf("Найден: %s, %d лет, оценка: %.1f\n", 
                   s.name, s.age, s.grade);
            found = 1;
        }
    }
    
    if(!found)
        printf("Студент не найден.\n");
    
    fclose(file);
    return 0;
}