#include "tester.h"

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "solver.h"
#include "supportive.h"

void program_testing(void) // void to int
{  
    struct testData array_of_tests[] =
    { //  num_of_test  coeff_a  coeff_b  coeff_c  solution_x1  solution_x2  count_of_different_roots 
        {      1,         0,       0,       0,        NAN,         NAN,            ANY_NUMBER        }, 
        {      2,         0,       0,       9,        NAN,         NAN,          NO_SOLUTIONS        }, // add test with coeff float point
        {      3,         0,       2,       6,         -3,          -3,          ONE_SOLUTION        },
        {      4,         1,      -2,       1,          1,           1,          ONE_SOLUTION        },
        {      5,         2,      -7,       5,          1,         2.5,         TWO_SOLUTIONS        },
        {      6,         1,       1,       1,        NAN,         NAN,          NO_SOLUTIONS        },
    };
    
    int count_of_tests = sizeof(array_of_tests) / sizeof(array_of_tests[0]);
    
    for (int index = 0; index < count_of_tests; ++index)
    {
        run_test(&array_of_tests[index]);
    }   
}

enum condition run_test(struct testData * data)
{    
    my_assert (data != NULL);
    
    double solution_x1 = 0;
    double solution_x2 = 0;

    int count_of_roots = program_solve_equation(data -> coeff_a, data -> coeff_b, data -> coeff_c, &solution_x1, &solution_x2);

    if (my_isnan(solution_x1) || my_isnan(solution_x2) || my_isnan(data -> solution_x1_expected) || my_isnan(data -> solution_x2_expected))
    {
        my_assert(my_isnan(data -> solution_x1_expected) && my_isnan(data -> solution_x2_expected));
        my_assert(my_isnan(solution_x1) && my_isnan(solution_x2));
    }

    if (!(my_isnan(data -> solution_x1_expected) && my_isnan(data -> solution_x2_expected)) && (data -> solution_x1_expected > data -> solution_x2_expected)) 
    {
        swap(&(data -> solution_x1_expected), &(data -> solution_x2_expected));    
    }

    if (!(my_isnan(solution_x1) && my_isnan(solution_x2)) && (solution_x1 > solution_x2))
    {
        swap(&solution_x1, &solution_x2);
    } 
        
    if (!double_equals_with_support_nan(count_of_roots, data -> count_of_different_roots_expected)
     || !double_equals_with_support_nan(solution_x1, data -> solution_x1_expected)
     || !double_equals_with_support_nan(solution_x2, data -> solution_x2_expected))
    {
        printf("\n#         Error test %d.\n"
               "          a = %lf, b = %lf, c = %lf.\n"
               "          x1 = %lf, x2 = %lf, count_of_roots = %d.\n"
               "Expected: x1 = %lf, x2 = %lf, count_of_roots = %d.\n",
               data -> num_of_test,
               data -> coeff_a, data -> coeff_b, data -> coeff_c,
               solution_x1, solution_x2, count_of_roots,
               data -> solution_x1_expected, data -> solution_x2_expected, data -> count_of_different_roots_expected);
        return FAILURE;
    }
    return SUCCESS;
}

bool double_equals_with_support_nan(double num1, double num2)
{ 
    if (my_isnan(num1) && my_isnan(num2))
        return true;
    else
        return double_equals(num1, num2);
}