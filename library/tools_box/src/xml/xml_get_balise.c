/*
** EPITECH PROJECT, 2023
** xml_get_balise.c
** File description:
** desc
*/

#include <t_string.h>
#include <stdlib.h>

char *txml_get_balise(char *buf, char *balise)
{
    char *format = tstr_compos("<%s.*>", balise);
    char *match;

    if (format == NULL)
        return NULL;
    if ((match = tstr_match(buf, format)) == NULL) {
        free(format);
        return NULL;
    }
    return match + tstr_len(balise) + 1;
}
