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
    return 0;
}