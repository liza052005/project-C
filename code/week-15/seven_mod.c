Модификация 1: Добавить поиск по имени/фамилии
        c
#include <stdio.h>
#include <string.h>
#include <windows.h>

struct humen {
    char name[50];
    char surname[50];
    int year;
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    struct humen arr1[4];
    struct humen arr2[4];
    int i;

    printf("=== ВВОД ДАННЫХ О 4 ЛЮДЯХ ===\n");
    for(i = 0; i < 4; i++)
    {
        printf("\n--- Человек %d ---\n", i + 1);

        printf("Имя: ");
        scanf("%s", arr1[i].name);

        printf("Фамилию: ");
        scanf("%s", arr1[i].surname);

        printf("Год рождения: ");
        scanf("%d", &arr1[i].year);
    }

    printf("\n=== ВВЕДЕННЫЕ ДАННЫЕ ===\n");
    for(i = 0; i < 4; i++)
    {
        printf("%d. %s %s, %d г.\n",
               i + 1,
               arr1[i].name,
               arr1[i].surname,
               arr1[i].year);
    }

    // копирование
    for(i = 0; i < 4; i++)
    {
        strcpy(arr2[i].name, arr1[i].name);
        strcpy(arr2[i].surname, arr1[i].surname);
        arr2[i].year = arr1[i].year;
    }
    printf("\n=== КОПИРОВАНИЕ ВЫПОЛНЕНО ===\n");

    // сортировка по году
    for(i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3 - i; j++)
        {
            if(arr2[j].year > arr2[j+1].year)
            {
                struct humen temp = arr2[j];
                arr2[j] = arr2[j+1];
                arr2[j+1] = temp;
            }
        }
    }

    printf("\n=== ОТСОРТИРОВАННЫЕ ДАННЫЕ (по году) ===\n");
    for(i = 0; i < 4; i++)
    {
        printf("%d. %s %s, %d г.\n",
               i + 1,
               arr2[i].name,
               arr2[i].surname,
               arr2[i].year);
    }

    // ===== НОВОЕ: поиск по имени =====
    char search_name[50];
    printf("\n=== ПОИСК ПО ИМЕНИ ===\n");
    printf("Введите имя для поиска: ");
    scanf("%s", search_name);

    int found = 0;
    for(i = 0; i < 4; i++)
    {
        if(strcmp(arr1[i].name, search_name) == 0)
        {
            printf("Найден: %s %s, %d г.\n",
                   arr1[i].name,
                   arr1[i].surname,
                   arr1[i].year);
            found++;
        }
    }

    if(found == 0)
        printf("Ничего не найдено!\n");
    else
        printf("Всего найдено: %d\n", found);

    return 0;
}
Модификация 2: "Студенческий стиль" (с косяками и комментариями)
c
#include <stdio.h>
#include <string.h>
#include <windows.h>

// структура для человека (можно было и по-русски назвать)
struct humen {
    char name[50];
    char surname[50];
    int god;  // год (назвал по-русски чтоб понятнее)
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    struct humen a[4];  // первый массив
    struct humen b[4];  // второй массив (для сортировки)
    int i, j;

    printf("Введи инфу о 4 людях:\n");

    for(i = 0; i < 4; i++)
    {
        printf("\nЧеловек %d:\n", i+1);

        printf("  Имя: ");
        scanf("%s", a[i].name);

        printf("  Фамилия: ");
        scanf("%s", a[i].surname);

        printf("  Год рождения: ");
        scanf("%d", &a[i].god);
    }

    // выводим что ввели
    printf("\n=== Твои данные ===\n");
    for(i = 0; i < 4; i++)
    {
        printf("%d) %s %s, родился в %d\n",
               i+1, a[i].name, a[i].surname, a[i].god);
    }

    // копируем в b (поэлементно)
    for(i = 0; i < 4; i++)
    {
        strcpy(b[i].name, a[i].name);
        strcpy(b[i].surname, a[i].surname);
        b[i].god = a[i].god;
    }

    printf("\nСкопировали!\n");

