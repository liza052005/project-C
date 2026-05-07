double** matrix_add(double **a, double **b, int n)
{
    int i, j;
    double **res = (double**)malloc(n * sizeof(double*));
    
    for (i = 0; i < n; i++)
    {
        res[i] = (double*)malloc(n * sizeof(double));
        for (j = 0; j < n; j++)
        {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
    return res;
}