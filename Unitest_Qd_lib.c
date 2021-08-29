
#include "Unitest_Qd_lib.h"
#include "Qadratik_lib.h"

//Характеристики юнитеста reshalka
#define NUM_OF_UNITEST_SOLVER 6       ///< Количество юнитестов reshalka

//Характеристики юнитеста qadrat
#define NUM_OF_UNITEST_QADRATIK 3     ///< Количество юнитестов qadrat

//Характеристики юнитеста linerial
#define NUM_OF_UNITEST_LINEAR 4       ///< Количество юнитестов linerial


//=====================================================================================
//#############################-  Массивы для юнитестов -##############################
//=====================================================================================

/// Юнитесты reshalka
const struct unitests UNITEST_SOLVER[NUM_OF_UNITEST_SOLVER] =
    {
    {0,  0,  0,  0,  0, ROOTS_INF},  // 0 Поверка на уникальный случай бесконечности корней
    {0,  0,  1,  0,  0, ROOTS_0},  // 1 Проверка на отсутствие корней
    {0,  1,  1, -1,  0, ROOTS_1},  // 2 Проверка на решение линейных уравнений
    {1, -2,  1,  1,  0, ROOTS_1},  // 3 Проверка на квадратное уравнение с 1 корнем
    {1, -1, -2,  2, -1, ROOTS_2},  // 4 Проверка на квадратное уравнение с 2 корнями
    {1,  1,  1,  0,  0, ROOTS_0},  // 5 проверка на отсутствие корней
    };

//=====================================================================================

/// Юнитесты qadrat
const struct unitests UNITEST_QADRATIK[NUM_OF_UNITEST_QADRATIK] =
    {
    {1, -2,  1,  1,  0, ROOTS_1},  // 0 Проверка на квадратное уравнение с 1 корнем
    {1, -1, -2,  2, -1, ROOTS_2},  // 1 Проверка на квадратное уравнение с 2 корнями
    {1,  1,  1,  0,  0, ROOTS_0},  // 2 проверка на отсутствие корней
    };

//=====================================================================================

/// Юнитесты linerial
const struct unitests UNITEST_LINEAR[NUM_OF_UNITEST_LINEAR] =
    {
    {0,  0,  0,  0, 0, ROOTS_INF}, // 0 Поверка на уникальный случай бесконечности корней
    {0,  1,  0,  0, 0, ROOTS_1},   // 1 Проверка на отсутствие корней
    {0,  1,  1, -1, 0, ROOTS_1},   // 2 Проверка на решение линейных уравнений
    {0,  0,  1,  0, 0, ROOTS_0},   // 1 Проверка на отсутствие корней
    };

//=====================================================================================
//#####################################################################################
//=====================================================================================

int unitest_all_Qd(void)
{

    if ((unitest_qadratik() == UNITEST_ERROR) || (unitest_linear() == UNITEST_ERROR) || (unitest_solver() == UNITEST_ERROR))
    {
        return UNITEST_ERROR;
    }

    return UNITEST_OK;
}

int unitest_solver(void)
{

    int nom_of_unitest = 0;
    double a = 0, b = 0, c = 0;
    double x_1 = 0, x_2 = 0;
    int solver_out = ERROR;

    while (nom_of_unitest < NUM_OF_UNITEST_SOLVER)
    {
        x_1 = 0;
        x_2 = 0;
        a = UNITEST_SOLVER[nom_of_unitest].a;
        b = UNITEST_SOLVER[nom_of_unitest].b;
        c = UNITEST_SOLVER[nom_of_unitest].c;

        solver_out = solver(a, b, c, &x_1, &x_2);

        if (!isequal(x_1, UNITEST_SOLVER[nom_of_unitest].x_1) ||
            !isequal(x_2, UNITEST_SOLVER[nom_of_unitest].x_2) ||
            !isequal(solver_out, UNITEST_SOLVER[nom_of_unitest].funk_out))
        {
            unitest_print(&UNITEST_SOLVER[nom_of_unitest], x_1, x_2,
                          solver_out, QADRATIK_FUNK, "solver", nom_of_unitest);
            return UNITEST_ERROR;
        }

        nom_of_unitest++;
    }

    printf("solver прошла юнитесты\n");
    return UNITEST_OK;
}

