/*
** EPITECH PROJECT, 2022
** int.c
** File description:
** desc
*/

#include <stdarg.h>
#include <t_print.h>
#include <t_string.h>

void int_flag(va_list args)
{
    print_nbr(va_arg(args, int));
}

char *compos_int(va_list args)
{
    return tstr_number(va_arg(args, int));
}
