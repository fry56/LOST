/*
** EPITECH PROJECT, 2022
** str_is_lower.c
** File description:
** desc
*/

#include <t_string.h>

int tstr_is_lower(char const *str)
{
    int length = tstr_len(str);
    int count = 0;

    if (length == 0)
        return 1;
    while (str[count] != '\0') {
        if (!(str[count] > 'a' && str[count] < 'z'))
            return 0;
        count++;
    }
    return 1;
}
