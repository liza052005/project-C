#ifndef MATRIX_OPS_H
#define MATRIX_OPS_H

// Функция выполняет операцию над матрицами
// Принимает: указатели на матрицы A и B, размер n, оператор
// Возвращает: указатель на матрицу-результат
double* matrix_operation(double *A, double *B, int n, char op);

#endif