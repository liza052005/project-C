
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
    FILE *file;
    struct Student s;
    printf("Введите имя студента: ");
    scanf("%s", s.name);
    printf("Введите возраст: ");
    scanf("%d", &s.age);
    printf("Введите оценку: ");
    scanf("%f", &s.grade);

    file = fopen("treni.txt", "a");  // a = append (добавить)
    if(file == NULL)
    {
        printf("Ошибка!\n");
        return 1;
    }
    fprintf(file, "%s,%d,%.f\n", s.name, s.age, s.grade);
    fclose(file);
    printf("Данные сохранены!\n");

    return 0;
}