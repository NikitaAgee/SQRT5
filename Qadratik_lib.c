
#include "Qadratik_lib.h"

const double COMPARASION_ERROR = 0.00001;   ///< Погрешность сравнения чисел

const int NUM_AF_POINT = 4;     ///< Количество цифр после запятой при выводе

void print_x(double x_1, double x_2, int root_count)
{

    assert(!isinf(x_1));
    assert(!isinf(x_2));

    switch (root_count) //Вывод значения в зависимости от root_count
    {
        case ROOTS_2:
            printf("Корни уравнения:\n");
            printf("X_1 = %.*f\n", NUM_AF_POINT, x_1);
            printf("X_2 = %.*f\n", NUM_AF_POINT, x_2);
            break;

        case ROOTS_1:
            printf("Корень уравнения:\n");
            printf("X = %.*f\n", NUM_AF_POINT, x_1);
            break;

        case ROOTS_0:
            printf("Корней нет\n");
            break;

        case ROOTS_INF:
            printf("Корней бесконечность\n");
            break;

        case ERROR:
            printf("Что-то пошло не по плану (Код ошибки %d)\n", ERROR);
            break;

        default:
            printf("Что-то пошло очень не по плану (Не правильный root_count = %d) \n", root_count);
    }
}

int slove_sqaure_equation(double a, double b, double c, double *x_1, double *x_2)
{
    assert(!isinf(a));
    assert(!isinf(b));
    assert(!isinf(c));
    assert(!isnan(a));
    assert(!isnan(b));
    assert(!isnan(c));
    assert(x_1 != NULL);
    assert(x_2 != NULL);
    assert(x_1 != x_2);
    assert(a != 0);

    double Dis = 0;   // Дискриминант
    double skDis = 0; // Корень дискриминанта
    *x_1 = 0;
    *x_2 = 0;
    // Вычисление дискриминанта
    Dis = ((b * b) - (4 * c * a));

    // Проверка переполнения Dis
    if (isinf(Dis))
    {
        return OVERFLOW_DIS;
    }

    /* начало ветвления резуультатов в зависимости от дискрииминанта*/
    if (islesszero(Dis))
    {
        return ROOTS_0;
    }
    if (iszero(Dis))
    {
        // Корень дискриминанта
        skDis = sqrt(Dis);

        // Вычисление x_1 и x_2
        *x_1 = ((-b + skDis) / (2 * a));
        *x_2 = 0;

        // Вывод соответствующего значения
        return ROOTS_1;
    }
    else
    {
        // Корень дискриминанта
        skDis = sqrt(Dis);

        // Вычисление x_1 и x_2
        *x_1 = ((-b + skDis) / (2 * a));
        *x_2 = ((-b - skDis) / (2 * a));;

        // Вывод соответствующего значения
        return ROOTS_2;
    }

    return ERROR;
}

int slove_linear_equation(double b, double c, double *x)
{

    assert(!isinf(b)); //isfinite
    assert(!isinf(c));
    assert(!isnan(b));
    assert(!isnan(c));
    assert(x != NULL);

    if (iszero(b) && iszero(c))   //проверка условий бесконечного количества решений
    {
        return ROOTS_INF;
    }
    if (iszero(b) && !iszero(c))   //проверка отсутствия корней из-за особенности переменных
    {
        return ROOTS_0;
    }
    if (!iszero(b))                           //роверка на выполнимость/необходимость приминения линейности
    {
        *x = ((-c) / b);
        return ROOTS_1;
    }

    return ERROR;
}

int solver(double a, double b, double c, double* x_1, double* x_2)
{

    assert(!isinf(a));
    assert(!isinf(b));
    assert(!isinf(c));
    assert(!isnan(a));
    assert(!isnan(b));
    assert(!isnan(c));
    assert(x_1 != NULL);
    assert(x_2 != NULL);
    assert(x_1 != x_2);

    if (iszero(a))   //проверка условий бесконечного количества решений
    {
        return slove_linear_equation(b, c, x_1);
    }
    else
    {
        return slove_sqaure_equation(a, b, c, x_1, x_2);
    }
}

void scan_abc(double *a, double *b, double *c)
{
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    assert(a != b);
    assert(a != c);
    assert(b != c);

    int scan_out = 0;         // Вывод scanf
    int any_char_check = 0;   // Проверка на наличие лишних символов

    while(1)
    {
        printf("Введите коэфициенты: ");
        scan_out = scanf("%lf %lf %lf", a, b, c);

        any_char_check = buffer_cleaner();

        if ((scan_out == 3) && (any_char_check == 0))
        {
            break;
        }

        printf("Вы ошиблись\n");
    }
}

int iszero(double a)
{
    assert(!isinf(a));
    assert(!isnan(a));

    return (fabs(a) <= COMPARASION_ERROR);   //precision
}

int islesszero(double a)
{
    assert(!isinf(a));
    assert(!isnan(a));

    return (a < -COMPARASION_ERROR);
}

bool isequal(double a, double b)
{

    assert(!isinf(a));
    assert(!isnan(a));

    return (fabs(a - b) <= COMPARASION_ERROR);
}

int buffer_cleaner()
{
    int char_counter = 0;
    char ch = getchar();

    while(ch != '\n' && ch != '\r')
        {
            ch = getchar();
            char_counter++;
        }

    return char_counter;
}
