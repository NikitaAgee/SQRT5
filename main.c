#include "Qadratik_lib.h"
#include "Unitest_Qd_lib.h"

int main(void)
{

    setlocale(LC_CTYPE,"Russian"); //Для того, чтобы выводились русские символы

    if (unitest_all_Qd() == UNITEST_ERROR)
    {
        getchar();
        getchar();
        return 404;
    }

    double a = 0, b = 0, c = 0;
    scan_abc(&a, &b, &c);

    double x_1 = 0, x_2 = 0;
    int root_count = solver(a, b, c, &x_1, &x_2);

    print_x(x_1, x_2, root_count);

    getchar();
    getchar();

    return 0;
}
