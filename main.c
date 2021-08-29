
//#include "Qadratik_const_fails.h"
//#include "Qadratik_funk.c"
//#include "Unitest.c"


#include "Pre_Qadratik.h"


int main(void)
{

    setlocale(LC_CTYPE,"Russian"); //Для того, чтобы выводились русские символы

    double a = 0, b = 0, c = 0; // Ввод и инициализация переменных для коэфициентов
    double x_1 = 0, x_2 = 0; // Ввод и инициализация переменных для корней
    int reshalka_error = OK; // Переменная для записи вывода функции reshalka
    int sc_chek = OK;        // Переменная для записи вывода функции abc_scan

    if (unitest() == END_PROGRAM)
    {
        getchar();
        getchar();
        return UNIT_FAIL;
    }

    start_print();

    while(1) // Основной цикл программы
    {

        sc_chek = abc_scan(&a, &b, &c);

        if (sc_chek == END_PROGRAM)
        {
            continue;
        }

        x_1 = 0;
        x_2 = 0;

        if ( abc_lim_over_print (a, b, c) )     // проверка на переполнение коэфициентв
        {
            continue;
        }
        else
        {

            reshalka_error = reshalka (a, b, c, &x_1, &x_2);

            if (reshalka_error == OVERFLOW_DIS)     // проверка на переполнение дискриминанта
            {
                continue;
            }
            else
            {
                x_lim_over_print(x_1, x_2, reshalka_error);           // провека корней на переполнение и их вывод
            }
        }
    }

    end_print();

    return 0;
}
