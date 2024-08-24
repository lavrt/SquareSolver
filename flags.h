#ifndef FLAGS_H
#define FLAGS_H

/*!
\file 
*/

enum compilationFlag
{
    ERROR = -1,
    USER = 0,
    INFO = 1,
    TEST = 2,
    VERSION = 3,
};

void start_program(void);
void info(void);
void test(void);
void version(void);
enum compilationFlag check_flag_number(const int argc, const char * argv[]);

#endif // FLAGS_H