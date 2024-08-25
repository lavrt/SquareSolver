#include "supportive.h"

#include <stdio.h>
#include <stdbool.h>                                  
#include <math.h>

#include "formatting.h" 

bool my_isnan(double num)
{
    return num != num;
}

void my_assert(bool statement, const char * error_message, const char * file_name,
               int number_of_string, const char * func_name) 
{
    if (statement) { return ; }
    
    fprintf(stderr, COLOR_RED FORMAT_BOLD "\nError\n%s:%d\n%s\n%s\n" COLOR_BLACK FORMAT_OFF "\n",
            file_name, number_of_string, func_name, error_message); 
    abort();
} 

bool my_isfinite(double num)
{
    return !(my_isnan(num) || my_isnan(num - num));
}

void swap(double * num1, double * num2)
{
    ASSERT(num1 != NULL, "The pointer to first number is NULL.");
    ASSERT(num2 != NULL, "The pointer to second number is NULL.");
    
    if (num1 == num2) { return; }
    
    double temp = *num2;
                  *num2 = *num1;
                          *num1 = temp;   
}