#ifndef INPUT_H
#define INPUT_H

/**
*Запрашивает у пользователя ввод коэффициентов.
*Повторяет ввод в цикле, если пользователь желает решить еще одно квадратное уравнение.
*\param[in] coeff_a Указатель на коэффициент a
*\param[in] coeff_b Указатель на коэффициент b
*\param[in] coeff_c Указатель на коэффициент c
*/
void program_get_num(double * coeff_a, double * coeff_b, double * coeff_c);

/**
*Запрашивает у пользователя ввод коэффициентов.
*\param[in] coeff_a Указатель на коэффициент a
*\param[in] coeff_b Указатель на коэффициент b
*\param[in] coeff_c Указатель на коэффициент c
*/
void take_values(double * coeff_a, double * coeff_b, double * coeff_c);

/**
*Выводит уравнение, которое желает решить пользователь.
*\param[in] coeff_a Указатель на коэффициент a
*\param[in] coeff_b Указатель на коэффициент b
*\param[in] coeff_c Указатель на коэффициент c
*/
void print_equation(double * coeff_a, double * coeff_b, double * coeff_c);

/**
*Очищает буфер stdin.
*/
int clear_buffer(void);

/**
*Спрашивает у пользователя, желает ли онт продолжить выполнение программы или начать ввод заново.
*/
bool get_choice(void);

#endif