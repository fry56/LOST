/*
** EPITECH PROJECT, 2022
** My rev str
** File description:
** The fastest and most effective way to die is to point a gun at Chuck Norris.
*/
#include <t_string.h>

char *tstr_rev(char *str)
{
    int size = tstr_len(str) - 1;
    char temp;

    for (int i = 0; i <= size / 2; i++) {
        temp = str[i];
        str[i] = str[size - i];
        str[size - i] = temp;
    }
    return str;
}
