/*
** EPITECH PROJECT, 2022
** char_is_upper.c
** File description:
** desc
*/

#include <t_ctype.h>

bool tchar_is_upper(char c)
{
    if (!(c > 'A' && c < 'Z'))
        return false;
    return true;
}
