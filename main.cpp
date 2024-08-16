// program for solving quadratic equations
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
void get_num(double *, double *, double *);
bool input_is_incorrect(double, double, double);
bool double_equals(double, double, double);
double solving_linear_equation(double, double);
void solving_quadratic_equation(double, double, double, double *, double *);

int main(void)
{
    const double epsilon = 1e-6;
    double a, b, c;
    get_num(&a, &b, &c);
    while (input_is_incorrect(a, b, c)){
        printf("\n\n\n");
        get_num(&a, &b, &c);
    }
    printf("The coefficients are saved.\n");

    if (double_equals(a, 0, epsilon))
    {
        printf("\nThe equation is linear.\nAnswer: x = %lf\n", solving_linear_equation(b, c));
    }
    else
    {
        double discriminant = b * b - 4 * a * c;
        double x1, x2;
        solving_quadratic_equation(a, b, discriminant, &x1, &x2);
        if (double_equals(discriminant, 0, epsilon))
        {
            printf("\nThe equation is quadratic and has two equal solutions.\nAnswer: x1 = %lf, x2 = %lf\n", x1, x2);
        }
        else if (discriminant < 0)
        {
            printf("\nThere are no solutions in real numbers.\n");
        }
        else if (discriminant > 0)
        {
            printf("\nThe equation is quadratic and has two different solutions.\nAnswer: x1 = %lf, x2 = %lf\n", x1, x2);
        }
    }

    return 0;
}




void get_num(double * ad_a, double * ad_b, double * ad_c)
{
    printf("To get started, enter the values of the "
            "coefficients of the quadratic equation.\n\n");

    printf("Enter a: ");
    while (scanf("%lf", ad_a) != 1){
        printf("\nPlease enter the correct numeric value.\nEnter a: ");
        while (getchar() != '\n') continue;
    }

    printf("Enter b: ");
    while (scanf("%lf", ad_b) != 1){
        printf("\nPlease enter the correct numeric value.\nEnter b: ");
        while (getchar() != '\n') continue;
    }

    printf("Enter c: ");
    while (scanf("%lf", ad_c) != 1){
        printf("\nPlease enter the correct numeric value.\nEnter c: ");
        while (getchar() != '\n') continue;
    }
}




bool input_is_incorrect(double a, double b, double c)
{
    getchar();

    printf("\nThe equation you want to solve:\n");
    printf("%lf*x^2 %+lf*x %+lf = 0\n", a, b, c);
    printf("Enter 'y' if you want to continue or 'n' if you want to change the coefficients: ");

    int ch;
    while ((ch = getchar()) != 'y' && ch != 'n'){
        printf("Enter 'y' or 'n' without quotes.\n");
        if (ch == '\n') continue;
        while ((getchar()) != '\n') continue;
    }

    return (ch == 'n') ? true : false;
}




double solving_linear_equation(double b, double c)
{
    return -(b / c);
}




void solving_quadratic_equation(double a, double b, double discriminant, double * ad_x1, double * ad_x2)
{
    *ad_x1 = (-b - sqrt(discriminant)) / (2 * a);
    *ad_x2 = (-b + sqrt(discriminant)) / (2 * a);
}




bool double_equals(double num1, double num2, double epsilon)
{
    return fabs(num1 - num2) < epsilon;
}



