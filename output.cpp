#include "output.h"

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "solver.h"
#include "supportive.h"

void program_print_solutions(enum nRoots count_of_roots, double solution_x1, double solution_x2)
{
    switch (count_of_roots)
    {
        case NO_SOLUTIONS:
            printf("\nThe equation has no solutions.\n");
            break;
        case ONE_SOLUTION:
            printf("\nThe equation has one solution. x = %lg.\n", solution_x1);
            break;
        case TWO_SOLUTIONS:
            printf("\nThe equation has two solutions. x1 = %lg, x2 = %lg.\n", solution_x1, solution_x2);
            break;
        case ANY_NUMBER:
            printf("\nThe solution to the equation is any number.\n");
            break;
        default:
            ASSERT(0, "\nUnexpected error!\n");
    }
}
