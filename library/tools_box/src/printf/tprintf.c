/*
** EPITECH PROJECT, 2022
** miniprintf.c
** File description:
** desc
*/

#include <stdarg.h>
#include <unistd.h>
#include <t_printf.h>

struct tprintf_flags{
    char flag;
    void (*func)(va_list parametersInfos);
};

static const struct tprintf_flags flags[] = {
        { 'd', int_flag},
        { 'i', int_flag},
        { 's', string_flag},
        { 'c', char_flag},
        { 'v', char_flag},
        { '%', modulo_flag},
        {0, NULL}
};

void find_flag(char flag, va_list args)
{
    const struct tprintf_flags *flagsP = flags;
    for (; flagsP->flag != 0; flagsP++) {
        if (flagsP->flag == flag) {
            flagsP->func(args);
        }
    }
}

int tprintf(char *format, ...)
{
    va_list args;
    va_start(args, format);

    for (; *format != '\0'; format++) {
        if (*format == '%') {
            find_flag(*(format + 1), args);
            format++;
        } else {
            write(1, &(*format), 1);
        }
    }
    va_end(args);
    return 0;
}
