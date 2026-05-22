
#include <stdio.h>
#include <windows.h>
struct Date {
    int day;
    int month;
    int year;
};

struct Student {
    char name[50];
    struct Date birthday;
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    struct Student s;
    
    printf("Имя студента: ");
    scanf("%s", s.name);
    
    printf("Дата рождения (день месяц год): ");
    scanf("%d %d %d", &s.birthday.day, 
                      &s.birthday.month, 
                      &s.birthday.year);
    
    printf("\nСтудент: %s\n", s.name);
    printf("Родился: %02d.%02d.%d\n", 
           s.birthday.day, 
           s.birthday.month, 
           s.birthday.year);
    
    return 0;
}

