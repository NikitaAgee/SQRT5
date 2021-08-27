
#include "Pre_Qadratik.h"

const char* NAME_VAR[NUM_OF_COEF] = {"a","b","c"};///< ������ ��� ����������

bool abc_lim_over_print(double a, double b, double c)
{

    assert(!isnan(a));
    assert(!isnan(b));
    assert(!isnan(c));

    // ����������� ��������� � ������������ ����� ������� �������� ����������, ������� �����������
    char* befor_variable = "������� ������� (�� ������) ����������: ";

    bool overflow = false; // ����������� ����� �������

    // �������� ������������� ��������
    overflow_alarm(a,  befor_variable, "a", "\n", &overflow);
    overflow_alarm(b,  befor_variable, "b", "\n", &overflow);
    overflow_alarm(c,  befor_variable, "c", "\n", &overflow);

    return overflow;
}

void x_lim_over_print(double x_1, double x_2, int root_count)
{

    assert(!isnan(x_1));
    assert(!isnan(x_2));

    char* befor_variable = "������� ������� (�� ������) ������: ";
    bool overflow = false;

    //�������� x_1 x_2
    overflow_alarm(x_1,  befor_variable, "x_1", "\n", &overflow);
    overflow_alarm(x_2,  befor_variable, "x_2", "\n", &overflow);

    if (overflow)
    {
        return;
    }
    switch (root_count) //����� �������� � ����������� �� root_count
    {
        case ROOTS_2:
            printf("����� ���������:\n");
            printf("X_1 = %.*f\n", NUM_AF_POINT, x_1);
            printf("X_2 = %.*f\n", NUM_AF_POINT, x_2);
            break;

        case ROOTS_1:
            printf("������ ���������:\n");
            printf("X = %.*f\n", NUM_AF_POINT, x_1);
            break;

        case ROOTS_0:
            printf("������ ���\n");
            break;

        case ROOTS_INF:
            printf("������ �������������\n");
            break;

        case ERROR:
            printf("���-�� ����� �� �� ����� (��� ������ %d)\n", ERROR);
            break;

        default:
            printf("���-�� ����� ����� �� �� ����� (�� ���������� root_count = %d) \n", root_count);
    }
}

int qadrat(double a, double b, double c, double *x_1, double *x_2)
{
    assert(!isinf(a));
    assert(!isinf(b));
    assert(!isinf(c));
    assert(x_1 != 0);
    assert(x_2 != 0);
    assert(x_1 != x_2);

    double Dis = 0;   // ������������
    double skDis = 0; // ������ �������������
    char* befor_variable = "������������ ������� ������� (�� ������)\n ";
    bool overflow = false;

    // ���������� �������������
    Dis = ((b * b) - (4 * c * a));

    // �������� ������������ Dis
    overflow_alarm(Dis,  befor_variable, "Dis", "\n", &overflow);
    if (overflow)
    {
        return OVERFLOW_DIS;
    }

    /* ������ ��������� ������������ � ����������� �� ��������������*/
    else if (Dis <= -MIN_DELT)
    {
        return ROOTS_0;
    }
    else if (fabs(Dis) < MIN_DELT)
    {
        // ������ �������������
        skDis = sqrt(Dis);

        // ���������� x_1 � x_2
        *x_1 = ((-b + skDis) / (2 * a));
        *x_2 = 0;

        // ����� ���������������� ��������
        return ROOTS_1;
    }
    else
    {
        // ������ �������������
        skDis = sqrt(Dis);

        // ���������� x_1 � x_2
        *x_1 = ((-b + skDis) / (2 * a));
        *x_2 = ((-b - skDis) / (2 * a));;

        // ����� ���������������� ��������
        return ROOTS_2;
    }

    return ERROR;
}

int linerial(double b, double c, double *x)
{

    assert(!isinf(b));
    assert(!isinf(c));
    assert(x != 0);

    if ((fabs(b) <= MIN_DELT) && (fabs(c) <= MIN_DELT))        //�������� ������� ������������ ���������� �������
    {
        return ROOTS_INF;
    }

    else if ((fabs(b) <= MIN_DELT) && (fabs(c) > MIN_DELT))   //�������� ���������� ������ ��-�� ����������� ����������
    {
        return ROOTS_0;
    }
    else if (fabs(b) > MIN_DELT)                           //������� �� ������������/������������� ���������� ����������
    {
        *x = ((-c) / b);
        return ROOTS_1;
    }

    return ROOTS_1;
}

int reshalka(double a, double b, double c, double* x_1, double* x_2)
{

    assert(!isinf(a));
    assert(!isinf(b));
    assert(!isinf(c));
    assert(x_1 != 0);
    assert(x_2 != 0);
    assert(x_1 != x_2);

    if (fabs(a) <= MIN_DELT)   //�������� ������� ������������ ���������� �������
    {
        return linerial(b, c, x_1);
    }
    else
    {
        return qadrat(a, b, c, x_1, x_2);
    }
}

