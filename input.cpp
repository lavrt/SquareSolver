#include "input.h"

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

#include "supportive.h"

void program_get_num(double * coeff_a, double * coeff_b, double * coeff_c)
{
    ASSERT(coeff_a != NULL, "The pointer to the coefficient a is NULL.");
    ASSERT(coeff_b != NULL, "The pointer to the coefficient b is NULL.");
    ASSERT(coeff_c != NULL, "The pointer to the coefficient c is NULL.");
    ASSERT(coeff_a != coeff_b, "The pointers to the coefficients occupied one memory cell.");
    ASSERT(coeff_b != coeff_c, "The pointers to the coefficients occupied one memory cell.");
    ASSERT(coeff_a != coeff_c, "The pointers to the coefficients occupied one memory cell.");
    
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

    } while (getchar() != EOF);
}

void take_values(double * coeff_a, double * coeff_b, double * coeff_c)
{
    ASSERT(coeff_a != NULL, "The pointer to the coefficient a is NULL.");
    ASSERT(coeff_b != NULL, "The pointer to the coefficient b is NULL.");
    ASSERT(coeff_c != NULL, "The pointer to the coefficient c is NULL.");
    ASSERT(coeff_a != coeff_b, "The pointers to the coefficients occupied one memory cell.");
    ASSERT(coeff_b != coeff_c, "The pointers to the coefficients occupied one memory cell.");
    ASSERT(coeff_a != coeff_c, "The pointers to the coefficients occupied one memory cell.");
    
    int char_accepted = 0;
    printf("Enter a: ");
    for (int number_of_attempts = 0; (((char_accepted = scanf("%lf", coeff_a)) && detecting_number())
        || (char_accepted != 1)); ++number_of_attempts)
    {
        printf("\nPlease enter the correct numeric value.\nEnter a: ");
        clear_buffer();
    }
    
    printf("Enter b: ");
    for (int number_of_attempts = 0; (((char_accepted = scanf("%lf", coeff_b)) && detecting_number())
        || (char_accepted != 1)); ++number_of_attempts)
    {
        printf("\nPlease enter the correct numeric value.\nEnter b: ");
        clear_buffer();
    }

    printf("Enter c: ");
    for (int number_of_attempts = 0; (((char_accepted = scanf("%lf", coeff_c)) && detecting_number())
        || (char_accepted != 1)); ++number_of_attempts)
    {
        printf("\nPlease enter the correct numeric value.\nEnter c: ");
        clear_buffer();
    }    
}


void print_equation(double * coeff_a, double * coeff_b, double * coeff_c)
{
    ASSERT(coeff_a != NULL, "The pointer to the coefficient a is NULL.");
    ASSERT(coeff_b != NULL, "The pointer to the coefficient b is NULL.");
    ASSERT(coeff_c != NULL, "The pointer to the coefficient c is NULL.");
    ASSERT(coeff_a != coeff_b, "The pointers to the coefficients occupied one memory cell.");
    ASSERT(coeff_b != coeff_c, "The pointers to the coefficients occupied one memory cell.");
    ASSERT(coeff_a != coeff_c, "The pointers to the coefficients occupied one memory cell.");
    
    printf("\nThe equation you want to solve:\n");
    printf("%lg*x^2 %+lg*x %+lg = 0\n", *coeff_a, *coeff_b, *coeff_c);
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
    while ((ch = getchar()) != 'y' && ch != 'n' && ch != EOF)
    {
        if (ch != '\n')
            printf("Enter 'y' or 'n' without quotes.\n");
        if (ch == '\n') continue;
        clear_buffer();
    }

    return ch == 'y';
}

bool detecting_number(void)
{
    int ch = getchar();
    while (!isdigit(ch) && ch != '\n')   
    {
        ch = getchar();
    }
    return (isdigit(ch)) ? true : false;
}