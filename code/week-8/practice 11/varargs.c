#ifndef VARARGS_H
#define VARARGS_H

#include <stdarg.h>  // для va_list, va_start, va_arg, va_end

// Функция вычисляет сумму чисел
double sum(int count, ...);

// Функция находит максимум
double max(int count, ...);

// Функция находит минимум
double min(int count, ...);

// Функция вычисляет среднее арифметическое
double average(int count, ...);

#endif