    // сортировка пузырьком (честно списано с лекции)
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3 - i; j++)
        {
            if(b[j].god > b[j+1].god)
            {
                struct humen tmp = b[j];
                b[j] = b[j+1];
                b[j+1] = tmp;
            }
        }
    }

    // выводим отсортированное
    printf("\n=== Отсортировано по году ===\n");
    for(i = 0; i < 4; i++)
    {
        printf("%d) %s %s, %d\n",
               i+1, b[i].name, b[i].surname, b[i].god);
    }

    system("pause");
    return 0;
}
Модификация 3: Добавить возможность ввода N человек (не фиксировано 4)
c
#include <stdio.h>
#include <string.h>
#include <windows.h>

struct humen {
    char name[50];
    char surname[50];
    int year;
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    struct humen arr1[100];  // побольше размер
    struct humen arr2[100];
    int n, i;

    printf("Сколько человек будем вводить? (макс 100): ");
    scanf("%d", &n);

    if(n <= 0 || n > 100)
    {
        printf("Неверное количество!\n");
        return 1;
    }

    printf("\n=== ВВОД ДАННЫХ ===\n");
    for(i = 0; i < n; i++)
    {
        printf("\n--- Человек %d ---\n", i + 1);

        printf("Имя: ");
        scanf("%s", arr1[i].name);

        printf("Фамилию: ");
        scanf("%s", arr1[i].surname);

        printf("Год рождения: ");
        scanf("%d", &arr1[i].year);
    }

    printf("\n=== ВВЕДЕННЫЕ ДАННЫЕ ===\n");
    for(i = 0; i < n; i++)
    {
        printf("%d. %s %s, %d г.\n",
               i + 1, arr1[i].name, arr1[i].surname, arr1[i].year);
    }

    // копирование
    for(i = 0; i < n; i++)
    {
        strcpy(arr2[i].name, arr1[i].name);
        strcpy(arr2[i].surname, arr1[i].surname);
        arr2[i].year = arr1[i].year;
    }

    // сортировка
    for(i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - 1 - i; j++)
        {
            if(arr2[j].year > arr2[j+1].year)
            {
                struct humen temp = arr2[j];
                arr2[j] = arr2[j+1];
                arr2[j+1] = temp;
            }
        }
    }

    printf("\n=== ОТСОРТИРОВАННЫЕ ДАННЫЕ ===\n");
    for(i = 0; i < n; i++)
    {
        printf("%d. %s %s, %d г.\n",
               i + 1, arr2[i].name, arr2[i].surname, arr2[i].year);
    }

    return 0;
}
Модификация 4: Добавить подсчет среднего возраста и самого старшего/младшего
        c
#include <stdio.h>
#include <string.h>
#include <windows.h>

struct humen {
    char name[50];
    char surname[50];
    int year;
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    struct humen arr1[4];
    struct humen arr2[4];
    int i;
    int current_year = 2025;  // текущий год

    printf("Введите данные о 4 людях:\n");
    for(i = 0; i < 4; i++)
    {
        printf("\n--- Человек %d ---\n", i + 1);

        printf("Имя: ");
        scanf("%s", arr1[i].name);

        printf("Фамилию: ");
        scanf("%s", arr1[i].surname);

        printf("Год рождения: ");
        scanf("%d", &arr1[i].year);
    }

    printf("\n=== ВВЕДЕННЫЕ ДАННЫЕ ===\n");
    for(i = 0; i < 4; i++)
    {
        printf("%d. %s %s, %d г. (возраст: %d)\n",
               i + 1,
               arr1[i].name,
               arr1[i].surname,
               arr1[i].year,
               current_year - arr1[i].year);
    }

    // копирование
    for(i = 0; i < 4; i++)
    {
        strcpy(arr2[i].name, arr1[i].name);
        strcpy(arr2[i].surname, arr1[i].surname);
        arr2[i].year = arr1[i].year;
    }

    // сортировка
    for(i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3 - i; j++)
        {
            if(arr2[j].year > arr2[j+1].year)
            {
                struct humen temp = arr2[j];
                arr2[j] = arr2[j+1];
                arr2[j+1] = temp;
            }
        }
    }

    printf("\n=== ОТСОРТИРОВАННЫЕ (по году рождения) ===\n");
    for(i = 0; i < 4; i++)
    {
        printf("%d. %s %s, %d г.\n",
               i + 1,
               arr2[i].name,
               arr2[i].surname,
               arr2[i].year);
    }

    // статистика
    int sum_years = 0;
    int min_year = arr2[0].year;
    int max_year = arr2[3].year;

    for(i = 0; i < 4; i++)
    {
        sum_years += arr2[i].year;
    }

    printf("\n=== СТАТИСТИКА ===\n");
    printf("Самый старший: %s %s, %d г. (возраст %d)\n",
           arr2[0].name, arr2[0].surname, arr2[0].year,
           current_year - arr2[0].year);
    printf("Самый младший: %s %s, %d г. (возраст %d)\n",
           arr2[3].name, arr2[3].surname, arr2[3].year,
           current_year - arr2[3].year);
    printf("Средний год рождения: %.0f\n", (double)sum_years / 4);

    return 0;
}
Модификация 5: Добавить сохранение/загрузку из файла
        c
