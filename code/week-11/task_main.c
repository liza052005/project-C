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
void search_by_author(struct Book books[], int count)
{
    char author[50];
    int found = 0;
    
    printf("Введите имя автора: ");
    fgets(author, sizeof(author), stdin);
    author[strcspn(author, "\n")] = 0;
    
    printf("\n=== КНИГИ АВТОРА '%s' ===\n", author);
    
    for(int i = 0; i < count; i++)
    {
        if(strstr(books[i].author, author) != NULL)
        {
            printf("%s (%d г.) - %d стр., %.2f руб.\n",
                   books[i].title,
                   books[i].year,
                   books[i].pages,
                   books[i].price);
            found = 1;
        }
    }
    
    if(!found)
        printf("Книги этого автора не найдены.\n");
}
void search_by_title(struct Book books[], int count)
{
    char title[100];
    int found = 0;
    
    printf("Введите название (или часть): ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0;
    
    printf("\n=== РЕЗУЛЬТАТЫ ПОИСКА ===\n");
    
    for(int i = 0; i < count; i++)
    {
        if(strstr(books[i].title, title) != NULL)
        {
            printf("%s - %s (%d г.)\n",
                   books[i].title,
                   books[i].author,
                   books[i].year);
            found = 1;
        }
    }
    
    if(!found)
        printf("Книги не найдены.\n");
}
void delete_book(struct Book books[], int *count)
{
    char title[100];
    int index = -1;
    
    printf("Введите название книги для удаления: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0;
    
    for(int i = 0; i < *count; i++)
    {
        if(strcmp(books[i].title, title) == 0)
        {
            index = i;
            break;
        }
    }
    
    if(index == -1)
    {
        printf("Книга не найдена!\n");
        return;
    }
    
    // Сдвигаем элементы влево
    for(int i = index; i < *count - 1; i++)
    {
        books[i] = books[i + 1];
    }
    
    (*count)--;
    printf("Книга удалена!\n");
}
void books_after_year(struct Book books[], int count)
{
    int year;
    int found = 0;
    
    printf("Введите год: ");
    scanf("%d", &year);
    getchar();
    
    printf("\n=== КНИГИ ИЗДАННЫЕ ПОСЛЕ %d ГОДА ===\n", year);
    
    for(int i = 0; i < count; i++)
    {
        if(books[i].year > year)
        {
            printf("%s - %s (%d г.)\n",
                   books[i].title,
                   books[i].author,
                   books[i].year);
            found = 1;
        }
    }
    
    if(!found)
        printf("Книги не найдены.\n");
}
void thickest_book(struct Book books[], int count)
{
    if(count == 0)
    {
        printf("Библиотека пуста!\n");
        return;
    }
    
    int max_index = 0;
    
    for(int i = 1; i < count; i++)
    {
        if(books[i].pages > books[max_index].pages)
            max_index = i;
    }
    
    printf("\n=== САМАЯ ТОЛСТАЯ КНИГА ===\n");
    printf("Название: %s\n", books[max_index].title);
    printf("Автор: %s\n", books[max_index].author);
    printf("Год: %d\n", books[max_index].year);
    printf("Страниц: %d\n", books[max_index].pages);
    printf("Цена: %.2f руб.\n", books[max_index].price);
}