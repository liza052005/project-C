Модификация 1: Добавить выбор года фильтрации (ручной ввод)
        c
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
    int filter_year;

    printf("=== ФИЛЬТРАЦИЯ ЛЮДЕЙ ПО ГОДУ РОЖДЕНИЯ ===\n");
    printf("Введите год (будут отобраны люди, родившиеся ПОСЛЕ этого года): ");
    scanf("%d", &filter_year);
    getchar(); // чистим буфер

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

    int count = 0;  // счетчик найденных

    while(fgets(line, sizeof(line), input) != NULL)
    {
        // убираем перевод строки
        line[strcspn(line, "\n")] = '\0';

        // ищем последний пробел (перед годом)
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

            if(year > filter_year)
            {
                fprintf(output, "%s\n", line);
                count++;
                printf("Добавлен: %s\n", line);  // показываем на экране
            }
        }
    }

    fclose(input);
    fclose(output);

    printf("\n========================================\n");
    printf("Готово! Найдено %d человек(а).\n", count);
    printf("Результат сохранен в result.txt\n");

    return 0;
}
Модификация 2: "Студенческий стиль" (с косяками и русскими комментариями)
c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    FILE *f1, *f2;
    char stroka[200];
    char *p;
    int god, i;

    printf("Открываю файл people.txt...\n");
    f1 = fopen("people.txt", "r");

    if(f1 == NULL)
    {
        printf("Файл не найден, дурак!\n");
        return 1;
    }

    f2 = fopen("result.txt", "w");

    if(f2 == NULL)
    {
        printf("Не могу создать файл!\n");
        fclose(f1);
        return 1;
    }

    // читаем построчно
    while(fgets(stroka, 200, f1) != NULL)
    {
        // удаляем \n в конце
        for(i = 0; stroka[i] != '\0'; i++)
        {
            if(stroka[i] == '\n')
            {
                stroka[i] = '\0';
                break;
            }
        }

        // ищем последний пробел
        int pos = -1;
        for(i = 0; stroka[i] != '\0'; i++)
        {
            if(stroka[i] == ' ') pos = i;
        }

        if(pos != -1)
        {
            god = atoi(&stroka[pos+1]);

            if(god > 1980)  // тут можно поменять год
            {
                fprintf(f2, "%s\n", stroka);
                printf("%s -> сохранён\n", stroka);
            }
        }
    }

    fclose(f1);
    fclose(f2);

    printf("\nГотово! Смотри result.txt\n");
    system("pause");
    return 0;
}
Модификация 3: Добавить сортировку по году рождения
        c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

