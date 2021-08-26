#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

#define U_MIN_DELT 0.00001              ///< ��������, ������� ���������� ����������� �������� ������ �� �������� �����


enum Error_reshalka
{
    ROOTS_2 = 2,         ///< ��������� ����� 2 �����
    ROOTS_1 = 1,         ///< ��������� ����� 1 ������
    ROOTS_0 = 0,         ///< � ��������� ��� ������
    ROOTS_INF = -1,      ///< ��������� ����� ������������� �������
    OVERFLOW_DIS = -2,   ///< ������: ������������ ��� ������� ��������� ������������
    ERROR = -3           ///< ������: �������������� ��������� ( �� ������ ����������, �� ���� ��� ����������� �������� ���������, ������� ����� ������� ������� ����� ������� ���������)
};

/// �������� ������ ������� abc_scan skan_variable
enum Error_skan_var
{
    OK = 0,              ///< � ������ �� ������
    END_PROGRAM = 1,     ///< ����� ��������� ���������
    NEED_TAKE_STOK = 2   ///< ����� ���������� ������������ ���������
};

//�������������� �������� reshalka
#define NUM_OF_COEF_RESHALKA 3        ///< ���������� ������������ � reshalka
#define NUM_OF_UNITEST_RESHALKA 6     ///< ���������� ��������� reshalka
#define NUM_OUT_OF_UNITEST_RESHALKA 3 ///< ���������� ������� ������� reshalka

//�������������� �������� qadrat
#define NUM_OF_COEF_QADRAT 3        ///< ���������� ������������ � qadrat
#define NUM_OF_UNITEST_QADRAT 3     ///< ���������� ��������� qadrat
#define NUM_OUT_OF_UNITEST_QADRAT 3 ///< ���������� ������� ������� qadrat

//�������������� �������� linerial
#define NUM_OF_COEF_LINERIAL 2        ///< ���������� ������������ � linerial
#define NUM_OF_UNITEST_LINERIAL 3     ///< ���������� ��������� linerial
#define NUM_OUT_OF_UNITEST_LINERIAL 2 ///< ���������� ������� ������� linerial

/*!
�������� ������������ ������� reshalka
\return ������� � ������������ Error_skan_var
*/
int unitest_reshalka(void);

/*!
�������� ������������ ������� qadrat
\return ������� � ������������ Error_skan_var
*/
int unitest_qadrat(void);

/*!
�������� ������������ ������� linerial
\return ������� � ������������ Error_skan_var
*/
int unitest_linerial(void);

/*!
�������� ��� ������������ � ��������� � ���������
\return ������� � ������������ Error_skan_var
*/
int unitest(void);

//=====================================================================================
/// ���� ��� �������� reshalka
const double UNITEST_IN_RESHALKA[NUM_OF_UNITEST_RESHALKA][NUM_OF_COEF_RESHALKA] =
    {
    {0, 0, 0},     // ������� �� ���������� ������ ������������� ������
    {0, 0, 1},     // �������� �� ���������� ������
    {0, 1, 1},     // �������� �� ������� �������� ���������
    {1, -2, 1},    // �������� �� ���������� ��������� � 1 ������
    {1, -1, -2},   // �������� �� ���������� ��������� � 2 �������
    {1, 1, 1},     // �������� �� ���������� ������
    };

/// ��������� ����� ��� �������� reshalka
const double UNITEST_OUT_RESHALKA[NUM_OF_UNITEST_RESHALKA][NUM_OUT_OF_UNITEST_RESHALKA] =
    {
    {0, 0, ROOTS_INF},
    {0, 0, ROOTS_0},
    {-1, 0, ROOTS_1},
    {1, 0, ROOTS_1},
    {2, -1, ROOTS_2},
    {0, 0, ROOTS_0},
    };

//=====================================================================================
/// ���� ��� �������� qadrat
const double UNITEST_IN_QADRAT[NUM_OF_UNITEST_QADRAT][NUM_OF_COEF_QADRAT] =
    {
    {1, -2, 1},    // �������� �� ���������� ��������� � 1 ������
    {1, -1, -2},   // �������� �� ���������� ��������� � 2 �������
    {1, 1, 1},     // �������� �� ���������� ������
    };

/// ��������� ����� ��� �������� qadrat
const double UNITEST_OUT_QADRAT[NUM_OF_UNITEST_QADRAT][NUM_OUT_OF_UNITEST_QADRAT] =
    {
    {1, 0, ROOTS_1},
    {2, -1, ROOTS_2},
    {0, 0, ROOTS_0},
    };

//=====================================================================================
/// ���� ��� �������� linerial
const double UNITEST_IN_LINERIAL[NUM_OF_UNITEST_LINERIAL][NUM_OF_COEF_LINERIAL] =
    {
    {0, 0},     // ������� �� ���������� ������ ������������� ������
    {0, 1},     // �������� �� ���������� ������
    {1, 1},     // �������� �� ������� �������� ���������
    };

/// ��������� ����� ��� �������� linerial
const double UNITEST_OUT_LINERIAL[NUM_OF_UNITEST_LINERIAL][NUM_OUT_OF_UNITEST_LINERIAL] =
    {
    {0, ROOTS_INF},
    {0, ROOTS_0},
    {-1, ROOTS_1},
    };

//=====================================================================================
