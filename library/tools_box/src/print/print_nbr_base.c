/*
** EPITECH PROJECT, 2022
** my_putnbr_base
** File description:
** Converts and displays a decimal number into a number in a given base.
*/

#include <t_write.h>
#include <t_string.h>

int print_base(int const *nbr_base, int i, char *base)
{
    int count = 0;

    for (; i > -1; i--, count++)
        twrite(1, &(base[nbr_base[i]]));
    return (count);
}

int print_nbr_base(unsigned int nbr, char *base)
{
    int len = tstr_len(base);
    int nbr_base[32];
    int i = 0;
    int count;

    for (; nbr / len != 0; i++) {
        nbr_base[i] = (int)nbr % len;
        nbr = nbr / len;
    }
    nbr_base[i] = (int)nbr % len;
    count = i + 1;
    if (nbr_base[i] == 0)
        return (0);
    count += print_base(nbr_base, i, base);
    return (count);
}
