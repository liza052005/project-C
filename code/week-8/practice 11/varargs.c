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