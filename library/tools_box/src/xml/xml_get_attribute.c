/*
** EPITECH PROJECT, 2023
** xml_get_attribute.c
** File description:
** desc
*/

#include <t_string.h>
#include <stdlib.h>

char *txml_get_attribute(char *buf, char *attribute)
{
    char *format = tstr_compos("%s=\".*\"", attribute);
    char *match;
    int attribute_start, attribute_end;

    if (format == NULL)
        return NULL;
    if ((match = tstr_match(buf, format)) == NULL) {
        free(format);
        return NULL;
    }
    free(format);
    attribute_start = tstr_index_of(match, "\"");
    attribute_end = tstr_index_of(match + attribute_start + 1, "\"");
    return tstr_ncpy(NULL, match + attribute_start + 1, attribute_end - 1);
}
