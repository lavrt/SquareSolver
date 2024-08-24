#include "input.h"

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "supportive.h"

void program_get_num(double * coeff_a, double * coeff_b, double * coeff_c)
{
    my_assert (coeff_a != NULL, "The pointer to the coefficient a is NULL.", __FILE__, __LINE__, __func__);
    my_assert (coeff_b != NULL, "The pointer to the coefficient b is NULL.", __FILE__, __LINE__, __func__);
    my_assert (coeff_c != NULL, "The pointer to the coefficient c is NULL.", __FILE__, __LINE__, __func__);
    my_assert (coeff_a != coeff_b, "The pointers to the coefficients occupied one memory cell.", __FILE__, __LINE__, __func__);
    my_assert (coeff_b != coeff_c, "The pointers to the coefficients occupied one memory cell.", __FILE__, __LINE__, __func__);
    my_assert (coeff_a != coeff_c, "The pointers to the coefficients occupied one memory cell.", __FILE__, __LINE__, __func__);
    
    do
    {
        printf("To get started, enter the values of the coefficients of the quadratic equation.\n\n");

        take_values(coeff_a, coeff_b, coeff_c);

        print_equation(coeff_a, coeff_b, coeff_c);

        printf("\nAre the coefficients correct? ");
        if (get_choice())            
        {
            printf("The coefficients are saved.\n");
            break;
        }

    } while (true);
}

void take_values(double * coeff_a, double * coeff_b, double * coeff_c)
{
    my_assert (coeff_a != NULL, "The pointer to the coefficient a is NULL.", __FILE__, __LINE__, __func__);
    my_assert (coeff_b != NULL, "The pointer to the coefficient b is NULL.", __FILE__, __LINE__, __func__);
    my_assert (coeff_c != NULL, "The pointer to the coefficient c is NULL.", __FILE__, __LINE__, __func__);
    my_assert (coeff_a != coeff_b, "The pointers to the coefficients occupied one memory cell.", __FILE__, __LINE__, __func__);
    my_assert (coeff_b != coeff_c, "The pointers to the coefficients occupied one memory cell.", __FILE__, __LINE__, __func__);
    my_assert (coeff_a != coeff_c, "The pointers to the coefficients occupied one memory cell.", __FILE__, __LINE__, __func__);
    
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
    my_assert (coeff_a != NULL, "The pointer to the coefficient a is NULL.", __FILE__, __LINE__, __func__);
    my_assert (coeff_b != NULL, "The pointer to the coefficient b is NULL.", __FILE__, __LINE__, __func__);
    my_assert (coeff_c != NULL, "The pointer to the coefficient c is NULL.", __FILE__, __LINE__, __func__);
    my_assert (coeff_a != coeff_b, "The pointers to the coefficients occupied one memory cell.", __FILE__, __LINE__, __func__);
    my_assert (coeff_b != coeff_c, "The pointers to the coefficients occupied one memory cell.", __FILE__, __LINE__, __func__);
    my_assert (coeff_a != coeff_c, "The pointers to the coefficients occupied one memory cell.", __FILE__, __LINE__, __func__);
    
    printf("\nThe equation you want to solve:\n");
    printf("%lf*x^2 %+lf*x %+lf = 0\n", *coeff_a, *coeff_b, *coeff_c);
}

int clear_buffer(void)
{
    int ch = 0;
    while (((ch = getchar()) != '\n') && ch != EOF) continue;
    return !(ch == '\n');
}

bool get_choice(void)
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