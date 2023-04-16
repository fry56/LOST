/*
** EPITECH PROJECT, 2022
** float.c
** File description:
** desc
*/

#include <stdarg.h>
#include <t_print.h>

void float_flags(va_list args)
{
    print_float(va_arg(args, long double), 6);
}
