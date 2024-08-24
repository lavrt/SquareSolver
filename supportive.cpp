#include "supportive.h"

#include <stdio.h>
#include <stdbool.h>                                  
#include <math.h>

#include "formatting.h" 

bool my_isnan(double num)
{
    return num != num;
}

void my_assert(bool statement, const char * error_message, const char * file_name, int number_of_string, const char * func_name) // в отдельный файл
{
    if (!statement)
    {
        fprintf(stderr, COLOR_RED FORMAT_BOLD "\nError\n%s:%d\n%s" COLOR_BLACK FORMAT_OFF "\n",
                file_name, number_of_string, func_name); 
        abort();
    }
} 

bool my_isfinite(double num)
{
    return !(my_isnan(num) || my_isnan(num - num));
}