#include <stdio.h>
#include <string.h>
#include <windows.h>

struct humen {
    char name[50];
    char surname[50];
    int year;
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    struct humen arr1[4];
    struct humen arr2[4];
    int i;
    int mode;

    printf("1 - ввести данные с клавиатуры\n");
    printf("2 - загрузить из файла people_save.txt\n");
    printf("Выбери: ");
    scanf("%d", &mode);

    if(mode == 2)
    {
        FILE *f = fopen("people_save.txt", "r");
        if(f == NULL)
        {
            printf("Файл не найден!\n");
            return 1;
        }
        for(i = 0; i < 4; i++)
        {
            fscanf(f, "%s %s %d", arr1[i].name, arr1[i].surname, &arr1[i].year);
        }
        fclose(f);
        printf("Данные загружены!\n");
    }
    else
    {
        printf("Введите данные о 4 людях:\n");
        for(i = 0; i < 4; i++)
        {
            printf("\n--- Человек %d ---\n", i + 1);
            printf("Имя: ");
            scanf("%s", arr1[i].name);
            printf("Фамилию: ");
            scanf("%s", arr1[i].surname);
            printf("Год рождения: ");
            scanf("%d", &arr1[i].year);
        }

        // сохраняем в файл
        FILE *f = fopen("people_save.txt", "w");
        if(f != NULL)
        {
            for(i = 0; i < 4; i++)
            {
                fprintf(f, "%s %s %d\n", arr1[i].name, arr1[i].surname, arr1[i].year);
            }
            fclose(f);
            printf("\nДанные сохранены в people_save.txt\n");
        }
    }

    printf("\n=== ВВЕДЕННЫЕ ДАННЫЕ ===\n");
    for(i = 0; i < 4; i++)
    {
        printf("%d. %s %s, %d г.\n", i+1, arr1[i].name, arr1[i].surname, arr1[i].year);
    }

    // копирование
    for(i = 0; i < 4; i++)
    {
        strcpy(arr2[i].name, arr1[i].name);
        strcpy(arr2[i].surname, arr1[i].surname);
        arr2[i].year = arr1[i].year;
    }

    // сортировка
    for(i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3 - i; j++)
        {
            if(arr2[j].year > arr2[j+1].year)
            {
                struct humen temp = arr2[j];
                arr2[j] = arr2[j+1];
                arr2[j+1] = temp;
            }
        }
    }

    printf("\n=== ОТСОРТИРОВАННЫЕ ДАННЫЕ ===\n");
    for(i = 0; i < 4; i++)
    {
        printf("%d. %s %s, %d г.\n", i+1, arr2[i].name, arr2[i].surname, arr2[i].year);
    }

    return 0;
}
//артем сказал
#include <stdio.h>
#include <string.h>
#include <windows.h>

struct humen {
    char name[50];
    char surname[50];
    int year;
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    FILE *f;
    struct humen people[100];
    int n = 0;
    int i, j;

    // ПЫТАЕМСЯ ОТКРЫТЬ ФАЙЛ
    f = fopen("people.txt", "r");

