#include "flags.h"

#include <stdio.h>
#include <cstring>

#include "tester.h"
#include "input.h"      
#include "solver.h"     
#include "output.h"
#include "formatting.h"

void start_program(void)
{
    read_and_run_tests(PRINT_OFF);

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
}

void info(void)
{
    puts("The program was created by the developer Alex Lavr");
    puts("The program solves equations of no more than the second degree");
    puts("You can use the following compilation flags:");
    puts("--user     to run the program");
    puts("--help     to get information about the program");
    puts("--test     to test the program");
    puts("--version  to get information about the version of the program");
}

void test(void)
{
    if (!read_and_run_tests(PRINT_ON))
    {
        puts( COLOR_BLUE FORMAT_BOLD 
        "\nAll tests passed successfully\n" 
        COLOR_BLUE FORMAT_BOLD);
    }
    else
    {
        puts( COLOR_BLUE FORMAT_BOLD 
        "\nThere are failed tests\n" 
        COLOR_BLUE FORMAT_BOLD);
    }
}

void version(void)
{
    puts("Program version 2.0");
}

enum compilationFlag check_flag_number(const int argc, const char * argv[])
{
    if (!strcmp(argv[1], "--user"))
    {
        return USER;
    }
    else if (!strcmp(argv[1], "--help"))
    {
        return INFO;
    }
    else if (!strcmp(argv[1], "--test"))
    {
        return TEST;
    }
    else if (!strcmp(argv[1], "--version"))
    {
        return VERSION;  
    }
    else
        return ERROR;
}