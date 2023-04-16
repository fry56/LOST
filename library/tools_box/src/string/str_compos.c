/*
** EPITECH PROJECT, 2023
** str_compos.c
** File description:
** desc
*/

#include <stdarg.h>
#include <unistd.h>
#include <t_mem.h>
#include <t_string.h>

char *compos_int(va_list args);
char *compos_char(va_list args);
char *compos_string(va_list args);
char *compos_modulo(va_list args);

struct tstr_compos_flags{
    char flag;
    char *(*func)(va_list parametersInfos);
};

static const struct tstr_compos_flags flags[] = {
        { 'd', compos_int},
        { 's', compos_string},
        { '%', compos_modulo},
        {0, NULL}
};

static void insert_in_buf(char *buf, char new_char, int index)
{
    if (index != 0 && (index % 2048) == 0)
        buf = trealloc(buf, index, (index + 2048));
    buf[index] = new_char;
}

static void *find_flag(char flag)
{
    const struct tstr_compos_flags *flagsP = flags;
    for (; flagsP->flag != 0; flagsP++) {
        if (flagsP->flag == flag) {
            return flagsP->func;
        }
    }
    return NULL;
}

static void insert_flag_datas(char *buf, va_list args
    , char new_char, int *index)
{
    char *(*func)(va_list parametersInfos);
    char *new_str;

    func = find_flag(new_char);
    new_str = func(args);
    for (int i = 0; i < tstr_len(new_str); ++i, *index += 1)
        insert_in_buf(buf, new_str[i], *index);
    *index -= 1;
}

char *tstr_compos(char *format, ...)
{
    char *buf = tcalloc(1, 2048);
    va_list args;
    int index = 0;

    if (buf == NULL)
        return NULL;
    va_start(args, format);
    for (; *format != '\0'; format++, index++) {
        if (*format == '%') {
            insert_flag_datas(buf, args, *(format + 1), &index);
            format++;
            continue;
        }
        insert_in_buf(buf, *format, index);
    }
    insert_in_buf(buf, '\0', index++);
    va_end(args);
    return trealloc(buf, index, index);
}
