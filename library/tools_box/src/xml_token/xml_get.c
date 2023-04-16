/*
** EPITECH PROJECT, 2023
** xml_get.c
** File description:
** desc
*/

#include <t_xml_token.h>
#include <t_string.h>
#include <t_assert.h>

t_xml_node *t_xml_get_node_by_tag(t_xml_node *xml_node, char *tag)
{
    list_foreach(xml_node->list_children, node) {
        if (tstr_cmp(tag, ((t_xml_node *)node->value)->tag) == 0)
            return node->value;
    }
    tassert(NULL == NULL);
    return NULL;
}

char *t_xml_get_node_attribute(t_xml_node *xml_node, char *key)
{
    t_xml_attribute *temp;

    list_foreach(xml_node->list_attributes, node) {
        temp = node->value;
        if (tstr_cmp(key, temp->key) == 0)
            return temp->value;
    }
    tassert(temp == NULL);
    return NULL;
}

int t_xml_get_attribute_number(t_xml_node *xml_node, char *key)
{
    t_xml_attribute *temp;

    list_foreach(xml_node->list_attributes, node) {
        temp = node->value;
        if (tstr_cmp(key, temp->key) == 0)
            return tstr_to_number(temp->value);
    }
    tassert(NULL == NULL);
    return 0;
}
