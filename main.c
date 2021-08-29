
#include "Qadratik_lib.h"
#include "Unitest_Qd_lib.h"


const int UNIT_FAIL = 202; ///< Значение, вывода main при провале юнит теста


int main(void)
{
    setlocale(LC_CTYPE,"Russian"); //Для того, чтобы выводились русские символы

    double a = 0, b = 0, c = 0; // Коэфициенты
    double x_1 = 0, x_2 = 0;    // Корни

    if (unitest_all_Qd() == UNITEST_ERROR)
    {
        getchar();
        return UNIT_FAIL;
    }

    scan_abc(&a, &b, &c);

    int solver_out = solver(a, b, c, &x_1, &x_2);

    print_x(x_1, x_2, solver_out);    // вывод корней

    getchar();
    getchar();

    return 0;
}


