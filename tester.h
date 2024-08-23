#ifndef TESTER_H
#define TESTER_H

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

enum condition
{
    SUCCESS = 0,
    FAILURE = 1,
};

//-----------------------------------------------------------
/**
*Тестирует программу.
*/
//-----------------------------------------------------------
void program_testing(void);

//-----------------------------------------------------------
/**
*Запускает тест квадратного уравнения.
*/
//-----------------------------------------------------------
enum condition run_test(struct testData * data);

//-----------------------------------------------------------
/**
*С заданной точностью пределяет, равны ли два параметра типа double друг другу.
*Способна определить, являются ли оба параметра NaN.
*\param[in] num1 Первый параметр
*\param[in] num2 Второй параметр
*/
//-----------------------------------------------------------
bool double_equals_with_support_nan(double num1, double num2);

#endif