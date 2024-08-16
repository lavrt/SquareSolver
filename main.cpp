#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define EPSILON 1e-8

void get_num(double * ad_a, double * ad_b, double * ad_c);
bool input_is_incorrect(double coeff_a, double coeff_b, double coeff_c);
bool double_equals(double num1, double num2);
double solving_linear_equation(double coeff_b, double coeff_c);
void solving_quadratic_equation(double coeff_a, double coeff_b, double discriminant, double * ad_x1, double * ad_x2);
bool program_continue(void);

int main(void)
{
    do
    {
        double coeff_a = 0;
        double coeff_b = 0;
        double coeff_c = 0;
        get_num(&coeff_a, &coeff_b, &coeff_c);
        while (input_is_incorrect(coeff_a, coeff_b, coeff_c))
        {
            printf("\n\n\n");
            get_num(&coeff_a, &coeff_b, &coeff_c);
        }
        printf("The coefficients are saved.\n");

        if (double_equals(coeff_a, 0))
        {
            printf("\nThe equation is linear.\nAnswer: x = %lf\n", solving_linear_equation(coeff_b, coeff_c));
        }
        else
        {
            double discriminant = coeff_b * coeff_b - 4 * coeff_a * coeff_c;
            double x1, x2;
            solving_quadratic_equation(coeff_a, coeff_b, discriminant, &x1, &x2);

            if (double_equals(discriminant, 0))
            {
                printf("\nThe equation is quadratic and has two equal solutions.\nAnswer: x1 = %lf, x2 = %lf\n", x1, x2);
            }
            else if (discriminant > 0)
            {
                printf("\nThe equation is quadratic and has two different solutions.\nAnswer: x1 = %lf, x2 = %lf\n", x1, x2);
            }
            else if (discriminant < 0)
            {
                printf("\nThere are no solutions in real numbers.\n");
            }  // add solving in complex numbers later
        }
    } while (program_continue());

    return 0;
}

void get_num(double * ad_a, double * ad_b, double * ad_c)
{
    printf("To get started, enter the values of the "
            "coefficients of the quadratic equation.\n\n");

    printf("Enter a: ");
    while (scanf("%lf", ad_a) != 1)
    {
        printf("\nPlease enter the correct numeric value.\nEnter a: ");
        while (getchar() != '\n') continue;
    }

    printf("Enter b: ");
    while (scanf("%lf", ad_b) != 1)
    {
        printf("\nPlease enter the correct numeric value.\nEnter b: ");
        while (getchar() != '\n') continue;
    }

    printf("Enter c: ");
    while (scanf("%lf", ad_c) != 1)
    {
        printf("\nPlease enter the correct numeric value.\nEnter c: ");
        while (getchar() != '\n') continue;
    }
}

bool input_is_incorrect(double coeff_a, double coeff_b, double coeff_c)
{
    getchar();

    printf("\nThe equation you want to solve:\n");
    printf("%lf*x^2 %+lf*x %+lf = 0\n", coeff_a, coeff_b, coeff_c);
    printf("Enter 'y' if you want to continue or 'n' if you want to change the coefficients: ");

    int ch;
    while ((ch = getchar()) != 'y' && ch != 'n')
    {
        printf("Enter 'y' or 'n' without quotes.\n");
        if (ch == '\n') continue;
        while ((getchar()) != '\n') continue;
    }

    return ch == 'n';
}

bool double_equals(double num1, double num2)
{
    return fabs(num1 - num2) < EPSILON;
}

double solving_linear_equation(double coeff_b, double coeff_c)
{
    return -(coeff_b / coeff_c);
}

void solving_quadratic_equation(double coeff_a, double coeff_b, double discriminant, double * ad_x1, double * ad_x2)
{
    if (discriminant >= 0)
    {
        *ad_x1 = (-coeff_b - sqrt(discriminant)) / (2 * coeff_a);
        *ad_x2 = (-coeff_b + sqrt(discriminant)) / (2 * coeff_a);
    }
    else if (discriminant < 0)
    {
        // add solving in complex numbers later
    }
}

bool program_continue(void)
{
    getchar();

    printf("\n\n\nDo you want to solve the equation again? Enter 'y' if you want to continue or 'q' to exit: ");

    int ch;
    while ((ch = getchar()) != 'y' && ch != 'q')
    {
        printf("Enter 'y' or 'n' without quotes.\n");
        if (ch == '\n') continue;
        while (getchar() != '\n') continue;
    }

    return ch == 'y';
}
