/*
** EPITECH PROJECT, 2022
** str_is_alpha.c
** File description:
** desc
*/

#include <t_string.h>

int tstr_is_alpha(char const *str)
{
    int length = tstr_len(str);
    int count = 0;
    char temp[length];

    if (length == 0)
        return 1;
    tstr_cpy(temp, str);
    tstr_case_lower(temp);
    while (temp[count] != '\0') {
        if (!(temp[count] > 'a' && temp[count] < 'z')) {
            return 0;
        }
        count++;
    }

    return 1;
}