typedef struct {
    char fio[100];
    int year;
} Person;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    FILE *input, *output;
    char line[200];
    Person people[100];
    int count = 0;

    input = fopen("people.txt", "r");
    if(input == NULL)
    {
        printf("Ошибка: файл people.txt не найден!\n");
        return 1;
    }

    // читаем всех в массив
    while(fgets(line, sizeof(line), input) != NULL && count < 100)
    {
        line[strcspn(line, "\n")] = '\0';

        // ищем последний пробел
        int last_space = -1;
        for(int i = 0; line[i] != '\0'; i++)
        {
            if(line[i] == ' ') last_space = i;
        }

        if(last_space != -1)
        {
            strcpy(people[count].fio, line);
            people[count].year = atoi(&line[last_space + 1]);
            count++;
        }
    }
    fclose(input);

    // сортировка пузырьком (студенты любят)
    for(int i = 0; i < count - 1; i++)
    {
        for(int j = 0; j < count - i - 1; j++)
        {
            if(people[j].year > people[j+1].year)
            {
                Person temp = people[j];
                people[j] = people[j+1];
                people[j+1] = temp;
            }
        }
    }

    output = fopen("result.txt", "w");
    if(output == NULL)
    {
        printf("Ошибка создания result.txt!\n");
        return 1;
    }

    fprintf(output, "=== ОТСОРТИРОВАННО ПО ГОДУ ===\n\n");

    for(int i = 0; i < count; i++)
    {
        if(people[i].year > 1980)
        {
            fprintf(output, "%s\n", people[i].fio);
        }
    }

    fclose(output);

    printf("Отсортировано %d записей\n", count);
    printf("Результат в файле result.txt\n");

    return 0;
}
Модификация 4: Добавить вывод статистики
        c
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
    int total = 0;
    int filtered = 0;
    int sum_years = 0;
    int min_year = 3000, max_year = 0;

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

    fprintf(output, "=== ЛЮДИ, РОДИВШИЕСЯ ПОСЛЕ 1980 ===\n\n");

    while(fgets(line, sizeof(line), input) != NULL)
    {
        line[strcspn(line, "\n")] = '\0';
        total++;

        int len = strlen(line);
        int last_space = -1;

        for(int i = 0; i < len; i++)
        {
            if(line[i] == ' ')
                last_space = i;
        }

        if(last_space != -1)
        {
            int year = atoi(&line[last_space + 1]);
            sum_years += year;

            if(year < min_year) min_year = year;
            if(year > max_year) max_year = year;

            if(year > 1980)
            {
                fprintf(output, "%s\n", line);
                filtered++;
            }
        }
    }

    fprintf(output, "\n=== СТАТИСТИКА ===\n");
    fprintf(output, "Всего записей: %d\n", total);
    fprintf(output, "Отфильтровано: %d\n", filtered);
    fprintf(output, "Средний год рождения: %.0f\n", (double)sum_years / total);
    fprintf(output, "Самый ранний год: %d\n", min_year);
    fprintf(output, "Самый поздний год: %d\n", max_year);

    fclose(input);
    fclose(output);

    printf("\n=== РЕЗУЛЬТАТ ===\n");
    printf("Всего людей: %d\n", total);
    printf("Родившихся после 1980: %d\n", filtered);
    printf("Средний год рождения: %.0f\n", (double)sum_years / total);
    printf("Статистика сохранена в result.txt\n");

    return 0;
}
Модификация 5: Интерактивный режим (меню)
        c
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
    int filter_year;
    int choice;

    printf("=== ПРОГРАММА ДЛЯ РАБОТЫ С ФАЙЛОМ people.txt ===\n");
    printf("1 - Показать всех, кто родился после указанного года\n");
    printf("2 - Показать всех, кто родился ДО указанного года\n");
    printf("3 - Показать всех\n");
    printf("Выберите: ");
    scanf("%d", &choice);

    if(choice == 1 || choice == 2)
    {
        printf("Введите год: ");
        scanf("%d", &filter_year);
    }

    input = fopen("people.txt", "r");
    if(input == NULL)
    {
        printf("Файл people.txt не найден!\n");
        return 1;
    }

    output = fopen("result.txt", "w");
    if(output == NULL)
    {
        printf("Не могу создать result.txt!\n");
        fclose(input);
        return 1;
    }

    while(fgets(line, sizeof(line), input) != NULL)
    {
        line[strcspn(line, "\n")] = '\0';

        int last_space = -1;
        for(int i = 0; line[i] != '\0'; i++)
        {
            if(line[i] == ' ') last_space = i;
        }

        if(last_space != -1)
        {
            int year = atoi(&line[last_space + 1]);
            int write_it = 0;

            if(choice == 1 && year > filter_year) write_it = 1;
            else if(choice == 2 && year < filter_year) write_it = 1;
            else if(choice == 3) write_it = 1;

            if(write_it)
            {
                fprintf(output, "%s\n", line);
            }
        }
    }

    fclose(input);
    fclose(output);

    printf("Готово! Результат в result.txt\n");

    return 0;
}
//артем сказал
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

typedef struct {
    char surname[50];
    char name[50];
    int year;
} Person;

int compare_by_first_letter_surname(Person a, Person b)
{
    // сравниваем по первой букве фамилии
    return a.surname[0] - b.surname[0];
}

int compare_by_first_letter_name(Person a, Person b)
{
    // сравниваем по первой букве имени
    return a.name[0] - b.name[0];
}

int compare_by_year(Person a, Person b)
{
    return a.year - b.year;
}

int compare_by_surname(Person a, Person b)
{
    return strcmp(a.surname, b.surname);
}

