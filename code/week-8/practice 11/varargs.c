#include "varargs.h"
#include <stdio.h>


double sum(int count, ...)
{
    va_list args;          
    double total = 0;
    va_start(args, count);
    for(int i = 0; i < count; i++)
    {
        total += va_arg(args, double); 
    }
    va_end(args);           
    return total;
}
// Максимум чисел
double max(int count, ...)
{
    va_list args;
    double max_val;
    
    va_start(args, count);
    
    max_val = va_arg(args, double);  // первый аргумент
    
    for(int i = 1; i < count; i++)
    {
        double current = va_arg(args, double);
        if(current > max_val)
            max_val = current;
    }
    
    va_end(args);
    
    return max_val;
}