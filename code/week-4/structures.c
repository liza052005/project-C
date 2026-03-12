#include <stdio.h>

// Объявление структуры
struct Student {
    char name[50];
    int age;
    float grade;
};

int main()
{
    // Создание переменной типа struct Student
    struct Student student1;
    
    // Заполнение полей структуры
    printf("Введите имя студента: ");
    scanf("%s", student1.name);
    
    printf("Введите возраст: ");
    scanf("%d", &student1.age);
    
    printf("Введите оценку: ");
    scanf("%f", &student1.grade);
    
    // Вывод данных
    printf("\nДанные студента:\n");
    printf("Имя: %s\n", student1.name);
    printf("Возраст: %d\n", student1.age);
    printf("Оценка: %.1f\n", student1.grade);
    
    return 0;
}
#include <stdio.h>

struct Book {
    char title[100];
    char author[50];
    int year;
    float price;
};

int main()
{
    struct Book book1, book2;
    
    // Заполняем первую книгу
    printf("=== КНИГА 1 ===\n");
    printf("Название: ");
    scanf("%s", book1.title);
    printf("Автор: ");
    scanf("%s", book1.author);
    printf("Год: ");
    scanf("%d", &book1.year);
    printf("Цена: ");
    scanf("%f", &book1.price);
    
    // Заполняем вторую книгу
    printf("\n=== КНИГА 2 ===\n");
    printf("Название: ");
    scanf("%s", book2.title);
    printf("Автор: ");
    scanf("%s", book2.author);
    printf("Год: ");
    scanf("%d", &book2.year);
    printf("Цена: ");
    scanf("%f", &book2.price);
    
    // Сравнение цен
    printf("\n=== СРАВНЕНИЕ ===\n");
    if(book1.price > book2.price)
        printf("Книга '%s' дороже\n", book1.title);
    else if(book1.price < book2.price)
        printf("Книга '%s' дороже\n", book2.title);
    else
        printf("Книги стоят одинаково\n");
    
    return 0;
}

#include <stdio.h>

struct Student {
    char name[50];
    int age;
};

int main()
{
    struct Student class[3];  // массив из 3 студентов
    int i;
    
    // Ввод данных для каждого студента
    for(i = 0; i < 3; i++)
    {
        printf("\nСтудент %d:\n", i+1);
        printf("Имя: ");
        scanf("%s", class[i].name);
        printf("Возраст: ");
        scanf("%d", &class[i].age);
    }
    
    // Вывод всех студентов
    printf("\n=== ВСЕ СТУДЕНТЫ ===\n");
    for(i = 0; i < 3; i++)
    {
        printf("%d. %s, %d лет\n", i+1, class[i].name, class[i].age);
    }
    
    return 0;
}

#include <stdio.h>

// Структура для даты
struct Date {
    int day;
    int month;
    int year;
};

// Структура для студента с датой рождения
struct Student {
    char name[50];
    struct Date birthday;  // структура внутри структуры
};

int main()
{
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


#include <stdio.h>

struct Point {
    int x;
    int y;
};

int main()
{
    struct Point dot = {10, 20};
    struct Point *ptr;  // указатель на структуру
    
    ptr = &dot;  // ptr указывает на dot
    
    // Доступ к полям через указатель
    printf("Через точку: x=%d, y=%d\n", dot.x, dot.y);
    printf("Через указатель: x=%d, y=%d\n", (*ptr).x, (*ptr).y);
    
    // Более удобный способ ->
    printf("Через стрелку: x=%d, y=%d\n", ptr->x, ptr->y);
    
    // Изменение через указатель
    ptr->x = 100;
    ptr->y = 200;
    
    printf("\nПосле изменения:\n");
    printf("x=%d, y=%d\n", dot.x, dot.y);
    
    return 0;
}