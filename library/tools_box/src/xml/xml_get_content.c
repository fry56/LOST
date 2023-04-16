/*
** EPITECH PROJECT, 2023
** xml_get_content.c
** File description:
** desc
*/

#include <t_string.h>

char *txml_get_content(char *buf)
{
    int start_index = tstr_index_of(buf, ">");
    int end_index;

    if (start_index == -1)
        return NULL;
    if ((end_index = tstr_index_of(buf, "</")) == -1)
        return NULL;
    return tstr_ncpy(NULL, buf + start_index + 1, end_index - start_index - 2);
}
