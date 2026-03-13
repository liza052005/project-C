int main()
{
    double matrix [3] [3];
    int i,j;
    printf("Введите значение матрицы 3x3: \n");
    for(i = 0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("matrix [%d] [%d] = ", i, j);
            scanf("%lf", &matrix[i] [j]);
        }
    }
    printf("\nВведенная матрица:\n");
        for(i = 0; i < 3; i++)
        {
            for(j = 0; j < 3; j++)
            {
                printf("%.2f\t", matrix[i][j]);  // \t - табуляция для ровных столбцов
            }
            printf("\n");  // переход на новую строку после каждой строки матрицы
        }
        double sum_main = 0;  // сумма главной диагонали

        for(i = 0; i < 3; i++)
        {
            sum_main += matrix[i][i];  // matrix[0][0], matrix[1][1], matrix[2][2]
        }
        double sum_secondary = 0;  // сумма побочной диагонали

        for(i = 0; i < 3; i++)
        {
            sum_secondary += matrix[i][2 - i];  // matrix[0][2], matrix[1][1], matrix[2][0]
        }
        printf("\nСумма главной диагонали: %.2f\n", sum_main);
        printf("Сумма побочной диагонали: %.2f\n", sum_secondary);



        // ВТОРАЯ ЧАСТЬ - матрица 2x2 типа int
        int matrix2[2][2];
        int k, l;  // можно использовать i, j заново

        printf("\n=== ВТОРАЯ ЧАСТЬ: матрица 2x2 ===\n");
        printf("Введите элементы матрицы 2x2 (целые числа):\n");

        for(i = 0; i < 2; i++)
        {
            for(j = 0; j < 2; j++)
            {
                printf("matrix2[%d][%d] = ", i, j);
                scanf("%d", &matrix2[i][j]);
            }
        }
            printf("\nВведенная матрица 2x2:\n");
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            printf("%d\t", matrix2[i][j]);
        }
        printf("\n");
    }
    int result[2][2];  // матрица для результата

// Получаем элементы исходной матрицы для удобства
int a = matrix2[0][0];
int b = matrix2[0][1];
int c = matrix2[1][0];
int d = matrix2[1][1];

// Вычисляем квадрат
result[0][0] = a*a + b*c;
result[0][1] = a*b + b*d;
result[1][0] = c*a + d*c;
result[1][1] = c*b + d*d;
printf("\nИсходная матрица:\n");
for(i = 0; i < 2; i++)
{
    for(j = 0; j < 2; j++)
    {
        printf("%d\t", matrix2[i][j]);
    }
    printf("\n");
}

printf("\nКвадрат матрицы:\n");
for(i = 0; i < 2; i++)
{
    for(j = 0; j < 2; j++)
    {
        printf("%d\t", result[i][j]);
    }
    printf("\n");
}
    return 0;
}