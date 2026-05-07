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
double** matrix_sub(double **a, double **b, int n)
{
    int i, j;
    double **res = (double**)malloc(n * sizeof(double*));
    
    for (i = 0; i < n; i++)
    {
        res[i] = (double*)malloc(n * sizeof(double));
        for (j = 0; j < n; j++)
        {
            res[i][j] = a[i][j] - b[i][j];
        }
    }
    return res;
}
double** matrix_mul(double **a, double **b, int n)
{
    int i, j, k;
    double **res = (double**)malloc(n * sizeof(double*));
    
    for (i = 0; i < n; i++)
    {
        res[i] = (double*)malloc(n * sizeof(double));
        for (j = 0; j < n; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < n; k++)
            {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}