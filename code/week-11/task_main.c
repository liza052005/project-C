#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_BOOKS 100
struct Book {
    char title[100];
    char author[50];
    int year;
    int pages;
    float price;
};

void add_book(struct Book books[], int *count);
void show_all_books(struct Book books[], int count);
void search_by_author(struct Book books[], int count);
void search_by_title(struct Book books[], int count);
void delete_book(struct Book books[], int *count);
void books_after_year(struct Book books[], int count);
void thickest_book(struct Book books[], int count);

int main()
{
    struct Book library[MAX_BOOKS];
    int book_count = 0;
    int choice;
    
    do {
        printf("\n=== БИБЛИОТЕКА ===\n");
        printf("1. Добавить книгу\n");
        printf("2. Показать все книги\n");
        printf("3. Поиск по автору\n");
        printf("4. Поиск по названию\n");
        printf("5. Удалить книгу\n");
        printf("6. Книги после года\n");
        printf("7. Самая толстая книга\n");
        printf("8. Выход\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);
        getchar(); 
        switch(choice)
        {
            case 1: add_book(library, &book_count); break;
            case 2: show_all_books(library, book_count); break;
            case 3: search_by_author(library, book_count); break;
            case 4: search_by_title(library, book_count); break;
            case 5: delete_book(library, &book_count); break;
            case 6: books_after_year(library, book_count); break;
            case 7: thickest_book(library, book_count); break;
            case 8: printf("До свидания!\n"); break;
            default: printf("Неверный выбор!\n");
        }
    } while(choice != 8);
    return 0;
}
void add_book(struct Book books[], int *count)
{
    if(*count >= MAX_BOOKS)
    {
        printf("Библиотека переполнена!\n");
        return;
    }
    
    printf("\n=== ДОБАВЛЕНИЕ КНИГИ ===\n");
    
    printf("Название: ");
    fgets(books[*count].title, sizeof(books[*count].title), stdin);
    books[*count].title[strcspn(books[*count].title, "\n")] = 0;
    
    printf("Автор: ");
    fgets(books[*count].author, sizeof(books[*count].author), stdin);
    books[*count].author[strcspn(books[*count].author, "\n")] = 0;
    
    printf("Год издания: ");
    scanf("%d", &books[*count].year);
    
    printf("Количество страниц: ");
    scanf("%d", &books[*count].pages);
    
    printf("Цена: ");
    scanf("%f", &books[*count].price);
    getchar(); // очистка буфера
    
    (*count)++;
    printf("Книга добавлена!\n");
}
void show_all_books(struct Book books[], int count)
{
    if(count == 0)
    {
        printf("Библиотека пуста!\n");
        return;
    }
    
    printf("\n=== ВСЕ КНИГИ ===\n");
    printf("%-3s %-30s %-20s %-6s %-8s %-8s\n", 
           "№", "Название", "Автор", "Год", "Стр.", "Цена");
    printf("----------------------------------------------------------------\n");
    
    for(int i = 0; i < count; i++)
    {
        printf("%-3d %-30s %-20s %-6d %-8d %-8.2f\n",
               i + 1,
               books[i].title,
               books[i].author,
               books[i].year,
               books[i].pages,
               books[i].price);
    }
}