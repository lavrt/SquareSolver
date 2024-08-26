#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <cstring>

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
        puts("Enter the --help compilation flag for help.");
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
        default:
            ASSERT(0, "Unknown flag");
    }

    return 0;
}