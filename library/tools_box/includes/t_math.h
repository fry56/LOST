/*
** EPITECH PROJECT, 2022
** tmath.h
** File description:
** desc
*/
#ifndef TOOLS_BOX_TMATH_H
    #define TOOLS_BOX_TMATH_H

    #include "t_ctype.h"

    int tint_is_prime(int nb);
    int tint_power(int nb, int p);
    int tint_square(int nb);
    int tint_find_prime_sup(int nb);
    int tint_len(int nbr);
    double tdouble_modulo(long double nb, double div);
    int tdouble_len(long double nb, int precision);
    long double tdouble_abs(long double nb);
    char *tint_to_base(int number, int base, int max_digits);
#endif //TOOLS_BOX_TMATH_H
