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

int run_test(struct test_data data)
{
    double solution_x1 = 0;
    double solution_x2 = 0;

    int count_of_roots = program_solve_equation(data.coeff_a, data.coeff_b, data.coeff_c, &solution_x1, &solution_x2);

    if (data.solution_x1_expected > data.solution_x2_expected) 
    {
        swap(&(data.solution_x1_expected), &(data.solution_x2_expected));    
    }

    if (solution_x1 > solution_x2)
    {
        swap(&solution_x1, &solution_x2);
    }   

    if (!double_equals(count_of_roots, data.count_of_different_roots_expected) // fix logic
        || !((solution_x1 == NAN) && (data.solution_x1_expected == NAN))
        || !((solution_x2 == NAN) && (data.solution_x2_expected == NAN)))
    {
        return FAILURE;
    }

    if (!double_equals(count_of_roots, data.count_of_different_roots_expected)
        || !double_equals(solution_x1, data.solution_x1_expected)
        || !double_equals(solution_x2, data.solution_x2_expected))
    {
        printf("\n#         Error test %d.\n"
               "          a = %lf, b = %lf, c = %lf.\n"
               "          x1 = %lf, x2 = %lf, count_of_roots = %d.\n"
               "Expected: x1 = %lf, x2 = %lf, count_of_roots = %d.\n",
               data.num_of_test,
               data.coeff_a, data.coeff_b, data.coeff_c,
               solution_x1, solution_x2, count_of_roots,
               data.solution_x1_expected, data.solution_x2_expected, data.count_of_different_roots_expected);
        return FAILURE;
    }
    return SUCCESS;
}

void swap(double * num1, double * num2)
{
    double temp = *num2;
    *num2 = *num1;
    *num1 = temp;
}
