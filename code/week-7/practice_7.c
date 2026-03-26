    #include <stdio.h>
    #include <string.h>

    struct humen{
        char name [50];
        char surname [50];
        int year;

    };
    int main()
    {
        struct humen arr1[4];
        struct humen arr2[4];
        int i;
        printf("Введите данные о 4 людях:\n");
        for(i = 0; i < 4; i++)
        {
            printf("\n--- Человек %d ---\n", i + 1);
            
            printf("Введите имя: ");
            scanf("%s", arr1[i].name);
            
            printf("Введите фамилию: ");
            scanf("%s", arr1[i].surname);
            
            printf("Введите год рождения: ");
            scanf("%d", &arr1[i].year);
        }
         printf("\n=== ВВЕДЕННЫЕ ДАННЫЕ ===\n");
    for(i = 0; i < 4; i++)
    {
        printf("%d. %s %s, %d г.\n", 
               i + 1, 
               arr1[i].name, 
               arr1[i].surname, 
               arr1[i].year);
    }
        return 0;
    }