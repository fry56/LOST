/*
** EPITECH PROJECT, 2022
** my_put_float
** File description:
** Displays the float given as parameter with the specified precision
*/

#include <t_write.h>
#include <t_math.h>

long double fl_prec(long double nb, int precision)
{
    for (int i = 0; i < precision; i++)
        nb = nb * 10;
    return (nb);
}

int print_float_char(int i, int precision, char *number)
{
    int count;
    char *zero = "0";

    count = i;
    i--;
    if (i == precision) {
        twrite(1, zero);
        count++;
    }
    if (!number[i]) {
        twrite(1, zero);
        count++;
    }
    for (; i >= 0; i--)
        twrite(1, &number[i]);
    return count;
}

int print_float(long double nb, int precision)
{
    long double fl_to_int = tdouble_abs(fl_prec(nb, precision)) + 0.5;
    char number[41 + precision];
    int i = 0;
    int count;

    for (; i < precision; i++) {
        number[i] = tdouble_modulo(fl_to_int, 10) + '0';
        fl_to_int = (fl_to_int - (number[i] - '0')) / 10;
    }
    if (precision > 0) {
        number[i] = '.';
        i++;
    }
    for (; fl_to_int >= 1; i++) {
        number[i] = tdouble_modulo(fl_to_int, 10) + '0';
        fl_to_int = (fl_to_int - (number[i] - '0')) / 10;
    }
    count = print_float_char(i, precision, number);
    return (count);
}
