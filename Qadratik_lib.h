#include <stdio.h>
#include <float.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>


/// Варианты вывода функций qadratik_solver, lnear_solver, solver
enum Slover_out
{
    ROOTS_2 = 2,         ///< Уравнение имеет 2 корня
    ROOTS_1 = 1,         ///< Уравнение имеет 1 корень
    ROOTS_0 = 0,         ///< У уравнения нет корней
    ROOTS_INF = -1,      ///< Уравнение имеет бесконечность решений
    OVERFLOW_DIS = -2,   ///< Ошибка: Дискриминант при решении уравнения переполнелся
    ERROR = -3           ///< Ошибка: Непредвиденное состояние ( не должно выводиться, но есть для диагностики неутённых состояний, которые может вывести функция после будущих изменений)
};

/*!
выводит значения корней
\param[in] x_1 первый корень
\param[in] x_2 второй корень
\param[in] в соответствии с Slover_out
*/
void print_x(double x_1, double x_2, int root_count);

/*!
Решает квадратное уравнение a != 0
\param[in] a, b, c   коэфициенты уравнения
\param[out] x_1, x_2 корни уравнения (=0 если отсутствует)
\return соответствует Slover_out
*/
int slove_sqaure_equation(double a, double b, double c, double *x_1, double *x_2);

/*!
Решает линейное уравнение
\param[in] b, c коэфициенты уравнения
\param[out] x_1 корни уравнения (=0 если отсутствует)
\return соответствует Slover_out
*/
int slove_linear_equation(double b, double c, double *x);

/*!
решает квадратное уравнение учитывая случай a = 0
\param[in] a, b, c   коэфициенты уравнения
\param[out] x_1, x_2 корни уравнения (=0 если отсутствует)
\return соответствует Slover_out
*/
int solver(double a, double b, double c, double* x_1, double* x_2);

/*!
считывает коэфициенты уравнения
\paran[out] *a, *b, *c коэфициенты уавнения
*/
void scan_abc(double *a, double *b, double *c);

/*!
проверяет нулевое число или нет с погрешностью, которя определяется константой COMPARASION_ERROR
\param[in] a проверяемое число
*/
int iszero(double a);

/*!
Проверяет вводимое число на то, что оно меньше 0 +- погрешность, которя определяется константой COMPARASION_ERROR
\param[in] a проверяемое число
*/
int islesszero(double a);

/*!
Проверяет введённые числа на равенство с погрешностью, которя определяется константой COMPARASION_ERROR
\param[in] a, b сравниваемые
*/
bool isequal(double a, double b);

/*!
Очищает буфер ввода
\return int количество символов в буфере не считая '\n'
*/
int buffer_cleaner();
