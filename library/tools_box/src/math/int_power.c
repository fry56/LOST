/*
** EPITECH PROJECT, 2022
** int_power.c
** File description:
** desc
*/

#include <t_ctype.h>
#include <limits.h>

int tint_power(int nb, int p)
{
    int new_nb = nb;
    if (p == 0)
        return 1;
    for (int i = 1; i < p; ++i) {
        new_nb *= nb;
    }
    return new_nb;
}
