/*
** EPITECH PROJECT, 2022
** char.c
** File description:
** desc
*/

#include <unistd.h>
#include <stdarg.h>

void char_flag(va_list args)
{
    char arg_char = va_arg(args, int);
    write(1, &arg_char, 1);
}
