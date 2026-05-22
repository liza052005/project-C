#include <stdio.h>
#include <windows.h>
struct Book {
    char title[100];
    char author[50];
    int year;
    float price;
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    struct Book book1, book2;

    printf("КНИГА 1 \n");
    printf("Название: ");
    scanf("%s", book1.title);
    printf("Автор: ");
    scanf("%s", book1.author);
    printf("Год: ");
    scanf("%d", &book1.year);
    printf("Цена: ");
    scanf("%f", &book1.price);
    printf("\n КНИГА 2\n");
    printf("Название: ");
    scanf("%s", book2.title);
    printf("Автор: ");
    scanf("%s", book2.author);
    printf("Год: ");
    scanf("%d", &book2.year);
    printf("Цена: ");
    scanf("%f", &book2.price);

    printf("\nСРАВНЕНИЕ \n");
    if(book1.price > book2.price)
        printf("Книга '%s' дороже\n", book1.title);
    else if(book1.price < book2.price)
        printf("Книга '%s' дороже\n", book2.title);
    else
        printf("Книги стоят одинаково\n");

    return 0;
}