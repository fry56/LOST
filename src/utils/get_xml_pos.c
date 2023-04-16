/*
** EPITECH PROJECT, 2023
** get_xml_pos.c
** File description:
** desc
*/

#include <t_xml_token.h>
#include <Class/t_sprite.h>
#include <t_string.h>

sfVector2f get_xml_pos(t_xml_node *parent, char *node_name)
{
    t_xml_node *temp = t_xml_get_node_by_tag(parent, node_name);
    int x = tstr_to_number(t_xml_get_node_by_tag(temp, "x")->inner_text);
    int y = tstr_to_number(t_xml_get_node_by_tag(temp, "y")->inner_text);

    return (sfVector2f){(float)x, (float)y};
}
