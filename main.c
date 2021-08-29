
#include "Qadratik_lib.h"
#include "Unitest_Qd_lib.h"


const int UNIT_FAIL = 202; ///< ��������, ������ main ��� ������� ���� �����


int main(void)
{
    setlocale(LC_CTYPE,"Russian"); //��� ����, ����� ���������� ������� �������

    double a = 0, b = 0, c = 0; // �����������
    double x_1 = 0, x_2 = 0;    // �����

    if (unitest_all_Qd() == UNITEST_ERROR)
    {
        getchar();
        return UNIT_FAIL;
    }

    scan_abc(&a, &b, &c);

    int solver_out = solver(a, b, c, &x_1, &x_2);

    print_x(x_1, x_2, solver_out);    // ����� ������

    getchar();
    getchar();

    return 0;
}


