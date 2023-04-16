/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** Displays the number given as parameter
*/

#include <t_write.h>
#include <t_math.h>
#include <stdlib.h>

int print_nbr_data(int const *number, int i, int count)
{
    char nbr;
    for (; i > -1; i--) {
        nbr = number[i] + '0';
        twrite(1, &nbr);
    }
    return (count);
}

int print_nbr(long long nb)
{
    int number[19];
    int i = 0;
    int count;

    if (nb == 0)
        twrite(1, "0");
    for (; nb / 10 != 0; i++) {
        number[i] = abs((int)nb % 10);
        nb = nb / 10;
    }
    number[i] = abs((int)nb % 10);
    count = i + 1;
    if (nb < 0) {
        twrite(1, "-");
        count++;
    }
    if (number[i] == 0)
        return (0);
    count = print_nbr_data(number, i, count);
    return (count);
}
