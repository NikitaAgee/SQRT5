#include <stdio.h>
#include <float.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>


/// �������� ������ ������� qadratik_solver, lnear_solver, solver
enum Slover_out
{
    ROOTS_2 = 2,         ///< ��������� ����� 2 �����
    ROOTS_1 = 1,         ///< ��������� ����� 1 ������
    ROOTS_0 = 0,         ///< � ��������� ��� ������
    ROOTS_INF = -1,      ///< ��������� ����� ������������� �������
    OVERFLOW_DIS = -2,   ///< ������: ������������ ��� ������� ��������� ������������
    ERROR = -3           ///< ������: �������������� ��������� ( �� ������ ����������, �� ���� ��� ����������� �������� ���������, ������� ����� ������� ������� ����� ������� ���������)
};

/*!
������� �������� ������
\param[in] x_1 ������ ������
\param[in] x_2 ������ ������
\param[in] � ������������ � Slover_out
*/
void print_x(double x_1, double x_2, int root_count);

/*!
������ ���������� ��������� a != 0
\param[in] a, b, c   ����������� ���������
\param[out] x_1, x_2 ����� ��������� (=0 ���� �����������)
\return ������������� Slover_out
*/
int slove_sqaure_equation(double a, double b, double c, double *x_1, double *x_2);

/*!
������ �������� ���������
\param[in] b, c ����������� ���������
\param[out] x_1 ����� ��������� (=0 ���� �����������)
\return ������������� Slover_out
*/
int slove_linear_equation(double b, double c, double *x);

/*!
������ ���������� ��������� �������� ������ a = 0
\param[in] a, b, c   ����������� ���������
\param[out] x_1, x_2 ����� ��������� (=0 ���� �����������)
\return ������������� Slover_out
*/
int solver(double a, double b, double c, double* x_1, double* x_2);

/*!
��������� ����������� ���������
\paran[out] *a, *b, *c ����������� ��������
*/
void scan_abc(double *a, double *b, double *c);

/*!
��������� ������� ����� ��� ��� � ������������, ������ ������������ ���������� COMPARASION_ERROR
\param[in] a ����������� �����
*/
int iszero(double a);

/*!
��������� �������� ����� �� ��, ��� ��� ������ 0 +- �����������, ������ ������������ ���������� COMPARASION_ERROR
\param[in] a ����������� �����
*/
int islesszero(double a);

/*!
��������� �������� ����� �� ��������� � ������������, ������ ������������ ���������� COMPARASION_ERROR
\param[in] a, b ������������
*/
bool isequal(double a, double b);

/*!
������� ����� �����
\return int ���������� �������� � ������ �� ������ '\n'
*/
int buffer_cleaner();
