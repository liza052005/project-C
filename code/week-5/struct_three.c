
#include <stdio.h>
#include <windows.h>
struct Student {
    char name[50];
    int age;
};
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    struct Student class[3];
    int i;

    for(i = 0; i < 3; i++)
    {
        printf("\nСтудент %d:\n", i+1);
        printf("Имя: ");
        scanf("%s", class[i].name);
        printf("Возраст: ");
        scanf("%d", &class[i].age);
    }
    printf("\nВСЕ СТУДЕНТЫ \n");
    for(i = 0; i < 3; i++)
    {
        printf("%d. %s, %d лет\n", i+1, class[i].name, class[i].age);
    }

    return 0;
}