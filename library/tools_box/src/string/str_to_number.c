/*
** EPITECH PROJECT, 2022
** str_to_number.c
** File description:
** desc
*/

#include <t_string.h>
#include "t_ctype.h"

int tstr_to_number(char *number)
{
    int length = tstr_len(number);
    int new_number = 0;

    if (!tstr_contain_only(number, "0123456789\n"))
        return 0;
    for (int i = 0; i < length; ++i)
        new_number = (new_number * 10) + (number[i] - 48);
    return new_number;
}
