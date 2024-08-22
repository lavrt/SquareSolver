int program_solve_equation(double coeff_a, double coeff_b, double coeff_c, double * solution_x1, double * solution_x2)
{
    assert (isfinite(coeff_a)); // накидать ассерты в другие места
    assert (isfinite(coeff_b));
    assert (isfinite(coeff_c));                                                                                          

    assert (solution_x1 != NULL);
    assert (solution_x2 != NULL);
    assert (solution_x1 != solution_x2); 

    if (double_equals(coeff_a, 0))
    {
        return solver_linear_equation(coeff_b, coeff_c, solution_x1, solution_x2);
    }
    else
    {
        return solver_quadratic_equation(coeff_a, coeff_b, coeff_c, solution_x1, solution_x2);
    }
}

int solver_quadratic_equation(double coeff_a, double coeff_b, double coeff_c, double * solution_x1, double * solution_x2)
{                                                                         
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

int solver_linear_equation(double coeff_b, double coeff_c, double * solution_x1, double * solution_x2)
{
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

int run_test(int num_of_test, double coeff_a, double coeff_b, double coeff_c, double solution_x1_expected, double solution_x2_expected, int count_of_different_roots_expected)
{
    double solution_x1 = 0;
    double solution_x2 = 0;

    int count_of_roots = program_solve_equation(coeff_a, coeff_b, coeff_c, &solution_x1, &solution_x2);

    if (solution_x1_expected > solution_x2_expected) 
    {
        swap(&solution_x1_expected, &solution_x2_expected);    
    }

    if (solution_x1 > solution_x2)
    {
        swap(&solution_x1, &solution_x2);
    }   

    if (!double_equals(count_of_roots, count_of_different_roots_expected)
        || !((solution_x1 == NAN) && (solution_x1_expected == NAN))
        || !((solution_x2 == NAN) && (solution_x2_expected == NAN)))
    {
        return FAILURE;
    }

    if (!double_equals(count_of_roots, count_of_different_roots_expected)
        || !double_equals(solution_x1, solution_x1_expected)
        || !double_equals(solution_x2, solution_x2_expected))
    {
        printf("\n#         Error test %d.\n"
               "          a = %lf, b = %lf, c = %lf.\n"
               "          x1 = %lf, x2 = %lf, count_of_roots = %d.\n"
               "Expected: x1 = %lf, x2 = %lf, count_of_roots = %d.\n",
               num_of_test,
               coeff_a, coeff_b, coeff_c,
               solution_x1, solution_x2, count_of_roots,
               solution_x1_expected, solution_x2_expected, count_of_different_roots_expected);
        return FAILURE;
    }
    return SUCCESS;
}

void all_tests(void)
{   //        num_of_test  coeff_a  coeff_b  coeff_c  solution_x1  solution_x2  count_of_different_roots 
    run_test(      1,         0,       0,       0,        NAN,         NAN,            ANY_NUMBER        );       
    run_test(      2,         0,       0,       9,        NAN,         NAN,          NO_SOLUTIONS        );
    run_test(      3,         0,       2,       6,         -3,          -3,          ONE_SOLUTION        );
    run_test(      4,         1,      -2,       1,          1,           1,          ONE_SOLUTION        );
    run_test(      5,         2,      -7,       5,          1,         2.5,         TWO_SOLUTIONS        );
    run_test(      6,         1,       1,       1,        NAN,         NAN,          NO_SOLUTIONS        );
}

void swap(double * num1, double * num2)
{
    double temp = *num2;
    *num2 = *num1;
    *num1 = temp;
}