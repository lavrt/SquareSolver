#include "tester.h"

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "solver.h"
#include "supportive.h"
#include "formatting.h"

enum condition run_test(struct testData data)
{    
    double solution_x1 = 0;
    double solution_x2 = 0;

    int count_of_roots = program_solve_equation(data.coeff_a, data.coeff_b, data.coeff_c,
                                                &solution_x1, &solution_x2);

    if (my_isnan(data.solution_x1_expected) || my_isnan(data.solution_x2_expected))
    {
        ASSERT(my_isnan(data.solution_x1_expected) && my_isnan(data.solution_x2_expected),
              "Either both solutions are finite or both numbers are NaN");
    }

    if (my_isnan(solution_x1) || my_isnan(solution_x2))
    {
        ASSERT(my_isnan(solution_x1) && my_isnan(solution_x2),
              "Either both solutions are finite or both numbers are NaN");
    }

    if (!(my_isnan(data.solution_x1_expected)
        && my_isnan(data.solution_x2_expected))
        && (data.solution_x1_expected > data.solution_x2_expected)) 
    {
        swap(&(data.solution_x1_expected), &(data.solution_x2_expected));    
    }

    if (!(my_isnan(solution_x1) && my_isnan(solution_x2)) && (solution_x1 > solution_x2))
    {
        swap(&solution_x1, &solution_x2);
    } 
        
    if (!double_equals_with_support_nan(count_of_roots, data.count_of_different_roots_expected)
        || !double_equals_with_support_nan(solution_x1, data.solution_x1_expected)
        || !double_equals_with_support_nan(solution_x2, data.solution_x2_expected))
    {
        printf( COLOR_RED FORMAT_BOLD "\n#         Error test %d.\n"
               "          a = %lg, b = %lg, c = %lg.\n"
               "          x1 = %lg, x2 = %lg, count_of_roots = %d.\n"
               "Expected: x1 = %lg, x2 = %lg, count_of_roots = %d.\n\n" COLOR_BLACK FORMAT_OFF ,
               data.num_of_test,
               data.coeff_a, data.coeff_b, data.coeff_c,
               solution_x1, solution_x2, count_of_roots,
               data.solution_x1_expected, data.solution_x2_expected, data.count_of_different_roots_expected);
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

int read_and_run_tests(enum PrintTests flag)
{
    int number_of_failed_tests = 0;
    int count_of_tests = 0;

    struct testData data = {};
    
    FILE * input_tests = fopen("input_tests.txt", "r");

    fscanf(input_tests, "count_of_tests: %d", &count_of_tests);

    for (int index = 0; index < count_of_tests; ++index)
    {
        fscanf(input_tests, "%d%lf%lf%lf%lf%lf%d", &data.num_of_test, &data.coeff_a, &data.coeff_b, &data.coeff_c,
               &data.solution_x1_expected, &data.solution_x2_expected, &data.count_of_different_roots_expected);
        
        if (flag == PRINT_ON)
        {
            if (run_test(data) == SUCCESS)
            {
                printf( COLOR_GREEN FORMAT_BOLD "Test %d passed successfully" COLOR_BLACK FORMAT_OFF "\n", index + 1);
            }
            else
            {
                ++number_of_failed_tests;
                printf( COLOR_RED FORMAT_BOLD "Test %d failed" COLOR_BLACK FORMAT_BOLD "\n", index + 1);
            }
        }
        else
        {
            if (run_test(data) == FAILURE)
            {
                ++number_of_failed_tests;
            }
        }
    }
    fclose(input_tests);

    return number_of_failed_tests;
}