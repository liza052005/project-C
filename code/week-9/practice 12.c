#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Проверка високосного года
int is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Количество дней в месяце
int days_in_month(int year, int month)
{
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(month == 2 && is_leap_year(year))
        return 29;
    return days[month - 1];
}

// День недели (формула Зеллера)
int day_of_week(int year, int month, int day)
{
    if(month < 3)
    {
        month += 12;
        year--;
    }
    
    int k = year % 100;
    int j = year / 100;
    
    int dow = (day + (13 * (month + 1)) / 5 + k + (k / 4) + (j / 4) + 5 * j) % 7;
    dow = (dow + 5) % 7;
    
    return dow;  // 0 = понедельник, 6 = воскресенье
}

// Вывод дня недели
void print_weekday(int year, int month, int day)
{
    char *weekdays[] = {"понедельник", "вторник", "среда", 
                        "четверг", "пятница", "суббота", "воскресенье"};
    
    int dow = day_of_week(year, month, day);
    printf("%d.%d.%d - %s\n", year, month, day, weekdays[dow]);
}

// Вывод календаря на месяц
void print_month_calendar(int year, int month)
{
    char *month_names[] = {"Январь", "Февраль", "Март", "Апрель", 
                           "Май", "Июнь", "Июль", "Август", 
                           "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};
    
    int days = days_in_month(year, month);
    int start_dow = day_of_week(year, month, 1);
    
    printf("\n     %s %d\n", month_names[month - 1], year);
    printf("Пн Вт Ср Чт Пт Сб Вс\n");
    printf("--------------------\n");
    
    for(int i = 0; i < start_dow; i++)
        printf("   ");
    
    for(int day = 1; day <= days; day++)
    {
        printf("%2d ", day);
        if((start_dow + day) % 7 == 6)
            printf("\n");
    }
    printf("\n\n");
}

// Вывод календаря на год
void print_year_calendar(int year)
{
    printf("\n================== %d ==================\n\n", year);
    for(int month = 1; month <= 12; month++)
        print_month_calendar(year, month);
}

// Текущая дата
void get_current_date(int *year, int *month, int *day)
{
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    
    *year = local->tm_year + 1900;
    *month = local->tm_mon + 1;
    *day = local->tm_mday;
}

// Разбор ввода
void parse_input(char *input, int *year, int *month, int *day, int *mode)
{
    int dots = 0;
    for(int i = 0; input[i] != '\0'; i++)
        if(input[i] == '.') dots++;
    
    if(strcmp(input, "now") == 0)
    {
        *mode = 4;
        get_current_date(year, month, day);
    }
    else if(dots == 2)
    {
        *mode = 1;
        sscanf(input, "%d.%d.%d", year, month, day);
    }
    else if(dots == 1)
    {
        *mode = 2;
        sscanf(input, "%d.%d", year, month);
        *day = 1;
    }
    else
    {
        *mode = 3;
        *year = atoi(input);
        *month = 1;
        *day = 1;
    }
}

int main()
{
    char input[100];
    int year, month, day, mode;
    
    printf("=== ПРОГРАММА-КАЛЕНДАРЬ ===\n");
    printf("Форматы ввода:\n");
    printf("  - гггг.мм.дд  (день недели)\n");
    printf("  - гггг.мм     (календарь месяца)\n");
    printf("  - гггг        (календарь года)\n");
    printf("  - now         (текущая дата)\n");
    printf("\nВаш ввод: ");
    
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    
    parse_input(input, &year, &month, &day, &mode);
    
    printf("\n");
    
    switch(mode)
    {
        case 1:
            printf("Дата: %d.%d.%d\n", year, month, day);
            print_weekday(year, month, day);
            break;
        case 2:
            printf("Месяц: %d.%d\n", year, month);
            print_month_calendar(year, month);
            break;
        case 3:
            printf("Год: %d\n", year);
            print_year_calendar(year);
            break;
        case 4:
            printf("Текущая дата: %d.%d.%d\n", year, month, day);
            print_weekday(year, month, day);
            break;
        default:
            printf("Ошибка ввода!\n");
    }
    
    return 0;
}
ааа