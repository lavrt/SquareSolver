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
*Завершает выполнение программы
*\param[in] num Число для проверки на конечность
*/
void my_assert(bool statement); // , const char * error_message

/**
*Проверяет, является ли число конечным.
*\param[in] num Число для проверки на конечность
*/
bool my_isfinite(double num);

#endif // SUPPORTIVE_H