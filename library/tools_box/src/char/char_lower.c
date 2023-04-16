/*
** EPITECH PROJECT, 2022
** char_lower.c
** File description:
** desc
*/

#include <t_char.h>

char tchar_lower(char c)
{
    if (!tchar_is_upper(c))
        return c;
    return (char)(c + 32);
}
