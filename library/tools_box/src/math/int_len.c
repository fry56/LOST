/*
** EPITECH PROJECT, 2022
** my_int_len.c
** File description:
** desc
*/

#include <t_math.h>
#include <stdlib.h>

int tint_len(int nbr)
{
    int length = 0;

    if (nbr == 0)
        return 1;
    nbr = abs(nbr);
    while (nbr > 0) {
        length++;
        nbr /= 10;
    }
    return length;
}
