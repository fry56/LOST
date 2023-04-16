/*
** EPITECH PROJECT, 2023
** str_index_of.c
** File description:
** desc
*/

#include <stdlib.h>

int tstr_index_of(char *buf, char *value)
{
    int index = 0;
    int start_index = -1;

    if (buf == NULL || value == NULL)
        return -1;
    for (int i = 0; *buf; buf++, index++) {
        if (*buf != value[i]) {
            start_index = -1;
            i = 0;
            continue;
        }
        i++;
        if (start_index == -1)
            start_index = index;
        if (value[i] == '\0')
            return start_index;
    }
    return -1;
}
