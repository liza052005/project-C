Модификация 1: Добавить вывод в файл результата сортировки
c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

struct Person {
    char name[50];
    char surname[50];
    int year;
    char gender;
    float height;
};

int read_data(struct Person persons[], int max_count)
{
    FILE *file;
    int count = 0;
    file = fopen("people.txt", "r");
    if(file == NULL)
    {
        printf("Ошибка: файл people.txt не найден!\n");
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

void save_to_file(struct Person persons[], int count, char *filename, char *sort_type)
{
    FILE *f = fopen(filename, "w");
    if(f == NULL)
    {
        printf("Не удалось создать файл %s\n", filename);
        return;
    }

    fprintf(f, "=== ОТСОРТИРОВАНО ПО %s ===\n\n", sort_type);
    fprintf(f, "%-15s %-15s %6s %6s %8s\n",
            "Фамилия", "Имя", "Год", "Пол", "Рост(м)");

    for(int i = 0; i < count; i++)
    {
        fprintf(f, "%-15s %-15s %6d %6c %8.2f\n",
                persons[i].surname,
                persons[i].name,
                persons[i].year,
                persons[i].gender,
                persons[i].height);
    }

    fclose(f);
    printf("Результат сохранен в %s\n", filename);
}

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

void print_persons(struct Person persons[], int count)
{
    printf("\n%-15s %-15s %6s %6s %8s\n",
           "Фамилия", "Имя", "Год", "Пол", "Рост(м)");
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
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    struct Person persons[100];
    struct Person sorted[100];
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

        // копируем оригинал
        for(int i = 0; i < count; i++)
            sorted[i] = persons[i];

        switch(choice)
        {
            case 1:
                sort_persons(sorted, count, compare_by_year);
                print_persons(sorted, count);
                save_to_file(sorted, count, "sorted_by_year.txt", "ГОДУ");
                break;
            case 2:
                sort_persons(sorted, count, compare_by_surname);
                print_persons(sorted, count);
                save_to_file(sorted, count, "sorted_by_surname.txt", "ФАМИЛИИ");
                break;
            case 3:
                sort_persons(sorted, count, compare_by_name);
                print_persons(sorted, count);
                save_to_file(sorted, count, "sorted_by_name.txt", "ИМЕНИ");
                break;
            case 4:
                sort_persons(sorted, count, compare_by_gender);
                print_persons(sorted, count);
                save_to_file(sorted, count, "sorted_by_gender.txt", "ПОЛУ");
                break;
            case 5:
                sort_persons(sorted, count, compare_by_height);
                print_persons(sorted, count);
                save_to_file(sorted, count, "sorted_by_height.txt", "РОСТУ");
                break;
            case 6:
                printf("До свидания!\n");
                return 0;
            default:
                printf("Неверный выбор!\n");
        }
    }
}
Модификация 2: "Студенческий стиль" (с косяками и комментариями)
c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

// структура для человека
struct Person {
    char name[50];
    char surname[50];
    int year;
    char gender;   // M или F
    float height;  // в метрах
};

// функция чтения из файла
int read_data(struct Person persons[], int max_count)
{
    FILE *f;
    int n = 0;

    f = fopen("people.txt", "r");
    if(f == NULL)
    {
        printf("Ошибка: нет файла people.txt!\n");
        return 0;
    }

    // читаем пока хватает места
    while(fscanf(f, "%s %s %d %c %f",
                 persons[n].surname,
                 persons[n].name,
                 &persons[n].year,
                 &persons[n].gender,
                 &persons[n].height) == 5)
    {
        n++;
        if(n >= max_count) break;
    }

    fclose(f);
    return n;
}

// функции сравнения (для сортировки)
int cmp_year(struct Person a, struct Person b)
{
    return a.year - b.year;
}

int cmp_surname(struct Person a, struct Person b)
{
    return strcmp(a.surname, b.surname);
}

int cmp_name(struct Person a, struct Person b)
{
    return strcmp(a.name, b.name);
}

int cmp_gender(struct Person a, struct Person b)
{
    if(a.gender == b.gender) return 0;
    if(a.gender == 'F') return -1;  // женщины сначала (чтоб препод улыбнулся)
    return 1;
}

int cmp_height(struct Person a, struct Person b)
{
    if(a.height < b.height) return -1;
    if(a.height > b.height) return 1;
    return 0;
}

// универсальная сортировка
void sort_it(struct Person arr[], int n, int (*cmp)(struct Person, struct Person))
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-1-i; j++)
        {
            if(cmp(arr[j], arr[j+1]) > 0)
            {
                struct Person tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

// вывод на экран
void show(struct Person arr[], int n)
{
    printf("\n================================================================\n");
    printf("%-15s %-15s %6s %6s %8s\n",
           "Фамилия", "Имя", "Год", "Пол", "Рост(м)");
    printf("================================================================\n");

    for(int i = 0; i < n; i++)
    {
        printf("%-15s %-15s %6d %6c %8.2f\n",
               arr[i].surname,
               arr[i].name,
               arr[i].year,
               arr[i].gender,
               arr[i].height);
    }
    printf("================================================================\n");
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    struct Person people[100];
    struct Person copy[100];
    int cnt, choice;

    cnt = read_data(people, 100);

    if(cnt == 0)
    {
        printf("Нет данных! Проверь файл people.txt\n");
        return 1;
    }

    printf("Загружено %d человек\n", cnt);
    show(people, cnt);

    do
    {
        printf("\n=== МЕНЮ СОРТИРОВКИ ===\n");
        printf("1) По году рождения\n");
        printf("2) По фамилии\n");
        printf("3) По имени\n");
        printf("4) По полу\n");
        printf("5) По росту\n");
        printf("0) Выйти\n");
        printf("Твой выбор: ");
        scanf("%d", &choice);

        if(choice == 0) break;

        // копируем
        for(int i = 0; i < cnt; i++)
            copy[i] = people[i];

        switch(choice)
        {
            case 1:
                sort_it(copy, cnt, cmp_year);
                printf("\n=== ОТСОРТИРОВАНО ПО ГОДУ ===\n");
                break;
            case 2:
                sort_it(copy, cnt, cmp_surname);
                printf("\n=== ОТСОРТИРОВАНО ПО ФАМИЛИИ ===\n");
                break;
            case 3:
                sort_it(copy, cnt, cmp_name);
                printf("\n=== ОТСОРТИРОВАНО ПО ИМЕНИ ===\n");
                break;
            case 4:
                sort_it(copy, cnt, cmp_gender);
                printf("\n=== ОТСОРТИРОВАНО ПО ПОЛУ (F сначала) ===\n");
                break;
            case 5:
                sort_it(copy, cnt, cmp_height);
                printf("\n=== ОТСОРТИРОВАНО ПО РОСТУ ===\n");
                break;
            default:
                printf("Не понял, попробуй ещё\n");
                continue;
        }

        show(copy, cnt);

    } while(choice != 0);

    printf("Пока!\n");
    return 0;
}
Модификация 3: Добавить фильтрацию (поиск по критериям)
        c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

struct Person {
    char name[50];
    char surname[50];
    int year;
    char gender;
    float height;
};

// ... (предыдущие функции read_data, sort_persons, print_persons остаются) ...

        void filter_by_gender(struct Person persons[], int count, char gender)
{
    printf("\n=== ЖЕНЩИНЫ (пол F) ===\n");
    printf("%-15s %-15s %6s %6s %8s\n",
           "Фамилия", "Имя", "Год", "Пол", "Рост(м)");

    for(int i = 0; i < count; i++)
    {
        if(persons[i].gender == gender)
        {
            printf("%-15s %-15s %6d %6c %8.2f\n",
                   persons[i].surname,
                   persons[i].name,
                   persons[i].year,
                   persons[i].gender,
                   persons[i].height);
        }
    }
}

void filter_by_height(struct Person persons[], int count, float min_h, float max_h)
{
    printf("\n=== ЛЮДИ С РОСТОМ ОТ %.1f ДО %.1f ===\n", min_h, max_h);
    printf("%-15s %-15s %6s %6s %8s\n",
           "Фамилия", "Имя", "Год", "Пол", "Рост(м)");

    for(int i = 0; i < count; i++)
    {
        if(persons[i].height >= min_h && persons[i].height <= max_h)
        {
            printf("%-15s %-15s %6d %6c %8.2f\n",
                   persons[i].surname,
                   persons[i].name,
                   persons[i].year,
                   persons[i].gender,
                   persons[i].height);
        }
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    struct Person persons[100];
    struct Person sorted[100];
    int count, choice;
    int subchoice;

    count = read_data(persons, 100);

    if(count == 0)
    {
        printf("Нет данных!\n");
        return 1;
    }

    printf("Загружено %d записей\n\n", count);
    print_persons(persons, count);

    while(1)
    {
        printf("\n=== ГЛАВНОЕ МЕНЮ ===\n");
        printf("1. Сортировка\n");
        printf("2. Фильтрация\n");
        printf("3. Выход\n");
        printf("Выбор: ");
        scanf("%d", &choice);

        if(choice == 3) break;

        if(choice == 1)
        {
            printf("\n1. По году\n2. По фамилии\n3. По имени\n4. По полу\n5. По росту\nВыбор: ");
            scanf("%d", &subchoice);

            for(int i = 0; i < count; i++)
                sorted[i] = persons[i];

            switch(subchoice)
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
                default:
                    printf("Неверно!\n");
            }
        }
        else if(choice == 2)
        {
            printf("\n1. Только женщины\n2. Только мужчины\n3. По диапазону роста\nВыбор: ");
            scanf("%d", &subchoice);

            if(subchoice == 1)
                filter_by_gender(persons, count, 'F');
            else if(subchoice == 2)
                filter_by_gender(persons, count, 'M');
            else if(subchoice == 3)
            {
                float min_h, max_h;
                printf("Мин. рост: ");
                scanf("%f", &min_h);
                printf("Макс. рост: ");
                scanf("%f", &max_h);
                filter_by_height(persons, count, min_h, max_h);
            }
        }
    }

    printf("До свидания!\n");
    return 0;
}
//артем сказал
// добавить в matrix_ops.c или в основной файл
int compare_by_surname_desc(struct Person a, struct Person b)
{
    return strcmp(b.surname, a.surname);  // обратный порядок
}

int compare_by_name_desc(struct Person a, struct Person b)
{
    return strcmp(b.name, a.name);
}