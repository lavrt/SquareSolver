#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "tester.h"
#include "input.h"      
#include "solver.h"     
#include "output.h"

int main(const int argc, const char * argv[])
{
    program_testing();

    do
    {
        double coeff_a = 0;
        double coeff_b = 0;
        double coeff_c = 0;
        double solution_x1 = 0;
        double solution_x2 = 0;

        program_get_num(&coeff_a, &coeff_b, &coeff_c);

        program_solve_equation(coeff_a, coeff_b, coeff_c, &solution_x1, &solution_x2);

        program_print_solutions(coeff_a, coeff_b, coeff_c, solution_x1, solution_x2);

        printf("\nWould you like to solve another equation? ");
    } while (get_choice());

    return 0;
}