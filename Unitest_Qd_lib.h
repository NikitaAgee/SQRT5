#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

/*!
Структура для сохранения юнитестов
*/
struct unitests {
    double a;     ///< Коэфициент a
    double b;     ///< Коэфициент b
    double c;     ///< Коэфициент c
    double x_1;   ///< Первый корень
    double x_2;   ///< Второй корень
    int funk_out; ///< Вывод проверяемой функции
};

/// Типы функций в юнитесте
enum Unittest_Funk_Tipe
{
    LINEAR_FUNK = 0,   ///< Линейная функция
    QADRATIK_FUNK = 1  ///< Квадратная функция
};

/// Вывод функций юнитестов
enum Unit_out
{
    UNITEST_ERROR = 1, ///< Ошибка при прохождении юнитеста
    UNITEST_OK = 0     ///< Юнитесты пройдены успешно
};


/*!
Проводит тестирование функции slover
\return выводит в соответствии Slover_out
*/
int unitest_solver(void);

/*!
Проводит тестирование функции qadratik
\return выводит в соответствии Slover_out
*/
int unitest_qadratik(void);

/*!
Проводит тестирование функции linerial
\return выводит в соответствии Error_skan_var
*/
int unitest_linear(void);

/*!
Вызывает все тестирования основных функций Qadratik_lib и оповещает о проблемах
\return выводит в соответствии Error_skan_var
*/
int unitest_all_Qd(void);

/*!
Выводит сообщение о ошибке юнит теста на экран
\param[in] unnit_in[] массив значений вводимых юнитестом
\param[in] unit_out[] массив значений ожидаемых юнитестом на выводе функции
\param[in] x_1 первый корень уравнения
\param[in] x_2 второй корень уравнения (если нет, то 0)
\param[in] error вывод функции
\param[in] tipe тип функции в соответствии с Unittest_Funk_Tipe
\param[in] funk_name[] имя функции
\param[in] nom_of_unitest номер юнитеста
*/
void unitest_print(const struct unitests* unitest_in, double x_1, double x_2, double out_funk,
                   int tipe, char funk_name[], int nom_of_unitest);

