#ifndef SUPPORTIVE_H
#define SUPPORTIVE_H

/*!
\file
*/

/**
*Проверяет, является ли число NaN.
*\param[in] num Число для проверки на NaN
*/
bool my_isnan(double num);

/**
*Завершает выполнение программы, если выражение имеет значеие false.
*\param[in] statement Проверяемое выражение
*\param[in] file_name Имя файла, в котором не прошло проверку выражение statement
*\param[in] number_of_string Номер строки, на которой не прошло проверку выражение statement
*\param[in] func_name Имя функции, в которой не прошло проверку выражение statement
*/
void my_assert(bool statement, const char * error_message, const char * file_name, int number_of_string, const char * func_name); 

/**
*Проверяет, является ли число конечным.
*\param[in] num Число для проверки на конечность
*/
bool my_isfinite(double num);

#endif // SUPPORTIVE_H