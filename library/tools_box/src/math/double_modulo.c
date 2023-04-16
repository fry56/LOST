/*
** EPITECH PROJECT, 2022
** modulo_for_double
** File description:
** Modulo operation, but for double float
*/

double tdouble_modulo(long double nb, double div)
{
    long long constant = 10000000000000;
    long double mult_div = constant * div;
    mult_div *= constant;

    while (nb - div >= 0) {
        if (nb - mult_div >= 0)
            nb = nb - mult_div;
        if (nb - mult_div < 0)
            mult_div = mult_div / 10;
    }
    nb = (int) nb;
    return (double)nb;
}
