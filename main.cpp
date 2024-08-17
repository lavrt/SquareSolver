#include <stdio.h>
#include <stdbool.h>
#include <math.h>

const double epsilon = 1e-8;

void program(void);
void get_num(double * coeff_a, double * coeff_b, double * coeff_c);
bool double_equals(double num1, double num2);
double solving_linear_equation(double coeff_b, double coeff_c);
void solving_quadratic_equation(double coeff_a, double coeff_b, double discriminant, double * solution_x1, double * solution_x2);
bool program_continue(void);
void clear_buffer(void);

int main(void)
{
    do
    {
        program();
    } while (program_continue());

    return 0;
}

void program(void)
{
    double coeff_a = 0;
    double coeff_b = 0;
    double coeff_c = 0;

    get_num(&coeff_a, &coeff_b, &coeff_c);

    printf("The coefficients are saved.\n");

    if (double_equals(coeff_a, 0))
    {
        printf("\nThe equation is linear.\nAnswer: x = %lf\n", solving_linear_equation(coeff_b, coeff_c));
    }
    else
    {
        double discriminant = coeff_b * coeff_b - 4 * coeff_a * coeff_c;
        double solution_x1 = 0;
        double solution_x2 = 0;
        solving_quadratic_equation(coeff_a, coeff_b, discriminant, &solution_x1, &solution_x2);

        if (double_equals(discriminant, 0))
        {
            printf("\nThe equation is quadratic and has two equal solutions.\nAnswer: x1 = %lf, x2 = %lf\n", solution_x1, solution_x2);
        }
        else if (discriminant > 0)
        {
            printf("\nThe equation is quadratic and has two different solutions.\nAnswer: x1 = %lf, x2 = %lf\n", solution_x1, solution_x2);
        }
        else if (discriminant < 0)
        {
            printf("\nThere are no solutions in real numbers.\n");
        }  // add solving in complex numbers later
    }
}

void get_num(double * coeff_a, double * coeff_b, double * coeff_c)
{
    do
    {
        printf("To get started, enter the values of the "
                "coefficients of the quadratic equation.\n\n");

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

        printf("\nThe equation you want to solve:\n");
        printf("%lf*x^2 %+lf*x %+lf = 0\n", *coeff_a, *coeff_b, *coeff_c);
        printf("Enter 'y' if you want to continue or 'n' if you want to change the coefficients: ");

        int ch = 0;
        while ((ch = getchar()) != 'y' && ch != 'n')
        {
            printf("Enter 'y' or 'n' without quotes.\n");
            if (ch == '\n') continue;
            clear_buffer();
        }

        if (ch == 'y') break;

    } while (true);
}

bool double_equals(double num1, double num2)
{
    return fabs(num1 - num2) < epsilon;
}

double solving_linear_equation(double coeff_b, double coeff_c)
{
    return -(coeff_b / coeff_c);
}

void solving_quadratic_equation(double coeff_a, double coeff_b, double discriminant, double * solution_x1, double * solution_x2)
{
    if (discriminant >= 0)
    {
        *solution_x1 = (-coeff_b - sqrt(discriminant)) / (2 * coeff_a);
        *solution_x2 = (-coeff_b + sqrt(discriminant)) / (2 * coeff_a);
    }
    else if (discriminant < 0) // add solving in complex numbers later
    {
        *solution_x1 = NAN;
        *solution_x2 = NAN;
    }
}

bool program_continue(void)
{
    getchar();

    printf("\n\n\nDo you want to solve the equation again? Enter 'y' if you want to continue or 'q' to exit: ");

    int ch = 0;
    while ((ch = getchar()) != 'y' && ch != 'q')
    {
        printf("Enter 'y' or 'q' without quotes.\n");
        if (ch == '\n') continue;
        clear_buffer();
    }

    return ch == 'y';
}

void clear_buffer(void)
{
    int ch = 0;
    while ((ch = getchar() != '\n') && ch != EOF) continue;
}
