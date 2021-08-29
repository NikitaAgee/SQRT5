#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

/*!
��������� ��� ���������� ���������
*/
struct unitests {
    double a;     ///< ���������� a
    double b;     ///< ���������� b
    double c;     ///< ���������� c
    double x_1;   ///< ������ ������
    double x_2;   ///< ������ ������
    int funk_out; ///< ����� ����������� �������
};

/// ���� ������� � ��������
enum Unittest_Funk_Tipe
{
    LINEAR_FUNK = 0,   ///< �������� �������
    QADRATIK_FUNK = 1  ///< ���������� �������
};

/// ����� ������� ���������
enum Unit_out
{
    UNITEST_ERROR = 1, ///< ������ ��� ����������� ��������
    UNITEST_OK = 0     ///< �������� �������� �������
};


/*!
�������� ������������ ������� slover
\return ������� � ������������ Slover_out
*/
int unitest_solver(void);

/*!
�������� ������������ ������� qadratik
\return ������� � ������������ Slover_out
*/
int unitest_qadratik(void);

/*!
�������� ������������ ������� linerial
\return ������� � ������������ Error_skan_var
*/
int unitest_linear(void);

/*!
�������� ��� ������������ �������� ������� Qadratik_lib � ��������� � ���������
\return ������� � ������������ Error_skan_var
*/
int unitest_all_Qd(void);

/*!
������� ��������� � ������ ���� ����� �� �����
\param[in] unnit_in[] ������ �������� �������� ���������
\param[in] unit_out[] ������ �������� ��������� ��������� �� ������ �������
\param[in] x_1 ������ ������ ���������
\param[in] x_2 ������ ������ ��������� (���� ���, �� 0)
\param[in] error ����� �������
\param[in] tipe ��� ������� � ������������ � Unittest_Funk_Tipe
\param[in] funk_name[] ��� �������
\param[in] nom_of_unitest ����� ��������
*/
void unitest_print(const struct unitests* unitest_in, double x_1, double x_2, double out_funk,
                   int tipe, char funk_name[], int nom_of_unitest);

