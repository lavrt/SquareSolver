#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include "output.h"
#include "solver.h"

/*!
\file
*/

void program_print_solutions(double coeff_a, double coeff_b, double coeff_c, double solution_x1, double solution_x2)
{
    int count_of_roots = program_solve_equation(coeff_a, coeff_b, coeff_c, &solution_x1, &solution_x2);
    switch (count_of_roots) 
    {
        case NO_SOLUTIONS:
            printf("\nThe equation has no solutions.\n");
            break;
        case ONE_SOLUTION:
            printf("\nThe equation has one solution. x = %lf.\n", solution_x1);
            break;
        case TWO_SOLUTIONS:
            printf("\nThe equation has two solutions. x1 = %lf, x2 = %lf.\n", solution_x1, solution_x2);
            break;
        case ANY_NUMBER:
            printf("\nThe solution to the equation is any number.\n");
            break;
        default:
            printf("\nUnexpected error!\n");
    }
}