/*!
\file
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

struct testData
{
    int num_of_test;
    double coeff_a;
    double coeff_b;
    double coeff_c; 
    double solution_x1_expected;
    double solution_x2_expected; 
    int count_of_different_roots_expected;
};

const double epsilon = 1e-8;

enum nRoots
{
    NO_SOLUTIONS = 0,
    ONE_SOLUTION = 1,
    TWO_SOLUTIONS = 2,
    ANY_NUMBER = 3,
}; 

enum condition
{
    SUCCESS = 0,
    FAILURE = 1,
};

/**
*Запрашивает у пользователя ввод коэффициентов.
*Повторяет ввод в цикле, если пользователь желает решить еще одно квадратное уравнение.
*\param[in] coeff_a Указатель на коэффициент a
*\param[in] coeff_b Указатель на коэффициент b
*\param[in] coeff_c Указатель на коэффициент c
*/
void program_get_num(double * coeff_a, double * coeff_b, double * coeff_c);

//-----------------------------------------------------------
/**
*Решает уравнение степени не более 2.
*\param[in] coeff_a Коэффициент a
*\param[in] coeff_b Коэффициент b
*\param[in] coeff_c Коэффициент c
*\param[in] solution_x1 Указатель на первый корень уравнения
*\param[in] solution_x2 Указатель на второй корень уравнения
*/
//-----------------------------------------------------------
enum nRoots program_solve_equation(double coeff_a, double coeff_b, double coeff_c, double * solution_x1, double * solution_x2);

/**
*Выводит решения квадратного уравнения.
*\param[in] coeff_a Коэффициент a
*\param[in] coeff_b Коэффициент b
*\param[in] coeff_c Коэффициент c
*\param[in] solution_x1 Первый корень уравнения
*\param[in] solution_x2 Второй корень уравнения
*/
void program_print_solutions(double coeff_a, double coeff_b, double coeff_c, double solution_x1, double solution_x2);

/**
*С заданной точностью определяет, равны ли два параметра типа double друг другу.
*\param[in] num1 Первый параметр
*\param[in] num2 Второй параметр
*/
bool double_equals(double num1, double num2);

/**
*Спрашивает у пользователя, желает ли онт продолжить выполнение программы или начать ввод заново.
*/
bool get_choice(void);

/**
*Очищает буфер stdin.
*/
int clear_buffer(void);

/**
*Выводит уравнение, которое желает решить пользователь.
*\param[in] coeff_a Указатель на коэффициент a
*\param[in] coeff_b Указатель на коэффициент b
*\param[in] coeff_c Указатель на коэффициент c
*/
void print_equation(double * coeff_a, double * coeff_b, double * coeff_c);

/**
*Запрашивает у пользователя ввод коэффициентов.
*\param[in] coeff_a Указатель на коэффициент a
*\param[in] coeff_b Указатель на коэффициент b
*\param[in] coeff_c Указатель на коэффициент c
*/
void take_values(double * coeff_a, double * coeff_b, double * coeff_c);

/**
*Решает квадратное уравнение. Изменяет переменные, содержащие корни уравнения, по указателю.
*\param[in] coeff_a Коэффициент a
*\param[in] coeff_b Коэффициент b
*\param[in] coeff_c Коэффициент c
*\param[in] solution_x1 Указатель на первый корень уравнения
*\param[in] solution_x2 Указатель на второй корень уравнения
*/
enum nRoots solver_quadratic_equation(double coeff_a, double coeff_b, double coeff_c, double * solution_x1, double * solution_x2);

/**
*Решает линейное уравнение. Изменяет переменные, содержащие корни уравнения, по указателю.
*\param[in] coeff_b Коэффициент b
*\param[in] coeff_c Коэффициент c
*\param[in] solution_x1 Указатель на первый корень уравнения
*\param[in] solution_x2 Указатель на второй корень уравнения
*/
enum nRoots solver_linear_equation(double coeff_b, double coeff_c, double * solution_x1, double * solution_x2);

/**
*Меняет значения двух параметров местами.
*Передаются указатели на параметры.
*\param[in] num1 Первый параметр
*\param[in] num2 Второй параметр
*/
void swap(double * num1, double * num2);

/**
*Запускает тест квадратного уравнения.
*/
enum condition run_test(struct testData * data);

/**
*С заданной точностью пределяет, равны ли два параметра типа double друг другу.
*Способна определить, являются ли оба параметра NaN.
*\param[in] num1 Первый параметр
*\param[in] num2 Второй параметр
*/
bool double_equals_with_support_nan(double num1, double num2);

/**
*Тестирует программу.
*/
void program_testing(void);

#include "solver.cpp"

int main(void)
{
    program_testing();

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
    } while (get_choice());

    return 0;
}

void program_get_num(double * coeff_a, double * coeff_b, double * coeff_c)
{
    assert (coeff_a != NULL);
    assert (coeff_b != NULL);
    assert (coeff_c != NULL);
    assert (coeff_a != coeff_b);
    assert (coeff_b != coeff_c);
    assert (coeff_a != coeff_c);
    
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

bool double_equals(double num1, double num2)
{
    return fabs(num1 - num2) < epsilon;
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

void take_values(double * coeff_a, double * coeff_b, double * coeff_c)
{
    assert (coeff_a != NULL);
    assert (coeff_b != NULL);
    assert (coeff_c != NULL);
    assert (coeff_a != coeff_b);
    assert (coeff_b != coeff_c);
    assert (coeff_a != coeff_c);
    
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
    assert (coeff_a != NULL);
    assert (coeff_b != NULL);
    assert (coeff_c != NULL);
    assert (coeff_a != coeff_b);
    assert (coeff_b != coeff_c);
    assert (coeff_a != coeff_c);
    
    printf("\nThe equation you want to solve:\n");
    printf("%lf*x^2 %+lf*x %+lf = 0\n", *coeff_a, *coeff_b, *coeff_c);
}

void program_print_solutions(double coeff_a, double coeff_b, double coeff_c, double solution_x1, double solution_x2)
{
    int count_of_roots = program_solve_equation(coeff_a, coeff_b, coeff_c, &solution_x1, &solution_x2);
    switch (count_of_roots) 
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

int clear_buffer(void)
{
    int ch = 0;
    while (((ch = getchar()) != '\n') && ch != EOF) continue;
    return !(ch == '\n');
}

void program_testing(void) // void to int
{  
    struct testData array_of_tests[] =
    { //  num_of_test  coeff_a  coeff_b  coeff_c  solution_x1  solution_x2  count_of_different_roots 
        {      1,         0,       0,       0,        NAN,         NAN,            ANY_NUMBER        }, 
        {      2,         0,       0,       9,        NAN,         NAN,          NO_SOLUTIONS        }, // add test with coeff float point
        {      3,         0,       2,       6,         -3,          -3,          ONE_SOLUTION        },
        {      4,         1,      -2,       1,          1,           1,          ONE_SOLUTION        },
        {      5,         2,      -7,       5,          1,         2.5,         TWO_SOLUTIONS        },
        {      6,         1,       1,       1,        NAN,         NAN,          NO_SOLUTIONS        },
    };
    
    int count_of_tests = sizeof(array_of_tests) / sizeof(array_of_tests[0]);
    
    for (int index = 0; index < count_of_tests; ++index)
    {
        run_test(&array_of_tests[index]);
    }   
}