/*
** EPITECH PROJECT, 2022
** str_cmp.c
** File description:
** desc
*/
#include <stdio.h>
int tstr_cmp(char const *s1, char const *s2)
{
    for (; *s1 || *s2 ; s1++, s2++) {
        if (*s1 != *s2)
            return *s1 - *s2;
    }
    return 0;
}

int tstr_ncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; (*s1 || *s2) && i < n; s1++, s2++, i++) {
        if (*s1 != *s2)
            return *s1 - *s2;
    }
    return 0;
}
