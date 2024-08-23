#include "supportive.h"

#include <stdio.h>
#include <stdbool.h>                                  // check define макросы
#include <math.h>

bool my_isnan(double num)
{
    return num != num;
}

void my_assert(bool statement) // , const char * error_message
{
    if (!statement)
    {
        puts("ERROR\n");
        //printf("\n%d\n", __LINE__);
        abort();
    }
}

bool my_isfinite(double num)
{
    return !(my_isnan(num) || my_isnan(num - num));
}