//dobavit rabota s filimi
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    char s[81];
    int choice;

    printf("Выберите режим:\n");
    printf("1 - ввод с клавиатуры\n");
    printf("2 - чтение из файла input.txt\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);
    getchar(); // чистим буфер

    if (choice == 2)
    {
        FILE *file = fopen("input.txt", "r");
        if (file == NULL)
        {
            printf("Файл не найден! Создайте input.txt\n");
            return 1;
        }
        fgets(s, sizeof(s), file);
        fclose(file);
        s[strcspn(s, "\n")] = '\0';
        printf("Прочитано из файла: %s\n", s);
    }
    else
    {
        printf("Введите строку до 80 символов:\n");
        if (fgets(s, sizeof(s), stdin) == NULL)
        {
            printf("Ошибка ввода!\n");
            return 1;
        }
        s[strcspn(s, "\n")] = '\0';
    }

    int count = 0;  // счетчик замен (преподы любят статистику)

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == 'a' || s[i] == 'b')
        {
            s[i] = toupper(s[i]);
            count++;
        }
        else if (s[i] == 'а' || s[i] == 'б')
        {
            s[i] = s[i] - 32;
            count++;
        }
    }

    printf("Result: %s\n", s);
    printf("Всего замен: %d\n", count);

    // запись результата в файл
    FILE *out = fopen("output.txt", "w");
    if (out != NULL)
    {
        fprintf(out, "%s\n", s);
        fclose(out);
        printf("Результат сохранен в output.txt\n");
    }

    return 0;
}
//stude stylec
#include <stdio.h>
#include <string.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    char stroka[81];  // назвал по-русски, как студент
    int i, len;

    printf("Введи строку: ");
    gets(stroka);  // специально использую gets() - студенты так делают

    len = strlen(stroka);

    // заменяем маленькие буквы на большие
    for(i = 0; i < len; i++)
    {
        if(stroka[i] == 'a')
        {
            stroka[i] = 'A';
        }
        else if(stroka[i] == 'b')
        {
            stroka[i] = 'B';
        }
        else if(stroka[i] == 'а')  // русская а
        {
            stroka[i] = 'А';
        }
        else if(stroka[i] == 'б')  // русская б
        {
            stroka[i] = 'Б';
        }
    }

    printf("Результат: %s\n", stroka);

    system("pause");  // студенты любят паузу
    return 0;
}
//obrabotka mnogo strok
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    char lines[5][81];  // массив из 5 строк
    int n;

    printf("Сколько строк обработать (1-5)? ");
    scanf("%d", &n);
    getchar();

    if(n < 1 || n > 5)
    {
        printf("Неверное количество!\n");
        return 1;
    }

    for(int k = 0; k < n; k++)
    {
        printf("\nВведите строку %d: ", k+1);
        if(fgets(lines[k], sizeof(lines[k]), stdin) == NULL)
        {
            printf("Ошибка!\n");
            return 1;
        }
        lines[k][strcspn(lines[k], "\n")] = '\0';
    }

    printf("\n=== РЕЗУЛЬТАТЫ ===\n");

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; lines[k][i] != '\0'; i++)
        {
            if(lines[k][i] == 'a' || lines[k][i] == 'b')
            {
                lines[k][i] = toupper(lines[k][i]);
            }
            else if(lines[k][i] == 'а' || lines[k][i] == 'б')
            {
                lines[k][i] = lines[k][i] - 32;
            }
        }
        printf("%d: %s\n", k+1, lines[k]);
    }

    return 0;
}
//menu
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    char s[81];
    int mode;

    printf("=== ОБРАБОТКА СТРОКИ ===\n");
    printf("1 - замена a/b на заглавные\n");
    printf("2 - замена всех букв на заглавные\n");
    printf("3 - замена всех букв на строчные\n");
    printf("4 - инвертировать регистр\n");
    printf("Выберите режим: ");
    scanf("%d", &mode);
    getchar();

    printf("Введите строку: ");
    if(fgets(s, sizeof(s), stdin) == NULL)
    {
        printf("Ошибка!\n");
        return 1;
    }
    s[strcspn(s, "\n")] = '\0';

    switch(mode)
    {
        case 1:
            for(int i = 0; s[i]; i++)
            {
                if(s[i] == 'a' || s[i] == 'b')
                    s[i] = toupper(s[i]);
                else if(s[i] == 'а' || s[i] == 'б')
                    s[i] = s[i] - 32;
            }
            break;

        case 2:
            for(int i = 0; s[i]; i++)
            {
                if(s[i] >= 'a' && s[i] <= 'z')
                    s[i] = s[i] - 32;
                else if(s[i] >= 'а' && s[i] <= 'я' && s[i] != 'ё')
                    s[i] = s[i] - 32;
            }
            break;

        case 3:
            for(int i = 0; s[i]; i++)
            {
                if(s[i] >= 'A' && s[i] <= 'Z')
                    s[i] = s[i] + 32;
                else if(s[i] >= 'А' && s[i] <= 'Я' && s[i] != 'Ё')
                    s[i] = s[i] + 32;
            }
            break;

        case 4:
            for(int i = 0; s[i]; i++)
            {
                if(s[i] >= 'a' && s[i] <= 'z')
                    s[i] = s[i] - 32;
                else if(s[i] >= 'A' && s[i] <= 'Z')
                    s[i] = s[i] + 32;
                else if(s[i] >= 'а' && s[i] <= 'я')
                    s[i] = s[i] - 32;
                else if(s[i] >= 'А' && s[i] <= 'Я')
                    s[i] = s[i] + 32;
            }
            break;

        default:
            printf("Неверный режим!\n");
            return 1;
    }

    printf("Результат: %s\n", s);

    return 0;
}
//obrabotka str celicom bez circle
#include <stdio.h>
#include <string.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    char s[81];

    printf("Введите строку: ");
    fgets(s, 81, stdin);
    s[strlen(s)-1] = '\0';

    // странный способ через указатели (студенты любят выпендриваться)
    char *p = s;
    while(*p)
    {
        if(*p == 'a') *p = 'A';
        else if(*p == 'b') *p = 'B';
        else if(*p == 'а') *p = 'А';
        else if(*p == 'б') *p = 'Б';
        p++;
    }

    printf("Итог: %s\n", s);

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>  // Для toupper()
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    char s[81];
    printf("Введите строку до 80 символов:\n");
    if (fgets(s, sizeof(s), stdin) == NULL) {
        printf("Ошибка ввода!\n");
        return 1;
    }
    s[strcspn(s, "\n")] = '\0';

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == 'a' || s[i] == 'b')
        {
            s[i] = toupper(s[i]);
        }
        else if (s[i] == 'а' || s[i] == 'б')
        {
            s[i] = s[i] - 32;
        }
    }
    printf("Result: %s\n", s);
    return 0;
}