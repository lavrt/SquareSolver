#ifndef SOLVER_H
#define SOLVER_H

/*!
\file
*/

const double epsilon = 1e-8;

enum nRoots
{
    NO_SOLUTIONS = 0,
    ONE_SOLUTION = 1,
    TWO_SOLUTIONS = 2,
    ANY_NUMBER = 3,
}; 

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

//-----------------------------------------------------------
/**
*Решает квадратное уравнение. Изменяет переменные, содержащие корни уравнения, по указателю.
*\param[in] coeff_a Коэффициент a
*\param[in] coeff_b Коэффициент b
*\param[in] coeff_c Коэффициент c
*\param[in] solution_x1 Указатель на первый корень уравнения
*\param[in] solution_x2 Указатель на второй корень уравнения
*/
//-----------------------------------------------------------
enum nRoots solver_quadratic_equation(double coeff_a, double coeff_b, double coeff_c, double * solution_x1, double * solution_x2);

//-----------------------------------------------------------
/**
*Решает линейное уравнение. Изменяет переменные, содержащие корни уравнения, по указателю.
*\param[in] coeff_b Коэффициент b
*\param[in] coeff_c Коэффициент c
*\param[in] solution_x1 Указатель на первый корень уравнения
*\param[in] solution_x2 Указатель на второй корень уравнения
*/
//-----------------------------------------------------------
enum nRoots solver_linear_equation(double coeff_b, double coeff_c, double * solution_x1, double * solution_x2);

//-----------------------------------------------------------
/**
*Меняет значения двух параметров местами.
*Передаются указатели на параметры.
*\param[in] num1 Первый параметр
*\param[in] num2 Второй параметр
*/
//-----------------------------------------------------------
void swap(double * num1, double * num2);

//-----------------------------------------------------------
/**
*С заданной точностью пределяет, равны ли два параметра типа double друг другу.
*\param[in] num1 Первый параметр
*\param[in] num2 Второй параметр
*/
//-----------------------------------------------------------
bool double_equals(double num1, double num2);

//-----------------------------------------------------------
/**
*С заданной точностью определяет, равны ли два параметра типа double друг другу.
*\param[in] num1 Первый параметр
*\param[in] num2 Второй параметр
*/
//-----------------------------------------------------------
bool double_equals(double num1, double num2);

#endif // SOLVER_H