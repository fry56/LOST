/*
** EPITECH PROJECT, 2022
** string.c
** File description:
** desc
*/

#include <t_printf.h>
#include <t_write.h>
#include <stdarg.h>

void string_flag(va_list args)
{
    char *arg_string = va_arg(args, char*);
    twrite(1, arg_string);
}

char *compos_string(va_list args)
{
    return va_arg(args, char *);
}
