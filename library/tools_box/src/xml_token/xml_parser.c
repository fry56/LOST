/*
** EPITECH PROJECT, 2023
** xml_parser.c
** File description:
** desc
*/

#include <t_xml_token.h>
#include <t_string.h>
#include <t_printf.h>

bool is_orphan_tag(char *buf, size_t index)
{
    if (tstr_ncmp(buf + index - 3, "/>", 1) == 0)
        return true;
    return false;
}

bool t_xml_token_parser(t_xml *doc, char *buf)
{
    size_t index = 0;
    buf = tstr_match(buf, "<.*>");
    t_xml_node *current = NULL;
    int valide_end;

    while (buf[index] != '\0') {
        if (buf[index] != '<') {
            index++;
            continue;
        }
        valide_end = t_xml_token_is_valide_end_tag(buf, current, &index);
        if (valide_end == 1) {
            current = current->parent;
            continue;
        }
        if (valide_end == 0)
            return false;
        t_xml_token_add_datas(doc, &current, &index, buf);
    }
    return true;
}
