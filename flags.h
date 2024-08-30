#ifndef FLAGS_H
#define FLAGS_H

/*!
\file
*/

static const char * USER_FLAG    = "--user";
static const char * TEST_FLAG    = "--test";
static const char * HELP_FLAG    = "--help";
static const char * VERSION_FLAG = "--version";

enum compilationFlag
{
    ERROR   = -1,
    USER    =  0,
    INFO    =  1,
    TEST    =  2,
    VERSION =  3,
};

//-----------------------------------------------------------
/**
*Старт программы.
*/
//-----------------------------------------------------------
void start_program(void);

//-----------------------------------------------------------
/**
*Просмотр информации о программе.
*/
//-----------------------------------------------------------
void info(void);

//-----------------------------------------------------------
/**
*Запуск тестов.
*/
//-----------------------------------------------------------
void test(void);

//-----------------------------------------------------------
/**
*Просмотр информации о версии программы.
*/
//-----------------------------------------------------------
void version(void);

//-----------------------------------------------------------
/**
*Преобразует флаги компиляции в числовые значения.
*/
//-----------------------------------------------------------
enum compilationFlag check_flag_number(const int argc, const char * argv[]);

#endif // FLAGS_H
