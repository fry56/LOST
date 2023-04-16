/*
** EPITECH PROJECT, 2022
** int_square.c
** File description:
** desc
*/

static int square_root(int nb, int temp, int n)
{
    temp += (n * 2) + 1;

    if (((n + 1) * (n + 1)) > nb && ((n + 1) * (n + 1)) != nb)
        return 0;
    if (((n + 1) * (n + 1)) < nb)
        return square_root(nb, temp, n + 1);

    return n + 1;
}

int tint_square(int nb)
{
    if (nb <= 0)
        return 0;
    return square_root(nb, 0, 0);
}
