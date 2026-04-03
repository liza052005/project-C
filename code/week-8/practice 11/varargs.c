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

double max(int count, ...)
{
    va_list args;
    double max_val;
    va_start(args, count);
    max_val = va_arg(args, double);  
    for(int i = 1; i < count; i++)
    {
        double current = va_arg(args, double);
        if(current > max_val)
            max_val = current;
    }
    va_end(args);
    return max_val;
}


double min(int count, ...)
{
    va_list args;
    double min_val;
    
    va_start(args, count);
    
    min_val = va_arg(args, double);  
    
    for(int i = 1; i < count; i++)
    {
        double current = va_arg(args, double);
        if(current < min_val)
            min_val = current;
    }
    
    va_end(args);
    
    return min_val;
}