void sort_people(Person arr[], int n, int (*cmp)(Person, Person))
{
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-1-i; j++)
            if(cmp(arr[j], arr[j+1]) > 0)
            {
                Person tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    FILE *f;
    Person people[100];
    int count = 0;
    char line[200];
    int choice;

    f = fopen("people.txt", "r");
    if(f == NULL)
    {
        printf("Файл people.txt не найден!\n");
        return 1;
    }

    while(fgets(line, 200, f) != NULL && count < 100)
    {
        line[strcspn(line, "\n")] = '\0';

        char *token = strtok(line, " ");
        if(token) strcpy(people[count].surname, token);

        token = strtok(NULL, " ");
        if(token) strcpy(people[count].name, token);

        token = strtok(NULL, " ");
        if(token) people[count].year = atoi(token);

        count++;
    }
    fclose(f);

    printf("Загружено %d человек\n\n", count);

    printf("=== ВЫБЕРИ СОРТИРОВКУ ===\n");
    printf("1. По первой букве фамилии (А-Я)\n");
    printf("2. По первой букве имени (А-Я)\n");
    printf("3. По фамилии полностью (А-Я)\n");
    printf("4. По году рождения (от старых к молодым)\n");
    printf("5. По году рождения (от молодых к старым)\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);

    Person sorted[100];
    for(int i = 0; i < count; i++)
        sorted[i] = people[i];

    switch(choice)
    {
        case 1:
            sort_people(sorted, count, compare_by_first_letter_surname);
            printf("\n=== ОТСОРТИРОВАНО ПО ПЕРВОЙ БУКВЕ ФАМИЛИИ ===\n");
            break;
        case 2:
            sort_people(sorted, count, compare_by_first_letter_name);
            printf("\n=== ОТСОРТИРОВАНО ПО ПЕРВОЙ БУКВЕ ИМЕНИ ===\n");
            break;
        case 3:
            sort_people(sorted, count, compare_by_surname);
            printf("\n=== ОТСОРТИРОВАНО ПО ФАМИЛИИ ===\n");
            break;
        case 4:
            sort_people(sorted, count, compare_by_year);
            printf("\n=== ОТСОРТИРОВАНО ПО ГОДУ (старые первые) ===\n");
            break;
        case 5:
            sort_people(sorted, count, compare_by_year);
            // реверсируем
            for(int i = 0; i < count/2; i++)
            {
                Person tmp = sorted[i];
                sorted[i] = sorted[count-1-i];
                sorted[count-1-i] = tmp;
            }
            printf("\n=== ОТСОРТИРОВАНО ПО ГОДУ (молодые первые) ===\n");
            break;
        default:
            printf("Неверный выбор!\n");
            return 1;
    }

    printf("\n%-20s %-20s %6s\n", "Фамилия", "Имя", "Год");
    printf("----------------------------------------\n");
    for(int i = 0; i < count; i++)
        printf("%-20s %-20s %6d\n", sorted[i].surname, sorted[i].name, sorted[i].year);

    // сохранение в файл
    FILE *out = fopen("sorted_result.txt", "w");
    if(out)
    {
        for(int i = 0; i < count; i++)
            fprintf(out, "%s %s %d\n", sorted[i].surname, sorted[i].name, sorted[i].year);
        fclose(out);
        printf("\nРезультат сохранен в sorted_result.txt\n");
    }

    return 0;
}
//артем сказал
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

struct Person {
    char surname[50];
    char name[50];
    int year;
};

int compare_surname_asc(struct Person a, struct Person b)
{
    return strcmp(a.surname, b.surname);  // А-Я
}

int compare_surname_desc(struct Person a, struct Person b)
{
    return strcmp(b.surname, a.surname);  // Я-А
}

int compare_name_asc(struct Person a, struct Person b)
{
    return strcmp(a.name, b.name);  // А-Я по именам
}

int compare_name_desc(struct Person a, struct Person b)
{
    return strcmp(b.name, a.name);  // Я-А по именам
}

void sort_people(struct Person arr[], int n, int (*cmp)(struct Person, struct Person))
{
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-1-i; j++)
            if(cmp(arr[j], arr[j+1]) > 0)
            {
                struct Person tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    FILE *f = fopen("people.txt", "r");
    if(f == NULL)
    {
        printf("Файл people.txt не найден!\n");
        return 1;
    }

    struct Person people[100];
    int count = 0;

    while(fscanf(f, "%s %s %d", people[count].surname, people[count].name, &people[count].year) == 3)
    {
        count++;
        if(count >= 100) break;
    }
    fclose(f);

    printf("Загружено %d записей\n\n", count);

    printf("=== ВСЕ ЗАПИСИ ===\n");
    for(int i = 0; i < count; i++)
        printf("%d. %s %s, %d\n", i+1, people[i].surname, people[i].name, people[i].year);

    int choice;
    printf("\n=== МЕНЮ СОРТИРОВКИ ===\n");
    printf("1. По фамилии (А-Я)\n");
    printf("2. По фамилии (Я-А)\n");
    printf("3. По имени (А-Я)\n");
    printf("4. По имени (Я-А)\n");
    printf("Выбери: ");
    scanf("%d", &choice);

    struct Person sorted[100];
    for(int i = 0; i < count; i++)
        sorted[i] = people[i];

    switch(choice)
    {
        case 1:
            sort_people(sorted, count, compare_surname_asc);
            printf("\n=== ОТСОРТИРОВАНО ПО ФАМИЛИИ (А-Я) ===\n");
            break;
        case 2:
            sort_people(sorted, count, compare_surname_desc);
            printf("\n=== ОТСОРТИРОВАНО ПО ФАМИЛИИ (Я-А) ===\n");
            break;
        case 3:
            sort_people(sorted, count, compare_name_asc);
            printf("\n=== ОТСОРТИРОВАНО ПО ИМЕНИ (А-Я) ===\n");
            break;
        case 4:
            sort_people(sorted, count, compare_name_desc);
            printf("\n=== ОТСОРТИРОВАНО ПО ИМЕНИ (Я-А) ===\n");
            break;
        default:
            printf("Неверный выбор!\n");
            return 1;
    }

    for(int i = 0; i < count; i++)
        printf("%d. %s %s, %d\n", i+1, sorted[i].surname, sorted[i].name, sorted[i].year);

    return 0;
}