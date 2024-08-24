#include "solver.h"

#include <stdio.h>
#include <stdbool.h> // argc argv
#include <math.h>

#include "supportive.h"

enum nRoots program_solve_equation(double coeff_a, double coeff_b, double coeff_c,
                                   double * solution_x1, double * solution_x2)
{
    ASSERT (my_isfinite(coeff_a), "The coefficient a is not a finite number."); 
    ASSERT (my_isfinite(coeff_b), "The coefficient b is not a finite number.");
    ASSERT (my_isfinite(coeff_c), "The coefficient c is not a finite number.");                                                                                          

    ASSERT (solution_x1 != NULL, "The pointer to the solution x1 is NULL.");
    ASSERT (solution_x2 != NULL, "The pointer to the solution x2 is NULL.");
    ASSERT (solution_x1 != solution_x2, "The pointers to the solutions occupied one memory cell."); 

    return (double_equals(coeff_a, 0)) 
                ? solver_linear_equation(coeff_b, coeff_c, solution_x1, solution_x2)
                : solver_quadratic_equation(coeff_a, coeff_b, coeff_c, solution_x1, solution_x2);
} 

enum nRoots solver_quadratic_equation(double coeff_a, double coeff_b, double coeff_c,
                                      double * solution_x1, double * solution_x2)
{                                                                         
    ASSERT (solution_x1 != NULL, "The pointer to the solution x1 is NULL.");
    ASSERT (solution_x2 != NULL, "The pointer to the solution x2 is NULL.");
    ASSERT (solution_x1 != solution_x2, "The pointers to the solutions occupied one memory cell."); 
    
    double discriminant = coeff_b * coeff_b - 4 * coeff_a * coeff_c;

    if (double_equals(discriminant, 0))
    {
        *solution_x1 = -coeff_b / (2 * coeff_a);
        *solution_x2 = -coeff_b / (2 * coeff_a);
        return ONE_SOLUTION;
    }
    else if (discriminant > 0)
    {
        double discriminant_sqrt = sqrt(discriminant);
        
        *solution_x1 = (-coeff_b - discriminant_sqrt) / (2 * coeff_a);
        *solution_x2 = (-coeff_b + discriminant_sqrt) / (2 * coeff_a);
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
    ASSERT (solution_x1 != NULL, "The pointer to the solution x1 is NULL.");
    ASSERT (solution_x2 != NULL, "The pointer to the solution x2 is NULL.");
    ASSERT (solution_x1 != solution_x2, "The pointers to the solutions occupied one memory cell."); 
    
    if (double_equals(coeff_b, 0))
    {
        *solution_x1 = NAN;
        *solution_x2 = NAN;
        
        return (double_equals(coeff_c, 0)) ? ANY_NUMBER : NO_SOLUTIONS;
    }
    else
    {
        *solution_x1 = -(coeff_c / coeff_b);
        *solution_x2 = -(coeff_c / coeff_b);
        return ONE_SOLUTION;
    }
}

bool double_equals(double num1, double num2)
{
    return fabs(num1 - num2) < kEpsilon;
}