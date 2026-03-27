#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person {
    char name[50];
    char surname[50];
    int year;
    char gender;
    float height;
};

// Функция чтения данных из файла
int read_data(struct Person persons[], int max_count)
{
    FILE *file;
    int count = 0;
    
    file = fopen("people2.txt", "r");
    if(file == NULL)
    {
        printf("Ошибка: файл people2.txt не найден!\n");
        return 0;
    }
    
    while(fscanf(file, "%s %s %d %c %f", 
                 persons[count].surname,
                 persons[count].name,
                 &persons[count].year,
                 &persons[count].gender,
                 &persons[count].height) == 5)
    {
        count++;
        if(count >= max_count) break;
    }
    
    fclose(file);
    return count;
}

// Функции сравнения
int compare_by_year(struct Person a, struct Person b)
{
    return a.year - b.year;
}

int compare_by_surname(struct Person a, struct Person b)
{
    return strcmp(a.surname, b.surname);
}

int compare_by_name(struct Person a, struct Person b)
{
    return strcmp(a.name, b.name);
}

int compare_by_gender(struct Person a, struct Person b)
{
    return a.gender - b.gender;
}

int compare_by_height(struct Person a, struct Person b)
{
    if(a.height > b.height) return 1;
    if(a.height < b.height) return -1;
    return 0;
}

// Универсальная сортировка
void sort_persons(struct Person persons[], int count, 
                  int (*compare)(struct Person, struct Person))
{
    for(int i = 0; i < count - 1; i++)
    {
        for(int j = 0; j < count - 1 - i; j++)
        {
            if(compare(persons[j], persons[j+1]) > 0)
            {
                struct Person temp = persons[j];
                persons[j] = persons[j+1];
                persons[j+1] = temp;
            }
        }
    }
}

// Вывод данных
void print_persons(struct Person persons[], int count)
{
    printf("\n%-15s %-15s %6s %6s %8s\n", 
           "Фамилия", "Имя", "Год", "Пол", "Рост(м)");
    printf("--------------------------------------------------------\n");
    
    for(int i = 0; i < count; i++)
    {
        printf("%-15s %-15s %6d %6c %8.2f\n", 
               persons[i].surname,
               persons[i].name,
               persons[i].year,
               persons[i].gender,
               persons[i].height);
    }
}

int main()
{
    struct Person persons[100];
    int count;
    int choice;
    
    count = read_data(persons, 100);
    if(count == 0)
    {
        printf("Нет данных для обработки!\n");
        return 1;
    }
    
    printf("Загружено %d записей\n", count);
    print_persons(persons, count);
    
    while(1)
    {
        printf("\n=== СОРТИРОВКА ===\n");
        printf("1. По году рождения\n");
        printf("2. По фамилии\n");
        printf("3. По имени\n");
        printf("4. По полу\n");
        printf("5. По росту\n");
        printf("6. Выход\n");
        printf("Выбор: ");
        scanf("%d", &choice);
        
        struct Person sorted[100];
        for(int i = 0; i < count; i++)
            sorted[i] = persons[i];
        
        switch(choice)
        {
            case 1:
                sort_persons(sorted, count, compare_by_year);
                print_persons(sorted, count);
                break;
            case 2:
                sort_persons(sorted, count, compare_by_surname);
                print_persons(sorted, count);
                break;
            case 3:
                sort_persons(sorted, count, compare_by_name);
                print_persons(sorted, count);
                break;
            case 4:
                sort_persons(sorted, count, compare_by_gender);
                print_persons(sorted, count);
                break;
            case 5:
                sort_persons(sorted, count, compare_by_height);
                print_persons(sorted, count);
                break;
            case 6:
                printf("До свидания!\n");
                return 0;
            default:
                printf("Неверный выбор!\n");
        }
    }
}