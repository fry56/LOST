/*
** EPITECH PROJECT, 2023
** str_concat_char.c
** File description:
** desc
*/

#include <t_string.h>
#include <stdlib.h>

char *tstr_concat_char(char *str_a, char char_b)
{
    int len_a = tstr_len(str_a);
    char *new_str = malloc(len_a + 2);

    if (new_str == NULL)
        return NULL;
    for (int i = 0; i < (len_a + 1); ++i) {
        if (i < len_a) {
            new_str[i] = str_a[i];
        } else {
            new_str[i] = char_b;
        }
    }
    new_str[len_a + 1] = '\0';
    return new_str;
}
