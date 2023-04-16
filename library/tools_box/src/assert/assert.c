/*
** EPITECH PROJECT, 2023
** assert.c
** File description:
** desc
*/

#include <t_printf.h>
#include <stdio.h>

void l_assert_fail(char const *expr, char const *filename,
    int line, void (*func)(char const *))
{
    tprintf("Assertion failed in [%s:%d] -> (%s)\n", filename, line,
        expr);
    if (func != NULL)
        func(NULL);
}
