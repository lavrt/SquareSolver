#include <stdio.h>
#include <stdbool.h>
#include <math.h>
//#include <assert.h>

const double epsilon = 1e-8;

enum nRoots
{
    NO_SOLUTIONS = 0,
    ONE_SOLUTION = 1,
    TWO_SOLUTIONS = 2,
    ANY_NUMBER = 3,
};

void program_get_num(double * coeff_a, double * coeff_b, double * coeff_c);
int program_solve_equation(double coeff_a, double coeff_b, double coeff_c, double * solution_x1, double * solution_x2);
void program_print_solutions(double coeff_a, double coeff_b, double coeff_c, double solution_x1, double solution_x2);
bool double_equals(double num1, double num2);
bool program_continue(void);
int clear_buffer(void);
void print_equation(double * coeff_a, double * coeff_b, double * coeff_c);
void take_values(double * coeff_a, double * coeff_b, double * coeff_c);

int main(void)
{
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

    } while (program_continue());

    return 0;
}

void program_get_num(double * coeff_a, double * coeff_b, double * coeff_c)
{
    do
    {
        printf("To get started, enter the values of the "
                "coefficients of the quadratic equation.\n\n");

        take_values(coeff_a, coeff_b, coeff_c);

        print_equation(coeff_a, coeff_b, coeff_c);

        printf("\nAre the coefficients correct? ");
        if (program_continue())            //get choice
        {
            printf("The coefficients are saved.\n");
            break;
        }

    } while (true);
}

bool double_equals(double num1, double num2)
{
    return fabs(num1 - num2) < epsilon;
}

bool program_continue(void)
{
    printf("Enter 'y' if you want to continue, otherwise enter 'n': ");

    int ch = 0;
    while ((ch = getchar()) != 'y' && ch != 'n')
    {
        if (ch != '\n')
            printf("Enter 'y' or 'n' without quotes.\n");
        if (ch == '\n') continue;
        clear_buffer();
    }

    return ch == 'y';
}

int clear_buffer(void)
{
    int ch = 0;
    while (((ch = getchar()) != '\n') && ch != EOF) continue;
    return !(ch == '\n');
}

void take_values(double * coeff_a, double * coeff_b, double * coeff_c)
{
    printf("Enter a: ");
    while (scanf("%lf", coeff_a) != 1)
    {
        printf("\nPlease enter the correct numeric value.\nEnter a: ");
        clear_buffer();
    }
    clear_buffer();

    printf("Enter b: ");
    while (scanf("%lf", coeff_b) != 1)
    {
        printf("\nPlease enter the correct numeric value.\nEnter b: ");
        clear_buffer();
    }
    clear_buffer();

    printf("Enter c: ");
    while (scanf("%lf", coeff_c) != 1)
    {
        printf("\nPlease enter the correct numeric value.\nEnter c: ");
        clear_buffer();
    }
    clear_buffer();
}

void print_equation(double * coeff_a, double * coeff_b, double * coeff_c)
{
    printf("\nThe equation you want to solve:\n");
    printf("%lf*x^2 %+lf*x %+lf = 0\n", *coeff_a, *coeff_b, *coeff_c);
}

int program_solve_equation(double coeff_a, double coeff_b, double coeff_c, double * solution_x1, double * solution_x2)
{
/*  assert (std::isfinite (coeff_a));
    assert (std::isfinite (coeff_b));
    assert (std::isfinite (coeff_c));

    assert (solution_x1 != NULL);
    assert (solution_x2 != NULL);
    assert (solution_x1 != solution_x2); */

    enum nRoots count_of_roots;                     // ������� �������� � ������������ ������
    if (double_equals(coeff_a, 0))
    {
        if (double_equals(coeff_b, 0))
        {
            count_of_roots = (double_equals(coeff_c, 0)) ? ANY_NUMBER : NO_SOLUTIONS;
        }

        *solution_x1 = -(coeff_c / coeff_b);
        *solution_x2 = -(coeff_c / coeff_b);
        count_of_roots = ONE_SOLUTION;
    }

    double discriminant = coeff_b * coeff_b - 4 * coeff_a * coeff_c;

    if (double_equals(discriminant, 0))
    {
        *solution_x1 = -coeff_b / (2 * coeff_a);
        *solution_x2 = -coeff_b / (2 * coeff_a);
        count_of_roots = ONE_SOLUTION;
    }

    if (discriminant > 0)
    {
        *solution_x1 = (-coeff_b - sqrt(discriminant)) / (2 * coeff_a);
        *solution_x2 = (-coeff_b + sqrt(discriminant)) / (2 * coeff_a);
        count_of_roots = TWO_SOLUTIONS;
    }

    if (discriminant < 0)
    {
        *solution_x1 = NAN;
        *solution_x2 = NAN;
        count_of_roots = NO_SOLUTIONS;
    }

    return count_of_roots;
}

void program_print_solutions(double coeff_a, double coeff_b, double coeff_c, double solution_x1, double solution_x2)
{
    switch (program_solve_equation(coeff_a, coeff_b, coeff_c, &solution_x1, &solution_x2))      // вынести в переменную
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


