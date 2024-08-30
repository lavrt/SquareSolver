#ifndef OUTPUT_H
#define OUTPUT_H

#include "solver.h"

/*!
\file
*/

//-----------------------------------------------------------
/**
*Выводит решения квадратного уравнения.
*\param[in] coeff_a Коэффициент a
*\param[in] coeff_b Коэффициент b
*\param[in] coeff_c Коэффициент c
*\param[in] solution_x1 Первый корень уравнения
*\param[in] solution_x2 Второй корень уравнения
*/
//-----------------------------------------------------------
void program_print_solutions(enum nRoots count_of_roots, double solution_x1, double solution_x2);

#endif // OUTPUT_H
