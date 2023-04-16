/*
** EPITECH PROJECT, 2022
** int_is_prime.c
** File description:
** desc
*/

int tint_is_prime(int nb)
{
    int i = 3;

    if (nb == 2)
        return 1;
    if (nb < i)
        return (0);
    while (i < 46341){
        if (nb % i == 0 && nb != i)
            return (0);
        i += 2;
    }
    return (1);
}
