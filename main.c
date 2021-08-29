
//#include "Qadratik_const_fails.h"
//#include "Qadratik_funk.c"
//#include "Unitest.c"


#include "Pre_Qadratik.h"


int main(void)
{

    setlocale(LC_CTYPE,"Russian"); //��� ����, ����� ���������� ������� �������

    double a = 0, b = 0, c = 0; // ���� � ������������� ���������� ��� ������������
    double x_1 = 0, x_2 = 0; // ���� � ������������� ���������� ��� ������
    int reshalka_error = OK; // ���������� ��� ������ ������ ������� reshalka
    int sc_chek = OK;        // ���������� ��� ������ ������ ������� abc_scan

    if (unitest() == END_PROGRAM)
    {
        getchar();
        getchar();
        return UNIT_FAIL;
    }

    start_print();

    while(1) // �������� ���� ���������
    {

        sc_chek = abc_scan(&a, &b, &c);

        if (sc_chek == END_PROGRAM)
        {
            continue;
        }

        x_1 = 0;
        x_2 = 0;

        if ( abc_lim_over_print (a, b, c) )     // �������� �� ������������ �����������
        {
            continue;
        }
        else
        {

            reshalka_error = reshalka (a, b, c, &x_1, &x_2);

            if (reshalka_error == OVERFLOW_DIS)     // �������� �� ������������ �������������
            {
                continue;
            }
            else
            {
                x_lim_over_print(x_1, x_2, reshalka_error);           // ������� ������ �� ������������ � �� �����
            }
        }
    }

    end_print();

    return 0;
}