    if(f == NULL)
    {
        // ФАЙЛА НЕТ - ВВОДИМ С КЛАВИАТУРЫ
        printf("Файл people.txt не найден, введи данные вручную\n");
        printf("Сколько человек? (макс 100): ");
        scanf("%d", &n);

        if(n <= 0 || n > 100)
        {
            printf("Неверно!\n");
            return 1;
        }

        for(i = 0; i < n; i++)
        {
            printf("\nЧеловек %d:\n", i+1);
            printf("  Фамилия: ");
            scanf("%s", people[i].surname);
            printf("  Имя: ");
            scanf("%s", people[i].name);
            printf("  Год: ");
            scanf("%d", &people[i].year);
        }

        // СОХРАНЯЕМ
        f = fopen("people.txt", "w");
        if(f != NULL)
        {
            for(i = 0; i < n; i++)
                fprintf(f, "%s %s %d\n", people[i].surname, people[i].name, people[i].year);
            fclose(f);
            printf("\nСохранено!\n");
        }
    }
    else
    {
        // ФАЙЛ ЕСТЬ - ЧИТАЕМ СТРОКИ
        while(fscanf(f, "%s %s %d", people[n].surname, people[n].name, &people[n].year) == 3)
        {
            n++;
            if(n >= 100) break;
        }
        fclose(f);
        printf("Из файла people.txt загружено %d записей\n", n);
    }

    if(n == 0)
    {
        printf("Нет данных!\n");
        return 1;
    }

    // ВЫВОДИМ ВСЁ
    printf("\n=== ВСЕ ЛЮДИ (%d человек) ===\n", n);
    for(i = 0; i < n; i++)
        printf("%d. %s %s, %d г.\n", i+1, people[i].surname, people[i].name, people[i].year);

    // СОРТИРУЕМ
    for(i = 0; i < n-1; i++)
        for(j = 0; j < n-1-i; j++)
            if(people[j].year > people[j+1].year)
            {
                struct humen tmp = people[j];
                people[j] = people[j+1];
                people[j+1] = tmp;
            }

    printf("\n=== ОТСОРТИРОВАНО ПО ГОДУ ===\n");
    for(i = 0; i < n; i++)
        printf("%d. %s %s, %d г.\n", i+1, people[i].surname, people[i].name, people[i].year);

    system("pause");
    return 0;
}
//артем сказал
#include <stdio.h>
#include <string.h>
#include <windows.h>

struct humen {
    char name[50];
    char surname[50];
    int year;
};

// сортировка по фамилии А-Я
void sort_by_surname_asc(struct humen arr[], int n)
{
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-1-i; j++)
            if(strcmp(arr[j].surname, arr[j+1].surname) > 0)
            {
                struct humen temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

// сортировка по фамилии Я-А
void sort_by_surname_desc(struct humen arr[], int n)
{
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-1-i; j++)
            if(strcmp(arr[j].surname, arr[j+1].surname) < 0)
            {
                struct humen temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

// сортировка по имени А-Я
void sort_by_name_asc(struct humen arr[], int n)
{
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-1-i; j++)
            if(strcmp(arr[j].name, arr[j+1].name) > 0)
            {
                struct humen temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

// сортировка по имени Я-А
void sort_by_name_desc(struct humen arr[], int n)
{
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-1-i; j++)
            if(strcmp(arr[j].name, arr[j+1].name) < 0)
            {
                struct humen temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    struct humen arr[100];
    int n;

    printf("Сколько человек ввести? ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("\n--- Человек %d ---\n", i+1);
        printf("Имя: ");
        scanf("%s", arr[i].name);
        printf("Фамилия: ");
        scanf("%s", arr[i].surname);
        printf("Год: ");
        scanf("%d", &arr[i].year);
    }

    int choice;
    printf("\n=== СОРТИРОВКА ===\n");
    printf("1. По фамилии (А-Я)\n");
    printf("2. По фамилии (Я-А)\n");
    printf("3. По имени (А-Я)\n");
    printf("4. По имени (Я-А)\n");
    printf("Выбор: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            sort_by_surname_asc(arr, n);
            printf("\n=== ОТСОРТИРОВАНО ПО ФАМИЛИИ (А-Я) ===\n");
            break;
        case 2:
            sort_by_surname_desc(arr, n);
            printf("\n=== ОТСОРТИРОВАНО ПО ФАМИЛИИ (Я-А) ===\n");
            break;
        case 3:
            sort_by_name_asc(arr, n);
            printf("\n=== ОТСОРТИРОВАНО ПО ИМЕНИ (А-Я) ===\n");
            break;
        case 4:
            sort_by_name_desc(arr, n);
            printf("\n=== ОТСОРТИРОВАНО ПО ИМЕНИ (Я-А) ===\n");
            break;
    }

    for(int i = 0; i < n; i++)
        printf("%d. %s %s, %d\n", i+1, arr[i].surname, arr[i].name, arr[i].year);

    return 0;
}