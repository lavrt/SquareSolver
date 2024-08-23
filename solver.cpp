#include "solver.h"

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "supportive.h"

enum nRoots program_solve_equation(double coeff_a, double coeff_b, double coeff_c, double * solution_x1, double * solution_x2)
{
    my_assert (my_isfinite(coeff_a)); // накидать ассерты в другие места add my_assert in other places
    my_assert (my_isfinite(coeff_b));
    my_assert (my_isfinite(coeff_c));                                                                                          

    my_assert (solution_x1 != NULL);
    my_assert (solution_x2 != NULL);
    my_assert (solution_x1 != solution_x2); 

    if (double_equals(coeff_a, 0))
    {
        return solver_linear_equation(coeff_b, coeff_c, solution_x1, solution_x2);
    }
    else
    {
        return solver_quadratic_equation(coeff_a, coeff_b, coeff_c, solution_x1, solution_x2);
    }
}

enum nRoots solver_quadratic_equation(double coeff_a, double coeff_b, double coeff_c, double * solution_x1, double * solution_x2)
{                                                                         
    my_assert (solution_x1 != NULL);
    my_assert (solution_x2 != NULL);
    my_assert (solution_x1 != solution_x2); 
    
    double discriminant = coeff_b * coeff_b - 4 * coeff_a * coeff_c;

    if (double_equals(discriminant, 0))
    {
        *solution_x1 = (-coeff_b - sqrt(discriminant)) / (2 * coeff_a);
        *solution_x2 = (-coeff_b + sqrt(discriminant)) / (2 * coeff_a);
        return ONE_SOLUTION;
    }
    else if (discriminant > 0)
    {
        *solution_x1 = (-coeff_b - sqrt(discriminant)) / (2 * coeff_a);
        *solution_x2 = (-coeff_b + sqrt(discriminant)) / (2 * coeff_a);
        return TWO_SOLUTIONS;
    }
    else
    {
        *solution_x1 = NAN;
        *solution_x2 = NAN; 
        return NO_SOLUTIONS;                                                                                                // header guard
    }
}

enum nRoots solver_linear_equation(double coeff_b, double coeff_c, double * solution_x1, double * solution_x2)
{
    my_assert (solution_x1 != NULL);
    my_assert (solution_x2 != NULL);
    my_assert (solution_x1 != solution_x2); 
    
    if (double_equals(coeff_b, 0))
    {
        if (double_equals(coeff_c, 0))
        {
            *solution_x1 = NAN;
            *solution_x2 = NAN;
            return ANY_NUMBER;            
        }
        else
        {
            *solution_x1 = NAN;
            *solution_x2 = NAN;
            return NO_SOLUTIONS;
        }
    }
    else
    {
        *solution_x1 = -(coeff_c / coeff_b);
        *solution_x2 = -(coeff_c / coeff_b);
        return ONE_SOLUTION;
    }
}

void swap(double * num1, double * num2)
{
    my_assert (num1 != NULL);
    my_assert (num2 != NULL);
    my_assert (num1 != num2);
    
    double temp = *num2;
                  *num2 = *num1;
                          *num1 = temp;
}

bool double_equals(double num1, double num2)
{
    return fabs(num1 - num2) < epsilon;
}