int abc_scan(double *a, double *b, double *c)
{

    assert(a != 0);
    assert(b != 0);
    assert(c != 0);
    assert(a != b);
    assert(a != c);
    assert(b != c);

    int take_stok = 0;                    // �������� ������������ ���������� �����
    int sc_out = 0;                       // �������� ��� ������ ������ skan_variable
    double coef[NUM_OF_COEF] = {0, 0, 0}; // ������ ��� ������ ������������
                                          // [0]-a
                                          // [1]-b
                                          // [2]-c
    int cell_nom = 0;                     // ����� ����������� ������

    printf("==========================================================================\n");
    printf("������� ������������ \n(��� ���������� ��������� ������� %c): \n", END_SIMVOL);

    //������ �������� ����� �����
    while (cell_nom < NUM_OF_COEF)
    {
        sc_out = skan_variable(NAME_VAR[cell_nom], coef + cell_nom);

        if (sc_out == NEED_TAKE_STOK)
        {
            take_stok = 1;
        }
        if (sc_out == END_PROGRAM)
        {
            break;
        }

        cell_nom++;
    }
    //����� �������� ����� �����

    *a = coef[0];
    *b = coef[1];
    *c = coef[2];

    //���������� �����, ���� ���� ���������� � ���������� (�������� �������� ������ ������� �.�. �������� ����������� � ����� �����)
    if ((take_stok == 1) && (sc_out != END_PROGRAM))
    {
        printf("--------------------------------------------------------------------------\n");
        printf("a = %.*f\n", NUM_AF_POINT, *a);
        printf("b = %.*f\n", NUM_AF_POINT, *b);
        printf("c = %.*f\n", NUM_AF_POINT, *c);
    }

    printf("--------------------------------------------------------------------------\n");

    //����� �������� ������������� ��������� ��������� ��� ����������
    if (sc_out == END_PROGRAM)
    {
        return END_PROGRAM;
    }
    return OK;

}

int skan_variable(const char var_name[], double* var)
{

    assert (var != 0);
    assert (var_name != "\n");

    int sc_chek = 0;         // �������� ������� � ����� ����� (������ � ������)
    int sc_error = 0;        // �������� ������� � ���� ������� ����� ������� # � \n
    int end_simvol_chek = 0; // �������� �� ������� ��������� ������� ������ � ������ ����� (����� scanf)
    char ch = '\n';          // ���������� ��� ������� �� ������ ������
    int out = OK;            // ����� ���������

    while(1)
    {
        sc_chek = 0;
        sc_error = 0;
        end_simvol_chek = 0;
        ch = '\n';

        printf("%s = ", var_name);
        sc_chek = scanf("%lf", var);

        ch = getchar();

        if (ch == END_SIMVOL)
        {
            end_simvol_chek = 1;
            ch = getchar();
        }

        while (ch != '\n')
        {
            ch = getchar();
            sc_error = 1;
        }

        if ((sc_chek != 1) && (end_simvol_chek == 1) && (sc_error != 1))
        {
            if(end_question() == END_PROGRAM)
            {
                return END_PROGRAM;
            }
            else
            {
                out = NEED_TAKE_STOK;
            }
        }

        if ((sc_error == 1) || ((sc_chek == 1) && (end_simvol_chek == 1)))
        {
            printf("�� �������� ��� ����� ��������\a\n");
            printf("(��� ����� ����� ��� ������� ���������� ������������ ������ �������)\n");
            printf("��� ���������� ��������� ������� %c \n", END_SIMVOL);
            out = NEED_TAKE_STOK;
        }

        if ((sc_chek == 1) && (end_simvol_chek != 1) && (sc_error != 1))
        {
            break;
        }
    }

    return out;

}

int end_question(void)
{

    char pr_end_Y_N = 'N';

    while(1)
        {
            printf("�� ������������� ������ ��������� ��������� [Y/N]\a: "); //�������� �� ������ ������������


            pr_end_Y_N = getchar();         //������ ������ �� ������� �������


            //������� ������ �����
            while (getchar() != '\n')
                {;}

            //�������� ������
            if ((pr_end_Y_N == 'Y') || (pr_end_Y_N == 'y'))
            {
                return END_PROGRAM;
            }
            else if ((pr_end_Y_N == 'N') || (pr_end_Y_N == 'n'))
            {
                return OK;
            }
            else
            {
                printf("� �� �����, ���� ������\a\n");
            }
        }
}

void start_print(void)
{
    printf("==========================================================================\n");
    printf("                   ������� ��������� a*x^2+b*x+c=0                        \n");
}

void end_print(void)
{
    printf("==========================================================================\n");
    printf("��������� ���������\n");
    printf("��� �������� ���� ������� [Enter] \n");
    printf("==========================================================================\n");

    getchar();

}

void overflow_alarm (double nom, char befor_variable[], char name_variable[], char after_variable[], bool* overflow)
{

    assert(!isnan(nom));
    assert(overflow != 0);

    if (isinf(nom))
    {
        printf("%s%s%s", befor_variable, name_variable, after_variable);
        *overflow = true;
    }
}

int unitest(void)
{

    if ((unitest_qadrat() == END_PROGRAM) || (unitest_linerial() == END_PROGRAM) || (unitest_reshalka() == END_PROGRAM))
    {
        return END_PROGRAM;
    }

    return OK;
}
