/*
** EPITECH PROJECT, 2022
** my_put_float
** File description:
** Displays the float given as parameter with the specified precision
*/

#include <t_math.h>
#include <t_print.h>

static long double abs_ld_for_len(long double nb)
{
    if (nb < 0)
        return -nb;
    return nb;
}

int tdouble_len(long double nb, int precision)
{
    long double fl_to_int = abs_ld_for_len(fl_prec(nb, precision)) + 0.5;
    char number[41 + precision];
    int i = 0;

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
    return (i);
}
