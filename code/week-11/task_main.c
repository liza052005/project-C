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