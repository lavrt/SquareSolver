int program_solve_equation(double coeff_a, double coeff_b, double coeff_c, double * solution_x1, double * solution_x2)
{
    assert (isfinite(coeff_a));
    assert (isfinite(coeff_b));
    assert (isfinite(coeff_c));

    assert (solution_x1 != NULL);
    assert (solution_x2 != NULL);
    assert (solution_x1 != solution_x2); 

    if (double_equals(coeff_a, 0))
    {
        if (double_equals(coeff_b, 0))
        {
            count_of_roots = (double_equals(coeff_c, 0)) ? ANY_NUMBER : NO_SOLUTIONS;
        }
        else
        {
            solver_linear_equation(coeff_b, coeff_c, solution_x1, solution_x2);
            count_of_roots = ONE_SOLUTION;
        }
    }
    else
    {
        double discriminant = coeff_b * coeff_b - 4 * coeff_a * coeff_c;

        if (double_equals(discriminant, 0))
        {
            solver_quadratic_equation(coeff_a, coeff_b, discriminant, solution_x1, solution_x2);
            count_of_roots = ONE_SOLUTION;
        }

        if (discriminant > 0)
        {
            solver_quadratic_equation(coeff_a, coeff_b, discriminant, solution_x1, solution_x2);
            count_of_roots = TWO_SOLUTIONS;
        }

        if (discriminant < 0)
        {
            assign_nan(solution_x1, solution_x2);
            count_of_roots = NO_SOLUTIONS;
        }
    }
    
    return count_of_roots;
}

void solver_quadratic_equation(double coeff_a, double coeff_b, double discriminant, double * solution_x1, double * solution_x2)
{
    *solution_x1 = (-coeff_b - sqrt(discriminant)) / (2 * coeff_a);
    *solution_x2 = (-coeff_b + sqrt(discriminant)) / (2 * coeff_a);
}

void solver_linear_equation(double coeff_b, double coeff_c, double * solution_x1, double * solution_x2)
{
    *solution_x1 = -(coeff_c / coeff_b);
    *solution_x2 = -(coeff_c / coeff_b);
}

void assign_nan(double * solution_x1, double * solution_x2)
{
    *solution_x1 = NAN;
    *solution_x2 = NAN;    
}

int run_test(int num_of_test, double coeff_a, double coeff_b, double coeff_c, double solution_x1_expected, double solution_x2_expected, int count_of_different_roots_expected)
{
    double solution_x1 = 0, solution_x2 = 0;

    int count_of_roots = program_solve_equation(coeff_a, coeff_b, coeff_c, &solution_x1, &solution_x2);

    if (solution_x1_expected > solution_x2_expected)
    {
        double temp = solution_x2_expected;
        solution_x2_expected = solution_x1_expected;
        solution_x1_expected = temp;
    }

    if (solution_x1 > solution_x2)
    {
        double temp = solution_x2;
        solution_x2 = solution_x1;
        solution_x1 = temp;
    }   

    if (!double_equals(count_of_roots, count_of_different_roots_expected)
        || !double_equals(solution_x1, solution_x1_expected)
        || !double_equals(solution_x2, solution_x2_expected))
    {
        printf("\n#         Errot test %d.\n"
                "          a = %lf, b = %lf, c = %lf.\n"
                "          x1 = %lf, x2 = %lf, count_of_roots = %d.\n"
                "Expected: x1 = %lf, x2 = %lf, count_of_roots = %d.\n",
                num_of_test,
                coeff_a, coeff_b, coeff_c,
                solution_x1, solution_x2, count_of_roots,
                solution_x1_expected, solution_x2_expected, count_of_different_roots_expected);
        return 1;
    }
    return 0;
}