int unitest_qadratik(void)
{

    int nom_of_unitest = 0;
    double a = 0, b = 0, c = 0;
    double x_1 = 0, x_2 = 0;
    int qadratik_out = ERROR;

    while (nom_of_unitest < NUM_OF_UNITEST_QADRATIK)
    {
        // обнуление корней
        x_1 = 0;
        x_2 = 0;
        // запись коэфициентов
        a = UNITEST_QADRATIK[nom_of_unitest].a;
        b = UNITEST_QADRATIK[nom_of_unitest].b;
        c = UNITEST_QADRATIK[nom_of_unitest].c;
        // вызов тестируемой функции
        qadratik_out = slove_sqaure_equation(a, b, c, &x_1, &x_2);

        if (!isequal(x_1, UNITEST_QADRATIK[nom_of_unitest].x_1) ||
            !isequal(x_2, UNITEST_QADRATIK[nom_of_unitest].x_2) ||
            !isequal(qadratik_out, UNITEST_QADRATIK[nom_of_unitest].funk_out))
        {
            unitest_print(&UNITEST_QADRATIK[nom_of_unitest], x_1, x_2,
                          qadratik_out, QADRATIK_FUNK, "qadrat", nom_of_unitest);

            return UNITEST_ERROR;
        }

        nom_of_unitest++;
    }

    printf("qadratik прошла юнитесты\n");
    return UNITEST_OK;
}

int unitest_linear(void)
{

    int nom_of_unitest = 0;
    double b = 0, c = 0;
    double x_1 = 0, x_2 = 0;
    int linear_out = ERROR;

    while (nom_of_unitest < NUM_OF_UNITEST_LINEAR)
    {
        b = 0;
        c = 0;
        x_1 = 0;

        b = UNITEST_LINEAR[nom_of_unitest].b;
        c = UNITEST_LINEAR[nom_of_unitest].c;
        linear_out = slove_linear_equation(b, c, &x_1);
        if (!isequal(x_1, UNITEST_LINEAR[nom_of_unitest].x_1) ||
            !isequal(linear_out, UNITEST_LINEAR[nom_of_unitest].funk_out))
        {
            unitest_print(&UNITEST_LINEAR[nom_of_unitest], x_1, x_2,
                          linear_out, LINEAR_FUNK, "linear", nom_of_unitest);
            return UNITEST_ERROR;
        }

        nom_of_unitest++;
    }

    printf("qadrat прошла юнитесты\n");
    return UNITEST_OK;
}

void unitest_print(const struct unitests* unitest_in, double x_1, double x_2, double out_funk, int tipe, char funk_name[], int nom_of_unitest)
{
    int skeper = 0; // Переменная для прокручивания массивов

    // Шапка сообщения об ошибке
    printf("-------------------------------\n");
    printf("%s юнитест %d провален\n", funk_name, nom_of_unitest);
    printf("-------------------------------\n");
    printf("Ввод:\n");

    if (tipe == QADRATIK_FUNK) // Проверка для корректного вывода сообщения об ошибке линейной и не линейной фукции
    {
        printf("a = %f\n", unitest_in->a);
        skeper++;
    }

    printf("b = %f\n", unitest_in->b);
    skeper++;
    printf("c = %f\n", unitest_in->c);

    skeper = 0;
    // Шапка вывода корней
    printf("-------------------------------\n");
    printf("Вывод:  |Ожидание  |Рреальность\n");
    printf("x_1     |%10f|%10f\n", unitest_in->x_1, x_1);
    skeper++;

    if (tipe == QADRATIK_FUNK) // Проверка для корректного вывода сообщения об ошибке линейной и не линейной фукции
    {
        printf("x_2     |%10f|%10f\n", unitest_in->x_2, x_2);
        skeper++;
    }

    printf("res_err |%10f|%10f\n", unitest_in->funk_out, out_funk);

    printf("===============================\n"); // сообщение о том, как закрыть окно
    printf("[Enter] для закрытия окна\n");
}
