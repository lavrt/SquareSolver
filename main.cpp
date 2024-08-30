#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#include "flags.h"
#include "tester.h"
#include "input.h"
#include "solver.h"
#include "output.h"
#include "formatting.h"
#include "supportive.h"

int main(const int argc, const char * argv[])
{
    if (argc == 1)
    {
        printf("Enter the %s compilation flag for help.\n", USER_FLAG);
        return 0;
    }

    compilationFlag compilation_flag = check_flag_number(argc, argv);

    switch (compilation_flag)
    {
        case USER:
            start_program();
            break;
        case INFO:
            info();
            break;
        case TEST:
            test();
            break;
        case VERSION:
            version();
            break;
        case ERROR:
            fprintf(stderr, "Unexpected error!\n");
            return EXIT_FAILURE;
        default:
            ASSERT(0, "Unknown flag");
    }

    return 0;
}
