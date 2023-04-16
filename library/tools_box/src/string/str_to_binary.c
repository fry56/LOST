/*
** EPITECH PROJECT, 2023
** str_to_binary.c
** File description:
** desc
*/

#include <stdlib.h>
#include <t_ctype.h>
#include <t_string.h>
#include <t_math.h>
#include <t_mem.h>

char *tstr_to_binary(char *str)
{
    int str_length = tstr_len(str);
    char *binary = tcalloc(1, str_length * (sizeof(char) * 8) + 1);
    int index = 0;

    for (; *str; str++) {
        for (int i = 7; i >= 0; --i) {
            binary[index++] = (*str & 1 << i) ? '1' : '0';
        }
    }
    binary[index] = '\0';
    return binary;
}

char *tbinary_to_str(char *binary)
{
    int binary_len = tstr_len(binary);
    char *new_str;
    int index = 0;
    int ascii = 0;
    if ((binary_len % 8) != 0)
        return NULL;
    if ((new_str = tcalloc(1, sizeof(char) * ((binary_len / 8) + 1))) == NULL)
        return NULL;
    for (int i = 7; *binary; binary++, i--) {
        if (*binary == '1')
            ascii += tint_power(2, i);
        if (i == 0) {
            new_str[index++] = (char)ascii;
            i = 8;
            ascii = 0;
        }
    }
    new_str[index] = '\0';
    return new_str;
}
