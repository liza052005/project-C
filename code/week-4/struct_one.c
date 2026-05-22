#include <stdio.h>
#include <windows.h>
struct Student {
    char name[50];
    int age;
    float grade;
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    struct Student student1;

    printf("Введите имя студента: ");
    scanf("%s", student1.name);
    printf("Введите возраст: ");
    scanf("%d", &student1.age);
    printf("Введите оценку: ");
    scanf("%f", &student1.grade);

    printf("\nДанные студента:\n");
    printf("Имя: %s\n", student1.name);
    printf("Возраст: %d\n", student1.age);
    printf("Оценка: %.1f\n", student1.grade);

    return 0;
}