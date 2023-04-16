/*
** EPITECH PROJECT, 2023
** str_number.c
** File description:
** desc
*/

#include <t_mem.h>
#include <t_math.h>
#include <stdio.h>
#include <stdlib.h>

char *tstr_number(int number)
{
    int number_len = tint_len(number);
    char *new_str = malloc(number_len + 1);

    if (new_str == NULL)
        return NULL;
    for (int i = 0; i < number_len; i++)
        new_str[i] = (char)(((int)number % tint_power(10, number_len - i)
            / tint_power(10, (number_len - 1) - i)) + 48);
    new_str[number_len] = '\0';
    return new_str;
}
